//
//  RTCXImageUrlMgrModel.h
//  RTCXUtil
//
//  Created by Apple on 2025/3/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXImageUrlMgrModel : NSObject

@end

@interface RTCXImageUploadUrlReq : RTCXImageUrlMgrModel
// 上传数据用途类型，1：预置位图片, 2：个人头像图片 必选
@property (nonatomic, strong) NSNumber *useType;
// 图片类型，类似jpg之类 可选
@property (nonatomic, copy) NSString *picType;
// 过期时间，单位小时， 默认1h 可选
@property (nonatomic, strong) NSNumber *expireHours;
// 平台为设备颁发的ID，设备的唯一标识符，useType=1时必填，可选
@property (nonatomic, copy) NSString *iotId;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;
@end

@interface RTCXImageDownloadUrlReq : RTCXImageUrlMgrModel
// 文件名 必选
@property (nonatomic, copy) NSString *fileName;
// 过期时间，单位小时， 默认1h 可选
@property (nonatomic, strong) NSNumber *expireHours;
// 平台为设备颁发的ID，设备的唯一标识符，获取预置位图片必填，可选
@property (nonatomic, copy) NSString *iotId;
@end

@interface RTCXImageUploadUrlRsp : NSObject
// 上传链接
@property (nonatomic, copy) NSString *url;
// 文件名
@property (nonatomic, copy) NSString *fileName;
@end

@interface RTCXImageDownloadUrlRsp : NSObject
// 下载链接
@property (nonatomic, copy) NSString *url;
@end

@interface RTCXUploadFileDataReq : RTCXImageUrlMgrModel
// 上传文件路径 必选
@property (nonatomic, copy) NSString *fileUrl;
// 上传文件数据 必选
@property (nonatomic, strong) NSData *fileData;
// 文件名 必选
@property (nonatomic, copy) NSString *fileName;

@end
NS_ASSUME_NONNULL_END
