//
//  LinkAppExpress.h
//  LKAppExpress
//
//  Created by Apple on 2024/9/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef LKSignallingService
#define LKSignallingService(__protocol__) \
((id<__protocol__>)([[LinkAppExpress sharedInstance] getService:@protocol(__protocol__)]))
#endif

/**
 长连接通道连接状态枚举
 */
typedef NS_ENUM (NSInteger, LKAppExpConnectState){
    LKAppExpConnectStateConnected = 1,///< 已连接
    LKAppExpConnectStateDisconnected = 2,///< 已断连
    LKAppExpConnectStateConnecting = 3,///< 连接中
};

/**
 长连接通道连接状态侦听者
 */
@protocol LKAppExpConnectListener<NSObject>
/** 通道连接状况改变
 @param state 参见枚举 `LKExpConnectState`
 @param msgChannel 消息通道
 */
-(void)onConnectState:(LKAppExpConnectState) state messageChannel:(NSInteger)msgChannel;
@end

/**

 长连接通道连接配置项目

 */
@interface LKAEConnectConfig : NSObject
@property(nonatomic, copy) NSString * appKey;///<  应用 appkey，在 IoT 平台创建应用时生成
@property(nonatomic, copy) NSString * appSecret;

@property(nonatomic, copy, nullable) NSString * server;///< 长连通道连接的服务器地址，不要带 "协议://"，如果置为空，底层通道会使用默认的地址，
@property(nonatomic, assign) int port; ///< 通道连接的服务器端口，不传会使用默认端口
@property(nonatomic, assign) BOOL autoSelectChannelHost;///>  自动通道选择功能：提供一个公开的服务器地址可以供客户端在建联的时候去这个地址查询当前最优的链接通路地址。当下边的serverUrlForAutoSelectChannel为nil时，如果这个值设置为YES，则会选择默认的供查询地址。
@property(nonatomic, copy) NSString *serverUrlForAutoSelectChannel; ///> 自动通道选择功能：提供一个公开的服务器地址可以供客户端在建联的时候去这个地址查询当前最优的链接通路地址。这个供查询的服务器地址可以由业务方传入，如果业务方选择不传，SDK内部会选择一个默认的供查询地址。
@property(nonatomic, copy, nullable) NSString * cerPath; ///< TLS 文件绝对路径，如果为空，会使用默认的证书

@end

@protocol LKAppExpDownListener<NSObject>
/**
 下推数据方法
 
 @param topic 下推 Topic 的业务部分，由具体业务确定，下行的完整 Topic 形如：

 ${deviceName}/${iotId}/properties

 @param data 消息内容。可能是 NSString 或者 NSDictionary
 */
-(void)onDownstream:(NSString *)topic data: (id _Nullable) data;
@optional
/**
 数据使用 `onDownstream:data:` 上抛时，可以先过滤一遍，返回 NO，则不上抛；返回 YES，则会使用 `onDownstream:data:` 上抛
 
 @param topic 下推 Topic 的业务部分，由具体业务确定，下行的完整 Topic 形如：

 ${deviceName}/${iotId}/app/down/properties/post

 @return 返回 NO，则不上抛；返回 YES，则会使用 `onDownstream:data:` 上抛
 */
-(BOOL)shouldHandle:(NSString *)topic iotId:(NSString *)iotId;
@end

/**
 RPC请求回执内容
 */
@interface LKAppExpResponse : NSObject
@property (nonatomic, assign) BOOL successed;                   ///< 是否成功
@property (nonatomic, strong, nullable) id dataObject;          ///< 服务端返回的 json 的 data 字段
@property (nonatomic, strong, nullable) NSError *responseError; ///< 错误详情
@end


//回调函数定义如下
typedef void(^LKAppExpResponseHandler)(LKAppExpResponse *response);

/**
 提供一条双工的长连接通道
 */
@interface LinkAppExpress : NSObject
/**
 * 单例
 */
+(instancetype)sharedInstance;
/**
 获取RTCXDevice的service 实例
 @param protocol service的协议
 @return service实例
 */
- (id)getService:(Protocol *)protocol;
/**
 长连接通道启动接口，应用起来时调用一次
 @param config app 长连接通道配置项
 @param listener 通道连接状态侦听者
 */
-(void)startConnect:(LKAEConnectConfig *)config connectListener:(id<LKAppExpConnectListener>)listener;

