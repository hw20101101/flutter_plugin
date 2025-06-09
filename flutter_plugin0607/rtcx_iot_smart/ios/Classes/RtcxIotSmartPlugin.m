#import "RtcxIotSmartPlugin.h"
#import <RTCXIotSmart/RTCXIotSmart.h>

// 导入日志SDK头文件
#import <RTCXLog/RTCXLog.h>

// 导入账号管理SDK头文件
#import <RTCXOpenAccountCloud/RTCXOpenAccountCloud.h>

#import "RtcxOpenAccountFlutterPlugin.h"

@interface RtcxIotSmartPlugin()
@property (nonatomic, strong) FlutterMethodChannel *channel;
@end

@implementation RtcxIotSmartPlugin

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    FlutterMethodChannel* channel = [FlutterMethodChannel
                                   methodChannelWithName:@"rtcx_iot_smart"
                                         binaryMessenger:[registrar messenger]];
    RtcxIotSmartPlugin* instance = [[RtcxIotSmartPlugin alloc] init];
    instance.channel = channel;
    [registrar addMethodCallDelegate:instance channel:channel];
    
    // 注册其他 SDK 插件
    [RtcxOpenAccountFlutterPlugin registerWithRegistrar:registrar];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    if ([@"initialize" isEqualToString:call.method]) {
        [self handleInitialize:call result:result];
    } else if ([@"setDebug" isEqualToString:call.method]) {
        [self handleSetDebug:call result:result];
    } else if ([@"getCurrentSDKVersion" isEqualToString:call.method]) {
        result([RTCXIotSmart getCurrentSDKVersion]);
    } else if ([@"sdkInitializationCompleted" isEqualToString:call.method]) {
        result(@([[RTCXIotSmart sharedInstance] sdkInitializationCompleted]));
    } else if ([@"setLanguage" isEqualToString:call.method]) {
        [self handleSetLanguage:call result:result];
    } else if ([@"getLanguage" isEqualToString:call.method]) {
        result([[RTCXIotSmart sharedInstance] getLanguage]);
    } else if ([@"setCountry" isEqualToString:call.method]) {
        [self handleSetCountry:call result:result];
    } else if ([@"getCountryList" isEqualToString:call.method]) {
        [self handleGetCountryListWithResult:result];
    } else if ([@"getCountry" isEqualToString:call.method]) {
        [self handleGetCountryWithResult:result];
    } else {
        result(FlutterMethodNotImplemented);
    }
}

- (void)handleInitialize:(FlutterMethodCall*)call result:(FlutterResult)result {
    NSDictionary *args = call.arguments;
    NSString *appKey = args[@"appKey"];
    NSString *appSecret = args[@"appSecret"];
    NSNumber *appTypeIndex = args[@"appType"];
    NSNumber *regionTypeIndex = args[@"regionType"];
    
    if (!appKey || !appSecret || !appTypeIndex || !regionTypeIndex) {
        result([FlutterError errorWithCode:@"INVALID_ARGUMENTS"
                                   message:@"Invalid arguments for initialize"
                                   details:nil]);
        return;
    }
    
    // 用户鉴权失效监听
    [RTCXService(RTCXOpenAccountProtocol) setAuthenticationAbnormalCallback:^(NSInteger code, NSString * _Nonnull message) {
        if (code == 30314) {// token失效
            NSLog(@"-->> token失效");
        }
    }];
    
    RTCXIotSmartConfig *config = [RTCXIotSmartConfig new];
    config.appKey = appKey;
    config.appSecret = appSecret;
//    config.appType = (RTCXAppType)[appTypeIndex integerValue];
//    config.regionType = (RTCXRegionType)[regionTypeIndex integerValue];
    [RTCXIotSmart sharedInstance].config = config;
    
    // 设置初始化完成回调
    __weak typeof(self) weakSelf = self;
    [RTCXIotSmart sharedInstance].sdkInitCompletedCallback = ^{
        NSLog(@"-->> oc sdkInitCompletedCallback");
        __strong typeof(weakSelf) strongSelf = weakSelf;
        if (strongSelf) {
            [strongSelf.channel invokeMethod:@"sdkInitCompleted" arguments:nil];
        }
    };
    
    result(nil);
}

