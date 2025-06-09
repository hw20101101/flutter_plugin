//
//  RTCXDeviceMgrProtocol.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/21.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXDeviceMgrReq.h>

typedef void (^RTCXDeviceMgrOnSuccess)(id _Nullable data, id _Nullable rawData);
typedef void (^RTCXDeviceMgrOnError)(NSError * _Nullable error);

@protocol RTCXDeviceMgrProtocol <NSObject>
/**
 *  获取设备列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getDeviceListWithReq:(nonnull RTCXQueryDeviceListReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  获取网关的子设备列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getSubDeviceListWithReq:(nonnull RTCXQuerySubDeviceListReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  获取设备绑定token
 *
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getDeviceBindTokenWithReq:(nonnull RTCXBindTokenReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  基于token绑定用户设备
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deviceBindWithReq:(nonnull RTCXDeviceBindReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  解绑用户的设备
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deviceUnbindWithReq:(nonnull RTCXDeviceUnbindReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  设置设备昵称
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)setDeviceNickNameWithReq:(nonnull RTCXDeviceNickdNameSetReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  测试设备快速绑定 (测试设备专用)
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deviceQuickBindWithReq:(nonnull RTCXDeviceQuickBindReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  APP扫设备二维码绑定设备
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deviceQrcodeQuickBindWithReq:(nonnull RTCXDeviceQrcodeQuickBindReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  检查设备绑定状态
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deviceBindStatusCheckWithReq:(nonnull RTCXDeviceBindStatusReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  获取设备当前可用的固件信息
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)otaCheckFirmwareUpdateWithReq:(nonnull RTCXFirmwareUpdateCheckReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  确定设备允许进行升级
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)otaFirmwareUpdateWithReq:(nonnull RTCXFirmwareUpdateReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  获取固件升级进度
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)otaFirmwareUpdateProgressWithReq:(nonnull RTCXFirmwareUpdateProgressReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  获取设备配置
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getDeviceConfigWithReq:(nonnull RTCXGetDeviceConfigReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  保存设备配置
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)setDeviceConfigWithReq:(nonnull RTCXSetDeviceConfigReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  保存预置位
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)savePtzPresetPositionWithReq:(nonnull RTCXSavePtzPresetPositionReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  获取预置位列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getPtzPresetPositionListWithReq:(nonnull RTCXGetPtzPresetPositionListReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  删除预置位
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deletePtzPresetPositionWithReq:(nonnull RTCXDeletePtzPresetPositionReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  更新预置位名称
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)updatePtzPresetPositionWithReq:(nonnull RTCXUpdatePtzPresetPositionReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  休眠设备唤醒
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)wakeupDeviceWithReq:(nonnull RTCXWakeupDeviceReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
@end

