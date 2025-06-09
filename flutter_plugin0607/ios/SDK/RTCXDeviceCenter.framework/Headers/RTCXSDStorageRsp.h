//
//  RTCXSDStorageRsp.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2024/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXSDStorageRsp : NSObject

@end

@interface RTCXSDStorageRecordRsp : RTCXSDStorageRsp
// 文件开始时间
@property (nonatomic, assign) NSInteger beginTime;
// 文件结束时间
@property (nonatomic, assign) NSInteger endTime;
// 录像类型：0 计划录像，1 报警录像，2 主动录像 
@property (nonatomic, assign) NSInteger recordType;

@end

@interface RTCXSDStorageRecordListRsp : RTCXSDStorageRsp
// 下一页是否有效
@property (nonatomic, assign) BOOL nextValid;
// 下一页结束时间
@property (nonatomic, assign) NSInteger nextEndTime;
// SD卡录像列表<RTCXSDStorageRecordRsp>
@property (nonatomic, strong) NSArray *recordList;

@end

@interface RTCXSDStorageRecordEventRsp : RTCXSDStorageRsp
// 文件开始时间
@property (nonatomic, assign) NSInteger beginTime;
// 文件结束时间
@property (nonatomic, assign) NSInteger endTime;
// 录像类型：1 移动侦测，2 声音侦测
@property (nonatomic, assign) NSInteger recordType;

@end

@interface RTCXSDStorageRecordEventListRsp : RTCXSDStorageRsp
// 下一页是否有效
@property (nonatomic, assign) BOOL nextValid;
// 下一页结束时间
@property (nonatomic, assign) NSInteger nextEndTime;
// SD卡事件列表<RTCXSDStorageRecordEventRsp>
@property (nonatomic, strong) NSArray *recordEventList;

@end

@interface RTCXSDStorageRecordFileRsp : RTCXSDStorageRsp
// 文件录像名
@property (nonatomic, copy) NSString *fileName;
// 文件开始时间
@property (nonatomic, assign) NSInteger beginTime;
// 文件结束时间
@property (nonatomic, assign) NSInteger endTime;
// 文件大小
@property (nonatomic, copy) NSString *size;
// 录像类型：0 计划录像，1 报警录像，2 主动录像
@property (nonatomic, assign) NSInteger recordType;

@end

@interface RTCXSDStorageRecordFileListRsp : RTCXSDStorageRsp
// 下一页是否有效
@property (nonatomic, assign) BOOL nextValid;
// 下一页结束时间
@property (nonatomic, assign) NSInteger nextEndTime;
// SD卡录像文件列表<RTCXSDStorageRecordFileRsp>
@property (nonatomic, strong) NSArray *recordFileList;

@end

@interface RTCXSDStorageDayRecordRsp : RTCXSDStorageRsp
// 比如：2024-09-02
@property (nonatomic, copy) NSString *dateStr;

@end

@interface RTCXSDStorageMonthRecordRsp : RTCXSDStorageRsp
//  月录像列表
@property (nonatomic, strong) NSArray<RTCXSDStorageDayRecordRsp*> *monthRecordList;

@end

NS_ASSUME_NONNULL_END
