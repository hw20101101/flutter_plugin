#import "FlutterPlugin2Plugin.h"
#include "WXApi.h"

@implementation FlutterPlugin2Plugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  FlutterMethodChannel* channel = [FlutterMethodChannel
      methodChannelWithName:@"flutter_plugin2"
            binaryMessenger:[registrar messenger]];
  FlutterPlugin2Plugin* instance = [[FlutterPlugin2Plugin alloc] init];
  [registrar addMethodCallDelegate:instance channel:channel];
    
    //测试微信 SDK 调用是否成功
    NSString *ver = [WXApi getApiVersion];
    NSString *url = [WXApi getWXAppInstallUrl];
    NSLog(@"-->> WXApi ver:%@ - url:%@", ver, url);
    //输出：WXApi ver:2.0.4 - url:https://itunes.apple.com/cn/app/id414478124?mt=8
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
  if ([@"getPlatformVersion" isEqualToString:call.method]) {
    result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
  } else {
    result(FlutterMethodNotImplemented);
  }
}

@end
