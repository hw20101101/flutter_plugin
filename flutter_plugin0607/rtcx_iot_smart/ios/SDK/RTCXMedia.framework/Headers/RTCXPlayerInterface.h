//
//  RTCXPlayerInterface.h
//  LinkvisualMedia
//
//  Created by Apple on 2024/8/26.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <RTCXMedia/RTCXPlayerEnumDef.h>
#import <RTCXMedia/RTCXPlayerModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RTCXPlayerInterface <NSObject>
/**
 直播调用
 */
- (void)start;
/**
 回放调用

 @param playbackInfo  回放参数
 */
- (void)seekToTime:(RTCXPlaybackInfo*)playbackInfo;
/**
 释放player（不再需要时调用释放）
 */
- (void)releasePlayer;
/**
 恢复播放
 */
- (BOOL)resume;
/**
 暂停播放
 */
- (BOOL)pause;
/**
 停止播放
 */
- (BOOL)stop;
/**
 是否是回放
 */
- (BOOL)isPlayBack;
/**
 获取帧率 fps
 */
- (long)getPlayFPS;
/**
 获取码率 单位bit
 */
- (long)getBitrate;
/**
 设置播放器放大倍数
 
 @param scale 原始放大倍数，初始化为1，最大为4
 */
- (BOOL)setScaleRation:(int)scale;
/**
 获取播放画面Size
 */
- (CGSize)getVideoSize;
/**
 获取回放类型
 */
- (IOTPlaybackType)getPlaybackType;
/**
 AudioTalk的指针
 @return void  handle
 */
- (void *)getPlayerAudioOutputHandle;
/**
 设置旋转角度
 
 @param degrees 旋转角度 
 */
- (void)setVideoRotate:(IOTRenderRotation)degrees;
/**
 倍速播放
 
 @param rate 1、2、4等
 */
- (void)setPlaybackSpeed:(float)rate;
/**
 设置播放音量
 
 @param volume  取值0-100  其中0：静音 100：最大音量
 */
- (void)setVolume:(int32_t)volume;
/**
 设置播放是否静音
 
 @param mute 是否静音 YES：静音  NO：非静音
 */
- (void)setMuteRemoteAudio:(BOOL)mute;
/**
 获取播放器版本号
 */
+ (NSString *)getPlayerVersion;
/**
 获取rtc player模块版本
 */
+ (NSString *)getRtcPlayerVersion;
/**
 设置stunServiceIp（用于p2p打洞）
 */
+ (void)setStunServiceIp:(NSString *)stunServiceIp;
/**
 获取player正在使用的视频流通道
 
 @return CMS, P2P
 */
- (NSString *)getPlayerCurrentChannel;
/**
 获取player镜头Id
 
 @return 镜头Id
 */
- (int)getLensId;
/**
 边播边录
 
 @param path 保存文件夹
 @param isAdd 是否添加时间水印
 @return image
 */
- (BOOL)startRecord:(NSString *)path isAddTimeWatermark:(BOOL)isAdd;
/**
 停止边播边录
 */
- (BOOL)stopRecord;
/**
 截图
 
 @param bOriginalPic 是否原始尺寸
 @param isAdd 是否添加时间水印
 @return image
 */
- (UIImage *)snapshot:(BOOL)bOriginalPic isAddTimeWatermark:(BOOL)isAdd;
/**
 获取缩放比例
 */
- (float)getScaleRation;
/**
 player当前的播放状态
 */
- (RTCXCameraPlayerState)getPlayerState;
/**
 player当前播放错误码 (与上面getPlayerState方法返回状态一一对应)
 */
- (int)getPlayerErrorCode;
/**
 获取播放偏移量，单位毫秒
 */
- (NSInteger)getPosition;
/**
 获取当前播放时间，单位秒
 */
- (NSTimeInterval)getCurrentTime;
/**
 设置码流类型，0：主码流  1：辅码流
 */
- (void)setPlayStreamType:(int)streamType;
/**
 获取码流类型，0：主码流  1：辅码流
 */
- (int)getPlayStreamType;
/**
 设置视频画面是否可见,默认可见的(视频可见时播放器会渲染图像,不可见时播放器会停止渲染图像)  YES: 不可见 NO: 可见
 */
- (void)setVideoInvisibleEnable:(BOOL)invisible;
/**
 设置音视频通话配置
 */
- (void)setAudioVideoTalkConfig:(RTCXAudioVideoTalkConfig *)talkConfig;
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
 Pinch手势事件更新View
 
 @param viewVelocity Pinch手势 scale
 @param midPoint 手势View中心点坐标
 @return 是否设置成功
 */
- (BOOL)updatePlayerViewTouchPinch:(float)viewVelocity withMidPoint:(CGPoint)midPoint;
/**
 double tap手势事件更新View
 
 @param tapPoint double tap坐标
 @return 是否设置成功
 */
- (BOOL)updatePlayerViewDoubleTap:(CGPoint)tapPoint;
/**
 touch move更新View
 
 @param viewXYVelocityDict means the velocity for touch move of X and Y
 例:
 NSDictionary *viewXYVelocityDict = @{
 @"mViewXVelocity":@([(UIPanGestureRecognizer *)panges velocityInView:panges.view].x),
 @"mViewYVelocity":@([(UIPanGestureRecognizer *)panges velocityInView:panges.view].y)
 };
 @return 是否设置成功
 */
- (BOOL)updatePlayerViewTouchXYVelocity:(NSDictionary * )viewXYVelocityDict;
/**
 touch move更新View
 
 @param touchEventType touch event事件
 TOUCH_UP == 0
 TOUCH_DOWN == 1
 TOUCH_MOVE == 2
 @param touchPoint1 touch point 1坐标
 @param touchPoint2 touch point 2坐标
 @return 是否设置成功
 */
- (BOOL)updatePlayerViewTouchEvent:(int)touchEventType andStart:(CGPoint)touchPoint1 andEnd:(CGPoint)touchPoint2;

@end

NS_ASSUME_NONNULL_END
