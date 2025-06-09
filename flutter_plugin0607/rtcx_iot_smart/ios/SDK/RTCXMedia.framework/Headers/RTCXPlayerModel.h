//
//  RTCXPlayerModel.h
//  RTCXMedia
//
//  Created by Apple on 2024/9/10.
//

#import <Foundation/Foundation.h>
#import <RTCXMedia/RTCXPlayerEnumDef.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXPlayerModel : NSObject

@end

@interface RTCXPlayInfo : NSObject
// 设备型号 如：xLeWcoelZbyOePbJludl 必选
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002 必选
@property (nonatomic, copy) NSString *deviceName;
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 是否需要播放预连接  YES: 预连接, NO: 不预连接; 默认NO 可选
@property (nonatomic, assign) BOOL preConnectEnable;
// 设备镜头ID 可选
@property (nonatomic, strong) NSNumber *lensId;
// 码流类型，0：主码流  1：辅码流，默认为0
@property (nonatomic, assign) int streamType;
// 设备属性值字典 必选
@property (nonatomic, strong) NSDictionary *propertyMap;
// 设备套餐信息 必选
@property (nonatomic, strong) NSDictionary *cloudServicesDic;
@end

@interface RTCXPlaybackInfo : NSObject
// startTime 起始时间戳(秒) start = end时一直播下去
@property (nonatomic, assign) NSTimeInterval startTime;
// endTime  结束时间戳(秒) start = end时一直播下去
@property (nonatomic, assign) NSTimeInterval endTime;
// 回放类型
@property (nonatomic, assign) IOTPlaybackType playbackType;
// SD卡文件名，SD卡文件播放时，需要传此参数，可选
@property (nonatomic, copy) NSString *sdFileName;
// SD卡文件开始时间戳(秒)，SD卡文件播放时，需要传此参数，可选
@property (nonatomic, assign) NSTimeInterval sdFileStartTime;

@end

@interface RTCXAudioVideoTalkConfig : NSObject
/**
 是否音频通话
 */
@property (nonatomic, assign) BOOL audioTalk;
/**
 是否视频通话
 */
@property (nonatomic, assign) BOOL videoTalk;
/**
 设置视频通话分辨率 width
 */
@property (nonatomic, assign) int videoResolutionRatioWidth;
/**
 设置视频通话分辨率 height
 */
@property (nonatomic, assign) int videoResolutionRatioHeight;
/**
 设置视频通话帧率
 */
@property (nonatomic, assign) int videoFps;
/**
 获取视频通话码率
 */
@property (nonatomic, assign) int videoMaxBitrate;

@end
NS_ASSUME_NONNULL_END
