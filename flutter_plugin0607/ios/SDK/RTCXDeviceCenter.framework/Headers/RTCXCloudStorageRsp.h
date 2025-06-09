//
//  RTCXCloudStorageRsp.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/9/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXCloudStorageRsp : NSObject

@end

@interface RTCXCloudStorageRecordRsp : RTCXCloudStorageRsp
// 文件开始时间
@property (nonatomic, assign) NSInteger beginTime;
// 文件结束时间
@property (nonatomic, assign) NSInteger endTime;
// 录像类型：0 计划录像，1 报警录像，2 主动录像
@property (nonatomic, assign) NSInteger recordType;
// 码流类型：0主码流，1辅码流
@property (nonatomic, assign) NSInteger streamType;
// 录像缩略图URL
@property (nonatomic, copy) NSString *snapshotUrl;
// 机房名
@property (nonatomic, copy) NSString *region;

@end

@interface RTCXCloudStorageRecordListRsp : RTCXCloudStorageRsp
// 下一页是否有效
@property (nonatomic, assign) BOOL nextValid;
// 下一页结束时间
@property (nonatomic, assign) NSInteger nextEndTime;
// 云端录像文件列表<RTCXCloudStorageSectionRsp>
@property (nonatomic, strong) NSArray *recordFileList;

@end

@interface RTCXCloudStorageEventRsp : RTCXCloudStorageRsp
// 事件ID
@property (nonatomic, assign) NSInteger eventId;
// 事件开始时间
@property (nonatomic, assign) NSInteger beginTime;
// 事件结束时间
@property (nonatomic, assign) NSInteger endTime;
// 事件类型。0（表示全部）；1（表示移动侦测）；2（表示声音侦测）；3（表示人形侦测）
@property (nonatomic, assign) NSInteger eventType;
// 码流类型：0主码流，1辅码流
@property (nonatomic, copy) NSString *extraData;
// 事件缩略图
@property (nonatomic, copy) NSString *imgUrl;
// 镜头ID
@property (nonatomic,copy) NSString *lensId;
// 机房名
@property (nonatomic, copy) NSString *region;
@end

@interface RTCXCloudStorageEventListRsp : RTCXCloudStorageRsp
// 云端事件列表<RTCXCloudStorageEventRsp>
@property (nonatomic, strong) NSArray *eventList;
// 下一页是否有效
@property (nonatomic, assign) BOOL nextValid;
// 下一页结束时间
@property (nonatomic, assign) NSInteger nextEndTime;

@end

@interface RTCXCloudStorageVodUrlRsp : RTCXCloudStorageRsp
// 点播地址，带鉴权信息，无法重复使用
@property (nonatomic, copy) NSString *vodUrl;

@end

@interface RTCXCloudStorageVodEventUrlRsp : RTCXCloudStorageRsp
// 点播地址，带鉴权信息，无法重复使用
@property (nonatomic, copy) NSString *vodUrl;

@end

@interface RTCXCloudStorageDayRecordRsp : RTCXCloudStorageRsp
// 比如：2024-09-02
@property (nonatomic, copy) NSString *dateStr;
// 当天事件个数
@property (nonatomic, assign) NSInteger count;

@end

@interface RTCXCloudStorageMonthRecordRsp : RTCXCloudStorageRsp
// 长度为当月天数，每位表示当天是否有事件
@property (nonatomic, strong) NSArray<RTCXCloudStorageDayRecordRsp*> *dayCntList;

@end

@interface RTCXCloudStorageDayEventRsp : RTCXCloudStorageRsp
// 比如：2024-09-02
@property (nonatomic, copy) NSString *dateStr;
// 当天事件个数
@property (nonatomic, assign) NSInteger count;

@end

@interface RTCXCloudStorageMonthEventRsp : RTCXCloudStorageRsp
// 长度为当月天数，每位表示当天是否有事件
@property (nonatomic, strong) NSArray<RTCXCloudStorageDayEventRsp*> *eventCntList;

@end

@interface RTCXCloudStorageDeleteRecordRsp : RTCXCloudStorageRsp
// event数量
@property (nonatomic, assign) NSInteger eventCnt;
// record数量
@property (nonatomic, assign) NSInteger recordCnt;

@end

