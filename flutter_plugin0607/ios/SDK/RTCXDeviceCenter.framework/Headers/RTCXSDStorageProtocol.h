//
//  RTCXSDStorageProtocol.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2024/9/24.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXSDStorageReq.h>
NS_ASSUME_NONNULL_BEGIN
typedef void (^RTCXSDStorageOnSuccess)(id _Nullable data, id _Nullable rawData);
typedef void (^RTCXSDStorageOnError)(NSError * _Nullable error);
@protocol RTCXSDStorageProtocol <NSObject>
/**
 *  查询SD卡录像列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)querySDRecordListWithReq:(nonnull RTCXSDStorageRecordReq *)req onSuccess:(nullable RTCXSDStorageOnSuccess)onSuccess onError:(nullable RTCXSDStorageOnError)onError;
/**
 *  查询SD卡事件列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)querySDRecordEventListWithReq:(nonnull RTCXSDStorageRecordEventReq *)req onSuccess:(nullable RTCXSDStorageOnSuccess)onSuccess onError:(nullable RTCXSDStorageOnError)onError;
/**
 *  查询录像文件列表
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)querySDRecordFileListWithReq:(nonnull RTCXSDStorageRecordFileReq *)req onSuccess:(nullable RTCXSDStorageOnSuccess)onSuccess onError:(nullable RTCXSDStorageOnError)onError;
/**
 *  查询SD卡月录像
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)querySDMonthRecordWithReq:(nonnull RTCXSDStorageMonthRecordReq *)req onSuccess:(nullable RTCXSDStorageOnSuccess)onSuccess onError:(nullable RTCXSDStorageOnError)onError;
@end

NS_ASSUME_NONNULL_END
