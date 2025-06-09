//
//  RTCXPushServiceModel.h
//  RTCXPush
//
//  Created by Apple on 2025/1/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXPushServiceModel : NSObject

@end

@interface RTCXPushScheduleItem : NSObject
// 开始时间。单位秒。
@property (nonatomic, strong) NSNumber *start;
// 结束时间。单位秒。（end时间应始终大于start时间，跨天的时候，end为第二天的时间）
@property (nonatomic, strong) NSNumber *end;
// 重复周期，0：执行一次 1：每天重复 2：每周重复 3：每月重复 （目前支持1和2）
@property (nonatomic, strong) NSNumber *repeat;
// 对应的值仅在"repeat"为2时有效，存在重复设置值：SUN:0x0001, MON:0x0002, TUE:0x0004, WED:0x0008, THU:0x0010, FRI:0x0020, SATU:0x0040，支持按位或操作
@property (nonatomic, strong) NSNumber *week;
// 对应的值 1表示状态开，0表示状态关
@property (nonatomic, strong) NSNumber *status;
@end

@interface RTCXPushSchedule : NSObject
// Schedule子计划列表
@property (nonatomic, strong) NSMutableArray <RTCXPushScheduleItem *> *scheduleList;
// Schedule总开关, 1表示状态开，0表示状态关
@property (nonatomic, strong) NSNumber *status;
// 对应的值 1表示图片推送开，0表示图片推送关
@property (nonatomic, strong) NSNumber *image;
// 推送间隔 单位：秒
@property (nonatomic, strong) NSNumber *interval;
@end

@interface RTCXPnsScheduleSetReq : NSObject
// 平台为设备颁发的ID，设备的唯一标识符。
@property (nonatomic, copy) NSString *iotId;
// Schedule
@property (nonatomic, strong) RTCXPushSchedule *schedule;
@end

@interface RTCXPnsScheduleGetReq : NSObject
// 平台为设备颁发的ID，设备的唯一标识符。
@property (nonatomic, copy) NSString *iotId;
@end

NS_ASSUME_NONNULL_END
