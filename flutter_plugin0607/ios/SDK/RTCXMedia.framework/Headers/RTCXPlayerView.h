//
//  RTCXPlayerView.h
//  LinkvisualMedia
//
//  Created by Apple on 2024/8/26.
//

#import <UIKit/UIKit.h>
#import <RTCXMedia/RTCXPlayerController.h>
#import <RTCXMedia/RTCXPlayerModel.h>
@interface RTCXPlayerView : UIView
/**
AudioOutputHandle 用于语音对讲功能
*/
@property (nonatomic, assign) void *currentAudioOutputHandle;
/**
 player相关接口调用
 */
@property (nonatomic, strong) RTCXPlayerController *playerController;

/**
 初始化View
 @param frame 需要展示视频的frame
 @param playInfo 播放设备信息
 */
- (id)initWithFrame:(CGRect)frame withPlayInfo:(RTCXPlayInfo *)playInfo;
@end
