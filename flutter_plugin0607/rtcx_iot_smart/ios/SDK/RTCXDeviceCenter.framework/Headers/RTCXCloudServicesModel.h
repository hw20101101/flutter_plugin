//
//  RTCXCloudServicesModel.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2024/12/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXCloudServicesModel : NSObject
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
@end

@interface RTCXCloudServicesReq : RTCXCloudServicesModel
// 查询开始时间。单位毫秒。可选
@property (nonatomic, strong, nonnull) NSNumber *startTime;
// 查询结束时间。单位毫秒。可选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
@end

@interface RTCXCloudServicesRsp : NSObject
// 状态，0：无套餐，1：有套餐
@property (nonatomic, assign) NSInteger status;
// 云存储套餐名称
@property (nonatomic, copy) NSString *commodityName;
// 云存录像类型。1（表示连续型）；2（表示事件型）。
@property (nonatomic, assign) NSInteger recordType;
// 存储周期，单位：天。
@property (nonatomic, assign) NSInteger lifecycle;
// 服务周期，单位：月。
@property (nonatomic, assign) NSInteger months;
// 事件开始时间
@property (nonatomic, assign) NSInteger startTime;
// 事件结束时间
@property (nonatomic, assign) NSInteger endTime;
@end

NS_ASSUME_NONNULL_END
