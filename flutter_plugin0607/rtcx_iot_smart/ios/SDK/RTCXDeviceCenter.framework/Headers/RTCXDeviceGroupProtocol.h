//
//  RTCXDeviceGroupProtocol.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2024/10/29.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXDeviceMgrReq.h>
NS_ASSUME_NONNULL_BEGIN

@protocol RTCXDeviceGroupProtocol <NSObject>
/**
 *  创建设备分组
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)groupCreatWithReq:(nonnull RTCXGroupCreatReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  删除设备分组
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)groupDeleteWithReq:(nonnull RTCXGroupDeleteReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  更新设备分组信息
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)groupUpdateWithReq:(nonnull RTCXGroupUpdateReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  设备分组列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)groupListWithReq:(nonnull RTCXGroupListReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  添加设备到分组
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)groupAddDeviceWithReq:(nonnull RTCXGroupAddDeviceReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  分组中删除设备
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)groupDeleteDeviceWithReq:(nonnull RTCXGroupDeleteDeviceReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
@end

NS_ASSUME_NONNULL_END
