#import "FlutterPlugin0607Plugin.h"
// 导入初始化SDK头文件
#import <RTCXIotSmart/RTCXIotSmart.h>
// 导入日志SDK头文件
#import <RTCXLog/RTCXLog.h>

// 导入账号管理SDK头文件
#import <RTCXOpenAccountCloud/RTCXOpenAccountCloud.h>

@implementation FlutterPlugin0607Plugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    
    //test
    [FlutterPlugin0607Plugin testRTCXSDK];
    
  FlutterMethodChannel* channel = [FlutterMethodChannel
      methodChannelWithName:@"flutter_plugin0607"
            binaryMessenger:[registrar messenger]];
  FlutterPlugin0607Plugin* instance = [[FlutterPlugin0607Plugin alloc] init];
  [registrar addMethodCallDelegate:instance channel:channel];
}

+ (void)testRTCXSDK {
    
#if defined(DEBUG)
    // 开启控制台日志
    [RTCXLog showInConsole:YES];
#else
    // 开启控制台日志
    [RTCXLog showInConsole:YES];
    // 日志重定向
    [self redirectLocalLogManager];
#endif
    NSString *appKey = @"bOk9F2kUwgb1z4n3F6evQCc4l";
    NSString *appSecret = @"fg5d0HyycDjnEmYuO0aGuRgO1RvVnQz";
//    NSArray *array = [[NSUserDefaults standardUserDefaults] objectForKey:@""];
//    if (array.count == 2) {
//        appKey = array.firstObject;
//        appSecret = array.lastObject;
//    }
    // 用户鉴权失效监听
    [RTCXService(RTCXOpenAccountProtocol) setAuthenticationAbnormalCallback:^(NSInteger code, NSString * _Nonnull message) {
        if (code == 30314) {// token失效
            NSLog(@"-->> token失效");
//            if ([RTCXService(RTCXOpenAccountProtocol) isLogin]) {
//                [[self currentViewController].navigationController popToRootViewControllerAnimated:YES];// token过期退出登录
//            }
        }
    }];
    // 初始化SDK
    RTCXIotSmartConfig *config = [RTCXIotSmartConfig new];
    config.appKey = appKey;//需要自行配置自有app的appkey
    config.appSecret = appSecret;//需要自行配置自有app的appSecurit
    //config.regionType = REGION_ALL;//设置App使用范围
    [RTCXIotSmart sharedInstance].config = config;
    
    [[RTCXIotSmart sharedInstance] setSdkInitCompletedCallback:^{
        NSLog(@"-->> SDK初始化完成回调");
        //[weakSelf autoLoginCheck];
        
        BOOL isCompleted = [[RTCXIotSmart sharedInstance] sdkInitializationCompleted];
        NSLog(@"-->> SDK初始化完成回调 2:%d", isCompleted);
    }];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
  if ([@"getPlatformVersion" isEqualToString:call.method]) {
    result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
  } else {
    result(FlutterMethodNotImplemented);
  }
}

@end
