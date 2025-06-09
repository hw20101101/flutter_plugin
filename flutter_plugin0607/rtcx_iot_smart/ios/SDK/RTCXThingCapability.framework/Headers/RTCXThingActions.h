//
//  RTCXThingActions.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 对物进行操作时的响应结果类
 */
@interface RTCXThingActionsResponse : NSObject
@property(nonatomic, assign) BOOL success; ///< 响应结果，成功或者失败
@property (nonatomic, strong, nullable) id dataObject;          ///< 服务端返回的 json 的 data 字段,一般为 NSData 结构，具体格式请参见云端 '物的核心模型服务' 文档
@property (nonatomic, strong, nullable) NSError *responseError; ///< 错误，失败时才有，可以参见 NSError+RTCXThing.h
@end

typedef void (^RTCXThingActionsResponseHandler)(RTCXThingActionsResponse * _Nullable response); ///<对物进行操作时的响应结果回调函数定义

@protocol RTCXThingActions <NSObject>
/**
 获取物的所有属性的当前值

 @param handler 结果回调函数，请参考 `RTCXThingActionsResponseHandler`
 */
- (void)getPropertiesFull:(RTCXThingActionsResponseHandler)handler;

/**
 获取物的所有属性的当前值
 @param extraData 附加控制属性  key:@"IotPerformanceId" 性能测试
 key:@"Channel", value: ChannelPolicyCloud ChannelPolicyLocal   ChannelPolicyLocalPrefer
 @param handler 结果回调函数，请参考 `RTCXThingActionsResponseHandler`
 */
- (void)getPropertiesV1:(NSDictionary* _Nullable)extraData
        responseHandler:(RTCXThingActionsResponseHandler _Nullable)handler;

/**
 获取设备实体属性(配置策略等)
 @param attributeIdList id描述实体属性内容， 例如 1000:直播策略  [@(1000)]
 */
- (void)getEntityWithAttributeIdList:(NSArray *)attributeIdList responseHandler:(RTCXThingActionsResponseHandler _Nullable)handler;

/**
 设置物的属性值，可以同时设置一个或者多个属性

 @param items 属性 key-value 对， 如{"power":"on", temperature:30}
 @param handler 结果回调函数，请参考 `RTCXThingActionsResponseHandler`
 */
- (void)setProperties:(NSDictionary*_Nonnull)items responseHandler:(RTCXThingActionsResponseHandler _Nullable )handler DEPRECATED_ATTRIBUTE;

/**
 设置物的属性值，可以同时设置一个或者多个属性
 
 @param params 属性 key-value 对， 格式如{"items":{"power":"on", temperature:30}}
 @param extraData 附加控制属性  key:@"IotPerformanceId" 性能测试
                            key:@"Channel", value: ChannelPolicyCloud ChannelPolicyLocal   ChannelPolicyLocalPrefer
                            key:@"QosLevel", value: Qos_CON Qos_NON
                            key:@"NeedRsp", value:TRUE FALSE
                            key:@"Flag", 用于commonservice flag参数
                            key:@"LensId",value:@(1)镜头ID，仅多目设备需要单独设置指定镜头属性时填写， 如 {@"LensId":@(0)}
 @param handler 结果回调函数，请参考 `RTCXThingActionsResponseHandler
 */
- (void)setPropertiesV1:(NSDictionary * _Nonnull)params
              extraData:(NSDictionary* _Nullable)extraData
        responseHandler:(RTCXThingActionsResponseHandler _Nullable)handler;
/**
 调用物提供的服务

 @param serviceIdentifier 服务的唯一标识符
 @param params 调用服务的入参，请参考物的模型 tsl，形如 {"arg1":"val1", "arg2":"val2"}
 @param handler 结果回调函数
 */
- (void)invokeService:(NSString * _Nonnull)serviceIdentifier
               params:(NSDictionary* _Nullable)params
      responseHandler:(RTCXThingActionsResponseHandler)handler;

/**
 调用物提供的服务
 
 @param serviceIdentifier 服务的唯一标识符
 @param params 调用服务的入参，请参考物的模型 tsl，形如 {"arg1":"val1", "arg2":"val2"}
 @param extraData 附加控制属性
     key:@"IotPerformanceId" 性能测试
     key:@"callType" "async":异步， "sync"同步调用
     key:@"Channel", value: ChannelPolicyCloud ChannelPolicyLocal   ChannelPolicyLocalPrefer
     key:@"QosLevel", value: Qos_CON Qos_NON
     key:@"NeedRsp", value: value:TRUE FALSE

 @param handler 结果回调函数
 */
- (void)invokeServiceV1:(NSString * _Nonnull)serviceIdentifier
                 params:(NSDictionary* _Nullable)params
              extraData:(NSDictionary* _Nullable)extraData
        responseHandler:(RTCXThingActionsResponseHandler _Nullable)handler;

/**
 获取云端缓存的物定义的所有事件内容，云端逻辑是：当物某个事件触发时，云端记录此事件的快照，
 当 app 端来获取时，则返回这些事件在云端的记录

 @param handler 结果回调函数
 */
- (void)getEvents:(RTCXThingActionsResponseHandler)handler;

@optional
/**
 获取物的生命周期
 说明：status表示设备生命周期，目前有以下几个状态，0:未激活；1：上线；3：离线；8：禁用；
 @param handler 结果回调函数
 */
- (void)getStatus:(RTCXThingActionsResponseHandler)handler;
/**
 获取物的信息
 @param handler 结果回调函数
 */
- (void)getDetailInfo:(RTCXThingActionsResponseHandler)handler;
/**
 获取物的模型
 @param handler 结果回调函数
 */
- (void)getTsl:(RTCXThingActionsResponseHandler)handler;
@end

NS_ASSUME_NONNULL_END
