//
//  RTCXPlayerDelegate.h
//  LinkvisualMedia
//
//  Created by Apple on 2024/8/26.
//

#import <Foundation/Foundation.h>
#import <RTCXMedia/RTCXPlayerInterface.h>
NS_ASSUME_NONNULL_BEGIN

@protocol RTCXPlayerDelegate <NSObject>
/**
 player播放状态回调

 @param playState player状态（RTCXCameraPlayerState）
 @param code player错误码
 */
- (void)onPlayStateChanged:(RTCXCameraPlayerState)playState code:(int)code;

@optional
/**
 视频录制回调

 @param currentTime 回调当前录制时间
 @param filePath 回调数据路径
 @param error 视频录制错误
 */
- (void)onPlayerMp4Record:(NSInteger)currentTime filePath:(NSString *)filePath error:(NSError *)error;
/**
 当打开player全链路日志开关时，数据返回

 @param data 返回的数据
 */
- (void)onPlayerDataCollection:(NSString *)data;
/**
 video size 更新回调

 @param size 宽、高
 */
- (void)onPlayFrameChanged:(CGSize)size;
/**
 播放trace回调（可统计耗时）

 @param playTrace 播放trace（IOTPlayTraces）
 @param tempstime trace发生时间点
 @param msg 显示消息
 */
- (void)onPlayTracesChanged:(IOTPlayTraces)playTrace time:(NSInteger)tempstime message:(nullable NSString *)msg;
@end

NS_ASSUME_NONNULL_END
