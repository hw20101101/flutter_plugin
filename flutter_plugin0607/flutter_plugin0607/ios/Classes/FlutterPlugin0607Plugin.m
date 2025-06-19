#import "FlutterPlugin0607Plugin.h"
#import "WXApi.h"

@implementation FlutterPlugin0607Plugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
 
  FlutterMethodChannel* channel = [FlutterMethodChannel
      methodChannelWithName:@"flutter_plugin0607"
            binaryMessenger:[registrar messenger]];
  FlutterPlugin0607Plugin* instance = [[FlutterPlugin0607Plugin alloc] init];
  [registrar addMethodCallDelegate:instance channel:channel];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
  if ([@"getPlatformVersion" isEqualToString:call.method]) {
    result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
  } else if ([@"initWechatSDK" isEqualToString:call.method]) {
    [self initWechatSDK];
  } else {
    result(FlutterMethodNotImplemented);
  }
}

- (void)initWechatSDK {
 
    NSString *ver = [WXApi getApiVersion];
    NSString *url = [WXApi getWXAppInstallUrl];
    NSLog(@"-->> WXApi ver:%@ - url:%@", ver, url); 
}

@end
