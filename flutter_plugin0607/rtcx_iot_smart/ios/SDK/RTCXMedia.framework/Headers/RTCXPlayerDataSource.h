//
//  RTCXPlayerDataSource.h
//  LinkvisualMedia
//
//  Created by Apple on 2024/8/26.
//

#import <Foundation/Foundation.h>
@class RTCXPlayerEnumDef;
@protocol RTCXPlayerDataSource <NSObject>

@optional
/**
 设置logo水印本地路径
 
 @return logo水印本地路径
 */
- (NSString *)getLocalFilePathFromLogoWatermark;
/**
 设置logo水印位置
 
 @return logo水印位置
 */
- (IOTLogoWatermarkPosition)getPositionFromLogoWatermark;
/**
 设置录制视频的分辨率
 
 @return CGSize 例如：720p： （1280.0，720.0）
 */
- (CGSize)changeRecordVideoResolution;
/**
 外部可配置是否硬解

 @return 是否硬解
 */
- (BOOL)isSupportHardwareDecoder;
/**
  是否静音， player初始化时可以在该回调中设置，默认不静音

 @return YES：静音  NO：非静音
 */
- (BOOL)isMuted;
/**
 player初始化之后，onPath之前，可以在该回调中配置Config。如设置YUV数据流；
 */
- (void)onPlayerConfig;
/**
 设置直播策略cms/p2p
 */
- (NSString *)liveOptimizeStrategy;
/**
 设置SD卡回放策略cms/p2p
 */
- (NSString *)backOptimizeStrategy;

@end

