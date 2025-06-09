//
//  RTCXPushServiceProtocol.h
//  RTCXPush
//
//  Created by Apple on 2025/1/16.
//

#import <Foundation/Foundation.h>
#import <RTCXPush/RTCXPushServiceModel.h>
NS_ASSUME_NONNULL_BEGIN

typedef void (^RTCXPushServiceOnSuccess)(id _Nullable data, id _Nullable rawData);;
typedef void (^RTCXPushServiceOnError)(NSError * _Nullable error);

@protocol RTCXPushServiceProtocol <NSObject>
/**
 *  推送消息Schedule设置
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)setPnsScheduleWithReq:(nonnull RTCXPnsScheduleSetReq *)req onSuccess:(nullable RTCXPushServiceOnSuccess)onSuccess onError:(nullable RTCXPushServiceOnError)onError;
/**
 *  推送消息Schedule查询
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getPnsScheduleWithReq:(nonnull RTCXPnsScheduleGetReq *)req onSuccess:(nullable RTCXPushServiceOnSuccess)onSuccess onError:(nullable RTCXPushServiceOnError)onError;
@end

NS_ASSUME_NONNULL_END
