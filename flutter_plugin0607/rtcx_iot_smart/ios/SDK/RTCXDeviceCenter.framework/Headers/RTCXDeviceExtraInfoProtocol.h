//
//  RTCXDeviceExtraInfoProtocol.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2025/2/25.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXDeviceExtraInfo.h>
NS_ASSUME_NONNULL_BEGIN
typedef void (^RTCXDeviceExtraInfoMgrOnSuccess)(id _Nullable data, id _Nullable rawData);
typedef void (^RTCXDeviceExtraInfoMgrOnError)(NSError * _Nullable error);
@protocol RTCXDeviceExtraInfoProtocol <NSObject>
/**
 *  请求设备额外信息（App未调用设备列表接口时需要调用此接口，获取设备播放需要的必要信息）
 *
 *  @param req  请求参数对象, 设备iotId数组 eg:【xxx】
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryExtraInfoWithIotIds:(nonnull RTCXDeviceExtraInfoReq *)req onSuccess:(nullable RTCXDeviceExtraInfoMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceExtraInfoMgrOnError)onError;
/**
 *  通过iotId获取设备额外信息Model（需要在子线程调用）
 *
 *  @param iotId        设备iotId
 *  @return RTCXDeviceExtraInfo
 */
- (RTCXDeviceExtraInfo *)getDeviceExtraInfoWithIotId:(NSString *)iotId;
@end

NS_ASSUME_NONNULL_END