@interface RTCXCloudStorageDeleteEventRsp : RTCXCloudStorageRsp
// 删除数量
@property (nonatomic, assign) NSInteger count;

@end

@interface RTCXCloudStorageEventDescRsp : RTCXCloudStorageRsp
// 最新一条数据开始时间
@property (nonatomic, assign) NSInteger latestBeginTime;

@end

@interface RTCXCloudStorageCurrentRegionRsp : RTCXCloudStorageRsp
// 机房名
@property (nonatomic, copy) NSString *region;
// 服务域名列表， key为服务名称，例如gateway
@property (nonatomic, strong) NSDictionary *serviceAddresses;

@end

@interface RTCXCloudStorageRegionRsp : RTCXCloudStorageRsp
// 机房名
@property (nonatomic, copy) NSString *region;
// 开始时间戳。单位毫秒。
@property (nonatomic, assign) NSInteger startTime;
// 结束时间戳，当前机房没有结束时间。单位毫秒。
@property (nonatomic, assign) NSInteger endTime;
// 服务域名列表， key为服务名称，例如gateway
@property (nonatomic, strong) NSDictionary *serviceAddresses;

@end

@interface RTCXCloudStorageHistoryRegionListRsp : RTCXCloudStorageRsp
// 机房列表
@property (nonatomic, strong) NSArray<RTCXCloudStorageRegionRsp*> *regionList;

@end

@interface RTCXCloudStorageMessageEventRsp : RTCXCloudStorageRsp
// 事件ID
@property (nonatomic, assign) NSInteger eventId;
// 事件开始时间
@property (nonatomic, assign) NSInteger beginTime;
// 事件结束时间
@property (nonatomic, assign) NSInteger endTime;
// 事件类型。-128（自定义消息）；1（表示移动侦测）；2（表示声音侦测）；3（表示人形侦测）
@property (nonatomic, assign) NSInteger eventType;
// 码流类型：0主码流，1辅码流
@property (nonatomic, copy) NSString *extraData;
// 事件缩略图
@property (nonatomic, copy) NSString *imgUrl;
// 镜头ID
@property (nonatomic,copy) NSString *lensId;
// 0：纯消息类型，1：录像类型，2：图片类型
@property (nonatomic, assign) NSInteger dataType;
// 自定义事件的标识符, 如：OpenDoor
@property (nonatomic,copy) NSString *identifier;
// 机房名
@property (nonatomic, copy) NSString *region;
@end

@interface RTCXCloudStorageMessageEventListRsp : RTCXCloudStorageRsp
// 云端事件列表<RTCXCloudStorageMessageEventRsp>
@property (nonatomic, strong) NSArray *eventList;
// 下一页是否有效
@property (nonatomic, assign) BOOL nextValid;
// 下一页结束时间
@property (nonatomic, assign) NSInteger nextEndTime;

@end

@interface RTCXCloudStorageDayMessageRsp : RTCXCloudStorageRsp
// 比如：2024-09-02
@property (nonatomic, copy) NSString *dateStr;
// 当天事件个数
@property (nonatomic, assign) NSInteger count;

@end

@interface RTCXCloudStorageMonthMessageRsp : RTCXCloudStorageRsp
// 长度为当月天数，每位表示当天是否有消息
@property (nonatomic, strong) NSArray<RTCXCloudStorageDayMessageRsp*> *eventCntList;

@end

@interface RTCXCloudStorageMessageDescRsp : RTCXCloudStorageRsp
// 最新一条数据开始时间
@property (nonatomic, assign) NSInteger latestBeginTime;

@end

@interface RTCXCloudStorageDeleteMessageRsp : RTCXCloudStorageRsp
// 删除数量
@property (nonatomic, assign) NSInteger count;

@end

@interface RTCXCloudStoragePicUrlRsp : RTCXCloudStorageRsp
// 图片ID
@property (nonatomic, copy) NSString *pictureId;
// 图片的链接
@property (nonatomic,copy) NSString *pictureUrl;

@end

@interface RTCXCloudStoragePicUrlListRsp : RTCXCloudStorageRsp
// 图片地址数组
@property (nonatomic, strong) NSArray<RTCXCloudStoragePicUrlRsp*> *pictureList;

@end
NS_ASSUME_NONNULL_END
