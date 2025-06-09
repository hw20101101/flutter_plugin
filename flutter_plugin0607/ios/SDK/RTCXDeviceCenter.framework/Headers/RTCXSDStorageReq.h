//
//  RTCXSDStorageReq.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2024/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXSDStorageReq : NSObject
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 设备型号 如：xLeWcoelZbyOePbJludl 必选
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002 必选
@property (nonatomic, copy) NSString *deviceName;
@end

@interface RTCXSDStorageRecordReq : RTCXSDStorageReq
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 录像类型：0 计划录像，1 报警录像，2 主动录像, 99 所有类型 可选
@property (nonatomic, strong, nonnull) NSNumber *recordType;
// 分页大小，默认值是20，最大100。 可选
@property (nonatomic, strong, nonnull) NSNumber *pageSize;
// 是否支持数据压缩,（可以通过设备能力集属性deviceSdkAbility中的[1,2,4,7]是否包含7判断是否支持数据压缩），如果传YES,会对返回数据压缩，可选
@property (nonatomic, assign) BOOL compressEnable;

@end

@interface RTCXSDStorageRecordEventReq : RTCXSDStorageReq
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 录像类型：0 所有报警类型，1 移动侦测，2 声音侦测, 默认0， 可选
@property (nonatomic, strong, nonnull) NSNumber *recordType;
// 分页大小，默认值是10，最大100。 可选
@property (nonatomic, strong, nonnull) NSNumber *pageSize;
// 是否支持数据压缩,（可以通过设备能力集属性deviceSdkAbility中的[1,2,4,7]是否包含7判断是否支持数据压缩），如果传YES,会对返回数据压缩，可选
@property (nonatomic, assign) BOOL compressEnable;

@end

@interface RTCXSDStorageRecordFileReq : RTCXSDStorageReq
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 录像类型：0 计划录像，1 报警录像，2 主动录像, 99 所有类型 可选
@property (nonatomic, strong, nonnull) NSNumber *recordType;
// 分页大小，默认值是30，最大100。 可选
@property (nonatomic, strong, nonnull) NSNumber *pageSize;
// 是否支持数据压缩,（可以通过设备能力集属性deviceSdkAbility中的[1,2,4,7]是否包含7判断是否支持数据压缩），如果传YES,会对返回数据压缩，可选
@property (nonatomic, assign) BOOL compressEnable;

@end

@interface RTCXSDStorageMonthRecordReq : RTCXSDStorageReq
// 查询年份。如：2025，表示2025年，必选
@property (nonatomic, strong, nonnull) NSNumber *year;
// 查询月份。如：1，表示1月，必选
@property (nonatomic, strong, nonnull) NSNumber *month;

@end

NS_ASSUME_NONNULL_END
