//
//  RTCXImageUrlMgrProtocol.h
//  RTCXUtil
//
//  Created by Apple on 2025/3/18.
//

#import <Foundation/Foundation.h>
#import <RTCXOpenAccountCloud/RTCXImageUrlMgrModel.h>
NS_ASSUME_NONNULL_BEGIN

typedef void (^RTCXImageUrlMgrOnSuccess)(id _Nullable data, id _Nullable rawData);;
typedef void (^RTCXImageUrlMgrOnError)(NSError * _Nullable error);


@protocol RTCXImageUrlMgrProtocol <NSObject>
/**
 *  获取上传url
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getUploadUrlWithReq:(nonnull RTCXImageUploadUrlReq *)req onSuccess:(nullable RTCXImageUrlMgrOnSuccess)onSuccess onError:(nullable RTCXImageUrlMgrOnError)onError;
/**
 *  获取下载url
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getDownloadUrlWithReq:(nonnull RTCXImageDownloadUrlReq *)req onSuccess:(nullable RTCXImageUrlMgrOnSuccess)onSuccess onError:(nullable RTCXImageUrlMgrOnError)onError;
/**
 *  上传文件数据
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)uploadFileDataToOSSWithURL:(nonnull RTCXUploadFileDataReq *)req onSuccess:(nullable RTCXImageUrlMgrOnSuccess)onSuccess onError:(nullable RTCXImageUrlMgrOnError)onError;
@end

NS_ASSUME_NONNULL_END
