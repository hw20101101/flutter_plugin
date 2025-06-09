//
//  RTCXPushProtocol.h
//  RTCXPush
//
//  Created by Apple on 2024/9/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RTCXPushProtocol <NSObject>
/// sdk初始化方法，请在 AppDelegate  [application:didFinishLaunchingWithOptions:`] 回调方法中调用此API
/// @param application 应用实例，直接使用AppDelegate [application:didFinishLaunchingWithOptions:`] 回调方法的 application 参数
/// @param launchOptions  应用启动选项，直接使用AppDelegate [application:didReceiveRemoteNotification:`] 回调方法的 launchOptions 参数
- (BOOL)application:(UIApplication *_Nonnull)application didFinishLaunchingWithOptions:(NSDictionary *_Nullable)launchOptions;



/// 注册 apns 成功回调时，使用此方法通知 sdk 初始化 移动推送通道
/// @param application  应用实例，直接使用AppDelegate [application:didRegisterForRemoteNotificationsWithDeviceToken:`] 回调方法的 application 参数
/// @param deviceToken   直接使用AppDelegate [application:didReceiveRemoteNotification:`] 回调方法的 deviceToken 参数
- (void)application:(UIApplication * _Nonnull)application
didRegisterForRemoteNotificationsWithDeviceToken:(NSData * _Nonnull)deviceToken;



/// 注册 apns 成功回调时，使用此方法通知 sdk
/// @param application application 应用实例，直接使用AppDelegate [application:didFailToRegisterForRemoteNotificationsWithError:`] 回调方法的 application 参数
/// @param error 失败原因介绍。直接使用AppDelegate [application:didFailToRegisterForRemoteNotificationsWithError:`] 回调方法的 error 参数
- (void)application:(UIApplication *_Nonnull)application
didFailToRegisterForRemoteNotificationsWithError:(NSError *_Nonnull)error;



/// 在收到 apns 推送消息，调用此 API 通知 SDK，请在 AppDelegate [application:didReceiveRemoteNotification:`] 回调方法中调用此API
/// @param application 应用实例，直接使用AppDelegate [application:didReceiveRemoteNotification:`] 回调方法的 application 参数
/// @param userInfo  apns 推送消息的内容，直接使用AppDelegate [application:didReceiveRemoteNotification:`] 回调方法的 userInfo 参数
- (void)application:(UIApplication *_Nonnull)application didReceiveRemoteNotification:(NSDictionary * _Nonnull)userInfo;

@end

NS_ASSUME_NONNULL_END
