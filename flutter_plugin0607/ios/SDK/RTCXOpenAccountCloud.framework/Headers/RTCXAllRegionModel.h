//
//  RTCXAllRegionModel.h
//  RTCXOpenAccountCloud
//
//  Created by Apple on 2025/2/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXAllRegionModel : NSObject

@end

@interface RTCXCloudStorageAllRegionReq : NSObject
// 获取对应机房服务域名列表，例如：gateway 必选
@property (nonatomic, strong, nonnull) NSArray *serviceNameList;

@end

@interface RTCXSingleRegionRsp : NSObject
// 机房名
@property (nonatomic, copy) NSString *region;
// 服务域名列表， key为服务名称，例如gateway
@property (nonatomic, strong) NSDictionary *serviceAddresses;

@end

@interface RTCXAllRegionListRsp : NSObject
// 机房列表
@property (nonatomic, strong) NSArray<RTCXSingleRegionRsp*> *regionList;

@end

NS_ASSUME_NONNULL_END
