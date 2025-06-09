//
//  RTCXCloudStorageProtocol.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/9/3.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXCloudStorageReq.h>

NS_ASSUME_NONNULL_BEGIN


typedef void (^RTCXCloudStorageOnSuccess)(id _Nullable data, id _Nullable rawData);
typedef void (^RTCXCloudStorageOnError)(NSError * _Nullable error);
@protocol RTCXCloudStorageProtocol <NSObject>
/**
 *  查询云存录像列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryRecordListWithReq:(nonnull RTCXCloudStorageRecordReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询云存事件列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryEventListWithReq:(nonnull RTCXCloudStorageEventReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询云存录像点播地址
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryVodUrlWithReq:(nonnull RTCXCloudStorageVodUrlReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询云存事件点播地址
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryVodEventUrlWithReq:(nonnull RTCXCloudStorageVodEventUrlReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询月录像
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryMonthRecordWithReq:(nonnull RTCXCloudStorageMonthRecordReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询月事件
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryMonthEventWithReq:(nonnull RTCXCloudStorageMonthEventReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  删除云存录像
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deleteRecordWithReq:(nonnull RTCXCloudStorageDeleteRecordReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  删除云存事件
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deleteEventWithReq:(nonnull RTCXCloudStorageDeleteEventReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询事件描述（事件最新记录时间，事件小红点）
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryEventDescWithReq:(nonnull RTCXCloudStorageEventDescReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询设备当前机房信息
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryCurrentRegionWithReq:(nonnull RTCXCloudStorageCurrentRegionReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询设备历史机房信息
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryHistoryRegionWithReq:(nonnull RTCXCloudStorageHistoryRegionReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询消息中心事件列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryMessageCenterEventListWithReq:(nonnull RTCXCloudStorageMessageEventReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询月消息（消息中心按天统计）
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryMonthMessageWithReq:(nonnull RTCXCloudStorageMonthMessageReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  查询消息中心事件描述（消息中心最新记录时间，消息中心小红点）
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryMessageDescWithReq:(nonnull RTCXCloudStorageMessageDescReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  批量删除消息中心事件
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)deleteMessageWithReq:(nonnull RTCXCloudStorageDeleteMessageReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
/**
 *  根据图片ID列表获取图片地址
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryPictureUrlByIdWithReq:(nonnull RTCXCloudStoragePicUrlReq *)req onSuccess:(nullable RTCXCloudStorageOnSuccess)onSuccess onError:(nullable RTCXCloudStorageOnError)onError;
@end

NS_ASSUME_NONNULL_END