/**
 中断当前长连接通道，一般情况下不需要使用此 API。
 @param completeHandler 结果回调，在结果回调后方可继续建立新的连接
 */
- (void)stopConnect:(void(^)(void))completeHandler;

/**
 获取长连接通道当前的连接状态

 @return 通道连接状态，参见 `LKAppExpConnectState`
 */
- (LKAppExpConnectState)getMobileConnectState;

/**
 增加通道连接状态变化 listener
 @param listener 通道连接状态侦听者
 */
-(void) addConnectListener:(id<LKAppExpConnectListener>)listener;


/**
 增加通道连接状态变化 listener
 @param listener 通道连接状态侦听者
 */
-(void) removeConnectListener:(id<LKAppExpConnectListener>)listener;


/**
 RPC请求接口，封装了业务的上行 request 以及下行 response。
 @param topic rpc请求的 topic，由具体业务确定，上行的完整 topic 形如：

 ${productKey}/${deviceName}/${iotId}/app/up/properties/set,

 @param opts 可选配置项，可空，预留
 @param params 业务参数。
 @param responseHandler 业务服务器响应回调接口，参见 `LKExpResponse`
 */
-(void)invokeWithTopic:(NSString *)topic opts:(NSDictionary* _Nullable)opts
            params:(NSDictionary*)params respHandler:(LKAppExpResponseHandler)responseHandler;


/**
 发布消息接口，不同于 `invokeWithMethod:opts:params:respHandler:` 。这个接口不会有业务回执。
 @param topic rpc 请求的 topic，由具体业务确定，上行的完整 topic 形如：

 ${productKey}/${deviceName}/${iotId}/app/up/properties/set

 @param params 业务参数。
 @param completeCallback 业务服务器响应回调接口，参见 `LKExpResponse`
 */
-(void)publish:(NSString *)topic params:(NSDictionary *)params complete:(void(^)(NSError* _Nullable))completeCallback;


/**
 设置通道的下推侦听者，如果不需要用的时候，记得调用 `removeDownStreamListener:` 。
 `LKAppExpress` 收到云端下推的处理逻辑如下所示:
 
 if ([downListener shouldHandle:topic] == YES) {
    [downListener onDownstream:topic data:data];
 } else {
    NSLog(@"message will ignored");
 }
 
 @param uiSafety 是否要在UI线程里回调，建议为 YES
 @param downListener 侦听下推消息，参见 `LKExpDownListener`
 */
- (void)addDownStreamListener:(BOOL)uiSafety listener:(id<LKAppExpDownListener>)downListener;

/**
 取消通道的某个下推侦听者
 @param downListener 侦听下推消息，参见 `LKExpDownListener`
 */
-(void)removeDownStreamListener:(id<LKAppExpDownListener>)downListener;



/**
 app 向云端订阅 topic 的接口。SDK 启动时会默认向云端订阅 app 相关的所有下行消息。即自动 subscribe topic:@"/#"。
 所以默认情况下无需再订阅。
 @param topic 订阅的消息的 topic，由具体业务确定.
 下行的完整 topic 形如：

 ${productKey}/${deviceName}/${iotId}/app/down/properties/post
 @param completionHandler 订阅流程完成的 callback，如果 error 为空表示订阅成功，否则订阅失败
 */
- (void)subscribe:(NSString *)topic complete:(void (^)(NSError  * _Nullable error))completionHandler;


/**
 app向云端取消订阅 topic 的接口。SDK 启动时会默认向云端订阅 app 相关的所有下行消息。即主动 [subscribe topic:@"/#"]。
 如果应用层不希望订阅所有下行，可以先[unsubscrbie topic:@"/#"]取消所有下行的订阅。再subscribe自己感兴趣的 topic.
 @param topic 取消订阅的消息的 topic，由具体业务确定.
 下行的完整 topic 形如：
 ${productKey}/${deviceName}/${iotId}/app/down/properties/post

 @param completionHandler 取消订阅流程完成的 callback，如果 error 为空表示订阅成功，否则订阅失败
 */
- (void)unsubscribe:(NSString *)topic complete:(void (^)(NSError  * _Nullable error))completionHandler;


/**
 获取当前长连通道的 clientId
 */

- (NSString *)getClientId;
@end

NS_ASSUME_NONNULL_END