- (void)handleSetDebug:(FlutterMethodCall*)call result:(FlutterResult)result {
    NSDictionary *args = call.arguments;
    NSNumber *debugValue = args[@"debug"];
    
    if (!debugValue) {
        result([FlutterError errorWithCode:@"INVALID_ARGUMENTS"
                                   message:@"Invalid arguments for setDebug"
                                   details:nil]);
        return;
    }
    
    [[RTCXIotSmart sharedInstance] setDebug:[debugValue boolValue]];
    result(nil);
}

- (void)handleSetLanguage:(FlutterMethodCall*)call result:(FlutterResult)result {
    NSDictionary *args = call.arguments;
    NSString *language = args[@"language"];
    
    if (!language) {
        result([FlutterError errorWithCode:@"INVALID_ARGUMENTS"
                                   message:@"Invalid arguments for setLanguage"
                                   details:nil]);
        return;
    }
    
    [[RTCXIotSmart sharedInstance] setLanguage:language];
    result(nil);
}

- (void)handleSetCountry:(FlutterMethodCall*)call result:(FlutterResult)result {
    NSDictionary *args = call.arguments;
    NSString *areaName = args[@"areaName"];
    NSString *code = args[@"code"];
    NSString *pinyin = args[@"pinyin"];
    NSString *isoCode = args[@"isoCode"];
    
    if (!areaName || !code || !pinyin || !isoCode) {
        result([FlutterError errorWithCode:@"INVALID_ARGUMENTS"
                                   message:@"Invalid arguments for setCountry"
                                   details:nil]);
        return;
    }
    
    RTCXIotCountry *country = [[RTCXIotCountry alloc] init];
    country.areaName = areaName;
    country.code = code;
    country.pinyin = pinyin;
    country.isoCode = isoCode;
    country.domainAbbreviation = args[@"domainAbbreviation"];
    
    __weak typeof(self) weakSelf = self;
    [[RTCXIotSmart sharedInstance] setCountry:country callback:^(NSError * _Nullable error, RTCXIotCountry * _Nullable resultCountry) {
        __strong typeof(weakSelf) strongSelf = weakSelf;
        if (!strongSelf) return;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            if (error) {
                result([FlutterError errorWithCode:@"SET_COUNTRY_ERROR"
                                           message:error.localizedDescription
                                           details:nil]);
            } else if (resultCountry) {
                result([strongSelf countryToMap:resultCountry]);
            } else {
                result(nil);
            }
        });
    }];
}

- (void)handleGetCountryListWithResult:(FlutterResult)result {
    NSArray<RTCXIotCountry *> *countries = [[RTCXIotSmart sharedInstance] getCountryList];
    NSMutableArray *countryMaps = [[NSMutableArray alloc] init];
    
    for (RTCXIotCountry *country in countries) {
        [countryMaps addObject:[self countryToMap:country]];
    }
    
    result(countryMaps);
}

- (void)handleGetCountryWithResult:(FlutterResult)result {
    RTCXIotCountry *country = [[RTCXIotSmart sharedInstance] getCountry];
    if (country) {
        result([self countryToMap:country]);
    } else {
        result(nil);
    }
}

- (NSDictionary *)countryToMap:(RTCXIotCountry *)country {
    NSMutableDictionary *map = [[NSMutableDictionary alloc] init];
    map[@"areaName"] = country.areaName ?: [NSNull null];
    map[@"code"] = country.code ?: [NSNull null];
    map[@"pinyin"] = country.pinyin ?: [NSNull null];
    map[@"isoCode"] = country.isoCode ?: [NSNull null];
    map[@"domainAbbreviation"] = country.domainAbbreviation ?: [NSNull null];
    return [map copy];
}

@end
