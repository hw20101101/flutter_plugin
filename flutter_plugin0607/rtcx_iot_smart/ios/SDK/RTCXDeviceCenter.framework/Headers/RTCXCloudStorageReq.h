//
//  RTCXCloudStorageReq.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/9/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXCloudStorageReq : NSObject
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;

@end

@interface RTCXCloudStorageRecordReq : RTCXCloudStorageReq
// 码流类型：0主码流，1辅码流 可选
@property (nonatomic, strong, nonnull) NSNumber *streamType;
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 录像类型：0 计划录像，1 报警录像，2 主动录像 可选
@property (nonatomic, strong, nonnull) NSNumber *recordType;
// 起始页数，从0开始 可选
@property (nonatomic, strong, nonnull) NSNumber *pageStart;
// 分页大小，默认值是20，最大100。 可选
@property (nonatomic, strong, nonnull) NSNumber *pageSize;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end

@interface RTCXCloudStorageEventReq : RTCXCloudStorageReq
// 事件类型。1（表示移动侦测）；2（表示声音侦测）；3（表示人形侦测）; 不传表示获取所有类型。可选
@property (nonatomic, strong, nonnull) NSArray *eventTypes;
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 分页大小，默认值是50，最大100。 可选
@property (nonatomic, strong, nonnull) NSNumber *pageSize;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;
@end

@interface RTCXCloudStorageVodUrlReq : RTCXCloudStorageReq
// 播放开始时间点,1970年1月1日开始的毫秒数 必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 播放结束时间点,1970年1月1日开始的毫秒数 必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end

@interface RTCXCloudStorageVodEventUrlReq : RTCXCloudStorageReq
// 播放开始时间点,1970年1月1日开始的毫秒数 必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 播放结束时间点,1970年1月1日开始的毫秒数 必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end


@interface RTCXCloudStorageMonthRecordReq : RTCXCloudStorageReq
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 时区的偏移值，比如：+08:00
@property (nonatomic, copy, nonnull) NSString *zoneOffsetId;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end

@interface RTCXCloudStorageMonthEventReq : RTCXCloudStorageReq
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 时区的偏移值，比如：+08:00
@property (nonatomic, copy, nonnull) NSString *zoneOffsetId;
// 事件类型。0（表示全部）；1（表示移动侦测）；2（表示声音侦测）；3（表示人形侦测）。可选
@property (nonatomic, strong, nonnull) NSNumber *eventType;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end

@interface RTCXCloudStorageDeleteRecordReq : RTCXCloudStorageReq
// 删除开始时间，1970年1月1日开始的毫秒数，不填为endTime之前的数据全部删除。可选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 删除结束时间，1970年1月1日开始的毫秒数。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end

@interface RTCXCloudStorageDeleteEventInfo : RTCXCloudStorageReq
// 事件ID
@property (nonatomic, assign) NSInteger eventId;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;
// 机房名 必选
@property (nonatomic, copy) NSString *region;

@end

@interface RTCXCloudStorageDeleteEventReq : RTCXCloudStorageReq
// 事件数组 必选
@property (nonatomic, strong, nonnull) NSArray<RTCXCloudStorageDeleteEventInfo*> *events;

@end

@interface RTCXCloudStorageEventDescReq : RTCXCloudStorageReq
// 事件类型。0（表示全部）；1（表示移动侦测）；2（表示声音侦测）；3（表示人形侦测）。可选
@property (nonatomic, strong, nonnull) NSNumber *eventType;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end

@interface RTCXCloudStorageCurrentRegionReq : RTCXCloudStorageReq
// 获取对应机房服务域名列表，例如：gateway 必选
@property (nonatomic, strong, nonnull) NSArray *serviceNameList;
// 调用来源。 可选
@property (nonatomic, copy) NSString *origin;

@end

@interface RTCXCloudStorageHistoryRegionReq : RTCXCloudStorageReq
// 获取对应机房服务域名列表，例如：gateway 必选
@property (nonatomic, strong, nonnull) NSArray *serviceNameList;
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 调用来源。 可选
@property (nonatomic, copy) NSString *origin;

@end

@interface RTCXCloudStorageMessageEventReq : RTCXCloudStorageReq
// 事件类型。0：（自定义消息）；1（表示移动侦测）；2（表示声音侦测）；3（表示人形侦测）; 不传表示获取所有类型。可选
@property (nonatomic, strong, nonnull) NSArray *eventTypes;
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 分页大小，默认值是50，最大100。 可选
@property (nonatomic, strong, nonnull) NSNumber *pageSize;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;
// 自定义上报事件的标识符，如["OpenDoor"], 可选
@property (nonatomic, strong, nonnull) NSArray *identifiers;
@end

@interface RTCXCloudStorageMonthMessageReq : RTCXCloudStorageReq
// 查询开始时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *beginTime;
// 查询结束时间。单位毫秒。必选
@property (nonatomic, strong, nonnull) NSNumber *endTime;
// 时区的偏移值，比如：+08:00
@property (nonatomic, copy, nonnull) NSString *zoneOffsetId;
// 物模型事件或属性标识，可选
@property (nonatomic, copy, nullable) NSNumber *identifier;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end

@interface RTCXCloudStorageMessageDescReq : RTCXCloudStorageReq
// 物模型事件或属性标识，可选
@property (nonatomic, copy, nullable) NSNumber *identifier;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;

@end

@interface RTCXCloudStorageDeleteMessageInfo : RTCXCloudStorageReq
// 事件ID
@property (nonatomic, assign) NSInteger eventId;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;
// 机房名 必选
@property (nonatomic, copy) NSString *region;

@end

@interface RTCXCloudStorageDeleteMessageReq : RTCXCloudStorageReq
// 事件数组 必选
@property (nonatomic, strong, nonnull) NSArray<RTCXCloudStorageDeleteMessageInfo*> *messages;

@end

@interface RTCXCloudStoragePicUrlReq : RTCXCloudStorageReq
// 图片ID列表array[string]，eg：["main/1/1/1740485609452"], 必选
@property (nonatomic, strong, nonnull) NSArray *pictureIdList;
// 多目指定镜头时填写 可选
@property (nonatomic, strong, nonnull) NSNumber *lensId;
// 图片来源，不填或0：消息中心，1：事件中心, 可选
@property (nonatomic, strong, nonnull) NSNumber *datasource;
@end
NS_ASSUME_NONNULL_END
