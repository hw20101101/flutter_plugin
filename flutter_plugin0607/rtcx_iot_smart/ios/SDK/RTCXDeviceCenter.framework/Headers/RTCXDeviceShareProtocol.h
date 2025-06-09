//
//  RTCXDeviceShareProtocol.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2024/10/22.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXDeviceMgrReq.h>
NS_ASSUME_NONNULL_BEGIN

@protocol RTCXDeviceShareProtocol <NSObject>
/**
 *  生成分享用的二维码(30min有效)
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)generateShareQrCodeWithReq:(nonnull RTCXGeneralShareQrcodeReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  通过扫描二维码绑定设备(分享设备)
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deviceBindByScanShareQrCodeWithReq:(nonnull RTCXScanShareQrCodeBindReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  设备分享给指定的用户
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deviceShareWithReq:(nonnull RTCXDeviceShareReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  获取分享通知列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getShareDeviceNoticeListWithReq:(nonnull RTCXDeviceShareNoticeListReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  被分享者同意或拒绝分享
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)confirmShareWithReq:(nonnull RTCXConfirmShareReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  发起者取消分享
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)cancelShareWithReq:(nonnull RTCXCancelShareReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  查询设备分享记录
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getDeviceShareRecordWithReq:(nonnull RTCXDeviceShareRecordReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  分享权限修改
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)setPermissionListWithReq:(nonnull RTCXSetPermissionListReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  查询用户下设备当前被分享用户(初始化和接受状态)
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getDeviceShareUserListWithReq:(nonnull RTCXDeviceShareUserListReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
/**
 *  查询用户下设备的分享数量(初始化和接受状态)
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getDeviceShareCountListWithReq:(nonnull RTCXDeviceShareCountListReq *)req onSuccess:(nullable RTCXDeviceMgrOnSuccess)onSuccess onError:(nullable RTCXDeviceMgrOnError)onError;
@end

NS_ASSUME_NONNULL_END
