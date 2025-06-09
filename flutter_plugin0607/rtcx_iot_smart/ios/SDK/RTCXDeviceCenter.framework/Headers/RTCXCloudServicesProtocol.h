//
//  RTCXCloudServicesProtocol.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2024/12/13.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXCloudServicesModel.h>
NS_ASSUME_NONNULL_BEGIN

typedef void (^RTCXCloudServicesOnSuccess)(id _Nullable data, id _Nullable rawData);;
typedef void (^RTCXCloudServicesOnError)(NSError * _Nullable error);

@protocol RTCXCloudServicesProtocol <NSObject>
/**
 *  查询当前云存储套餐详情
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryDeviceCurrentCloudServicesWithReq:(nonnull RTCXCloudServicesReq *)req onSuccess:(nullable RTCXCloudServicesOnSuccess)onSuccess onError:(nullable RTCXCloudServicesOnError)onError;
/**
 *  查询历史云存储套餐详情
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryDeviceHistoryCloudServicesWithReq:(nonnull RTCXCloudServicesReq *)req onSuccess:(nullable RTCXCloudServicesOnSuccess)onSuccess onError:(nullable RTCXCloudServicesOnError)onError;
@end

NS_ASSUME_NONNULL_END
