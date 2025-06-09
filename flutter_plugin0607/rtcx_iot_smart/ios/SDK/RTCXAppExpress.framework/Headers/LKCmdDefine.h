//
//  LKCmdDefine.h
//  LKAppExpress
//
//  Created by Apple on 2024/8/24.
//

#ifndef LKCmdDefine_h
#define LKCmdDefine_h

/**
 设备上报绑定令牌（设备通知客户端可以开始绑定通知）
 */
extern NSString *const LKCMDDeviceTokenBindNotification;
/**
 RTC相关信息消息通知
 */
extern NSString *const LKCMDTRtcMessageCallbackNotification;
/**
 客户端登录账号发生改变通知(如：在另一端修改了密码、登录等，当前端登录账号会收到该消息)
 */
extern NSString *const RTCXCMDAccountChangedNotification;
/**
 SD卡回放结束通知（当SD卡回放到没有数据的时候，会发送该通知）
 */
extern NSString *const RTCXCMDSDPlaybackEndNotification;
/**
 服务器触发客户端绑定结果通知（有线/4G设备绑定）
 */
extern NSString *const LKCMDDeviceBindNotification;
#endif /* LKCmdDefine_h */
