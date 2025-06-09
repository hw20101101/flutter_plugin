//
//  RTCXAudioVideoTalkInterface.h
//  RTCXMedia
//
//  Created by Apple on 2024/9/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <RTCXMedia/RTCXPlayerModel.h>
NS_ASSUME_NONNULL_BEGIN
@class RTCXAudioVideoTalk;
@class RTCXPlayerView;
typedef NS_ENUM(NSInteger, RTCXAudioVideoTalkType) {
    RTCXAudioVideoTalkType_Audio,    // 音频通话
    RTCXAudioVideoTalkType_Video,    // 视频通话
};

@protocol RTCXAudioVideoTalkDelegate <NSObject>
- (void)audioVideoTalk:(RTCXAudioVideoTalk *)audioVideoTalk didFailToAudioVideoTalkWithError:(NSError *)error;
@end

@protocol RTCXAudioVideoTalkInterface <NSObject>

/**
 初始化对象
 @param deviceInfo 设备信息
 @param avTalkType 音频、视频通话话类型
 @param delegate 代理对象
 */
- (id)initWithDeviceInfo:(RTCXPlayInfo *)deviceInfo avTalkType:(RTCXAudioVideoTalkType)avTalkType delegate:(id<RTCXAudioVideoTalkDelegate>)delegate;
/**
 开始通话
 */
- (void)startTalk;
/**
 结束通话
 */
- (void)endTalk;
/**
 设置音视频通话配置
 */
- (void)setAudioVideoTalkConfig:(RTCXAudioVideoTalkConfig *)talkConfig;
/**
 设置视频通话显示小窗口 如果avTalkType == RTCXAudioVideoTalkType_Video，需要调用
 @param superView  小窗口所在父视图
 @param videoFrame 显示小窗口的frame
 */
- (void)setVideoDisplaySuperView:(UIView *)superView videoFrame:(CGRect)videoFrame;
/**
 设置视频画面是否可见,默认可见的(视频可见时播放器会渲染图像,不可见时播放器会停止渲染图像)  YES: 不可见 NO: 可见
 */
- (void)setVideoInvisibleEnable:(BOOL)invisible;
/**
 设置麦克风是否静音 YES: 静音 NO:不静音
 */
- (BOOL)setMuteLocalAudio:(BOOL)mute;
/**
 设置摄像头是否开启 YES: 关闭摄像头 NO:开启摄像头
 */
- (BOOL)setMuteLocalVideo:(BOOL)mute;
/**
 切换前后摄像头 front暂未启用,前后摄像头切换无需参数控制,completionCallback: 摄像头前后切换完成回调,在此回调之后再进行下一次的切换,防止crash
 */
- (BOOL)setSwitchCamera:(BOOL)front completionCallback:(void(^)(int type))callback;
/**
 获取视频通话的视频小窗口view
 */
- (RTCXPlayerView *)localVideoWindow;
@end

NS_ASSUME_NONNULL_END
