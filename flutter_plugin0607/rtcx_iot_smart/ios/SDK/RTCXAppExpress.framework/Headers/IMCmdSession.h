//
//  IMCmdSession.h
//  LKAppExpress
//
//  Created by Apple on 2024/8/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^LKSessionCallback)(NSDictionary *response);

@protocol IMCmdSession <NSObject>
/**
 *  获取IM版本号
 */
- (NSString *)getIMVersion;
/**
 *  设备服务消息
 *
 *  @param deviceName 设备序列号SN  必选
 *  @param lensId  镜头Id
 *  @param compressAck  是否需要返回压缩的数据，1：需要压缩，0：不需要压缩，默认0
 *  @param params 参数
 *  @param method Topic
 *  @param callbackHandle 回调
 */
- (void )tslServiceSignallingWithDeviceName:(nonnull NSString *)deviceName productKey:(NSString *)productKey lensId:(nullable NSNumber *)lensId compressAck:(nullable NSNumber *)compressAck params:(NSDictionary *)params  method:(NSString *)method callbackHandle:(LKSessionCallback)callbackHandle;
/**
 *  设备端或者App端主动发起推拉流，获取到流媒体连接信息
 *
 *  @param productKey 设备型号  必选
 *  @param deviceName 设备序列号SN  必选
 *  @param lensId  镜头Id
 *  @param params 参数
 *  @param callbackHandle 回调
 */
- (void)querySdpWithProductKey:(nullable NSString *)productKey deviceName:(nullable NSString *)deviceName lensId:(nullable NSNumber *)lensId params:(NSDictionary *)params callbackHandle:(LKSessionCallback)callbackHandle;
/**
 *  客户端向服务订阅topic
 *
 *  @param deviceName 设备序列号SN  必选
 *  @param lensId  镜头Id
 *  @param iotId 平台为设备颁发的ID，设备的唯一标识符
 *  @param topic 请求Topic
 *  @param callbackHandle 回调
 */
- (void)subscribeTopicWithDeviceName:(NSString *)deviceName productKey:(NSString *)productKey lensId:(nullable NSNumber *)lensId iotId:(NSString *)iotId topic:(nullable NSString *)topic callbackHandle:(LKSessionCallback)callbackHandle;
/**
 *  客户端向服务反订阅topic
 *
 *  @param deviceName 设备序列号SN  必选
 *  @param lensId  镜头Id
 *  @param iotId 平台为设备颁发的ID，设备的唯一标识符
 *  @param topic 请求Topic
 *  @param callbackHandle 回调
 */
- (void)unsubscribeTopicWithDeviceName:(NSString *)deviceName productKey:(NSString *)productKey lensId:(nullable NSNumber *)lensId iotId:(NSString *)iotId topic:(nullable NSString *)topic callbackHandle:(LKSessionCallback)callbackHandle;
/**
 *  RPC请求接口，封装了业务的上行 request 以及下行 response
 *
 *  @param deviceName 设备序列号SN  必选
 *  @param lensId  镜头Id
 *  @param cmdId cmdId
 *  @param params 参数
 *  @param topic 请求Topic
 *  @param method method
 *  @param callbackHandle 回调
 */
- (void)invokeWithDeviceName:(NSString *)deviceName productKey:(NSString *)productKey lensId:(nullable NSNumber *)lensId cmdId:(int )cmdId params:(NSDictionary*)params topic:(nullable NSString *)topic method:(NSString *)method callbackHandle:(LKSessionCallback)callbackHandle;
/**
 *  获取播放策略
 *
 *  @param deviceName 设备序列号SN  必选
 *  @param productKey 设备型号
 *  @param lensId  镜头Id
 *  @param params 参数
 *  @param callbackHandle 回调
 */
- (void )getPlayStrategyWithDeviceName:(nonnull NSString *)deviceName productKey:(NSString *)productKey lensId:(nullable NSNumber *)lensId params:(nullable NSDictionary *)params callbackHandle:(LKSessionCallback)callbackHandle;
@end

NS_ASSUME_NONNULL_END
