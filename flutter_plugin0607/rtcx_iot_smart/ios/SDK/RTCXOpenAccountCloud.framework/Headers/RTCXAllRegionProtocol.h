//
//  RTCXAllRegionProtocol.h
//  RTCXOpenAccountCloud
//
//  Created by Apple on 2025/2/25.
//

#import <Foundation/Foundation.h>
#import <RTCXOpenAccountCloud/RTCXAllRegionModel.h>
NS_ASSUME_NONNULL_BEGIN

typedef void (^RTCXRegionOnSuccess)(id _Nullable data, id _Nullable rawData);
typedef void (^RTCXRegionOnError)(NSError * _Nullable error);

@protocol RTCXAllRegionProtocol <NSObject>
/**
 *  获取所有机房信息
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)queryAllRegionWithReq:(nonnull RTCXCloudStorageAllRegionReq *)req onSuccess:(nullable RTCXRegionOnSuccess)onSuccess onError:(nullable RTCXRegionOnError)onError;
/**
 *  获取所有regionList
 */
- (RTCXAllRegionListRsp *)getAllRegions;
@end

NS_ASSUME_NONNULL_END
