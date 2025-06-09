//
//  RTCXPlayerEnumDef.h
//  LinkvisualMedia
//
//  Created by Apple on 2024/8/27.
//

#ifndef RTCXPlayerEnumDef_h
#define RTCXPlayerEnumDef_h
/// 播放器状态回调
typedef NS_ENUM(NSInteger, RTCXCameraPlayerState) {
    // 播放初始化播放未开始
    RTCXCameraPlayerStateInitial = -1,
    // 播放准备就绪
    RTCXCameraPlayerStatePrepared = 0,
    // 播放状态
    RTCXCameraPlayerStatePlaying,
    // 开始图像渲染
    RTCXCameraPlayerStateRenderingStart,
    // 暂停状态
    RTCXCameraPlayerStatePaused,
    // 缓冲状态开始
    RTCXCameraPlayerStateBuffingStart,
    // 缓冲状态结束
    RTCXCameraPlayerStateBuffingEnd,
    // 事件，剪辑视频等，播放完毕
    RTCXCameraPlayerStatePlaybackCompleted,
    // 播放停止
    RTCXCameraPlayerStateStopped,
    /// 播放错误
    RTCXCameraPlayerStateError
};
/// 日志等级
typedef NS_ENUM(NSInteger, IOTPlayerLogLevel) {
    IOT_PLAYER_LOG_UNKNOWN = 0,
    IOT_PLAYER_LOG_LEVEL_VERBOSE,
    IOT_PLAYER_LOG_LEVEL_INFO,
    IOT_PLAYER_LOG_LEVEL_OFF
};
/// 水印位置
typedef NS_ENUM(NSInteger, IOTLogoWatermarkPosition) {
    IOTLogoWatermarkPosition_DefaultPos,   //logo水印默认位置
    IOTLogoWatermarkPosition_LeftTop,      //logo水印位于左上角
    IOTLogoWatermarkPosition_RightTop,     //logo水印位于右上角
    IOTLogoWatermarkPosition_RightBottom,  //logo水印位于右下角
    IOTLogoWatermarkPosition_Left_Bottom,  //logo水印位于左下角
};
/// 回放类型
typedef NS_ENUM(NSInteger, IOTPlaybackType) {
    /// 未知
    IOTPlaybackTypeUnknow,
    /// 云录像回放
    IOTPlaybackTypeCloudRecord,
    /// 云事件回放
    IOTPlaybackTypeCloudEvent,
    /// SD卡录像回放
    IOTPlaybackTypeSDCardRecord,
    /// SD卡事件回放
    IOTPlaybackTypeSDCardEvent
};

/// 旋转角度设置
typedef NS_ENUM (NSInteger, IOTRenderRotation){
    IOT_RENDER_ROTATION_0   = 0,
    IOT_RENDER_ROTATION_90  = 90,
    IOT_RENDER_ROTATION_180 = 180,
    IOT_RENDER_ROTATION_270 = 270
};
/// 播放Trace回调
typedef NS_ENUM(NSInteger, IOTPlayTraces) {
    // Tracek开始
    IOTPlayTracesStart = 0,
    // CMS本地sdp回调
    IOTPlayTracesCMSLocalSdp = 1,
    // CMS远程sdp回调
    IOTPlayTracesCMSRemoteSdp = 2,
    // CMS连接成功
    IOTPlayTracesCMSConnectSuccess = 3,
    // CMS播放成功
    IOTPlayTracesCMSPlaySuccess = 4,
    // P2P本地sdp回调
    IOTPlayTracesP2PLocalSdp = 5,
    // P2P远程sdp回调
    IOTPlayTracesP2PRemoteSdp = 6,
    // P2P连接成功
    IOTPlayTracesP2PConnectSuccess = 7,
    // P2P播放成功
    IOTPlayTracesP2PPlaySuccess = 8,
    // 开始获取URL
    IOTPlayTracesStartUrl = 9,
    // 结束获取URL
    IOTPlayTracesEndUrl = 10,
    // Tracek结束
    IOTPlayTracesEnd = 11,
    // p2p通道个数达到最大
    IOTPlayTracesP2PReachMax = 12,
};
// P2P通道连接状态
typedef NS_ENUM(NSInteger, RTCXP2PChannelConnectStatus) {
    RTCXP2PChannelConnectStatus_Initial = 0,
    RTCXP2PChannelConnectStatus_Success = 1,
    RTCXP2PChannelConnectStatus_Failed = 2,
};
// CMS通道连接状态
typedef NS_ENUM(NSInteger, RTCXCMSChannelConnectStatus) {
    RTCXCMSChannelConnectStatus_Initial = 0,
    RTCXCMSChannelConnectStatus_Success = 1,
    RTCXCMSChannelConnectStatus_Failed = 2,
};
#endif /* RTCXPlayerEnumDef_h */
