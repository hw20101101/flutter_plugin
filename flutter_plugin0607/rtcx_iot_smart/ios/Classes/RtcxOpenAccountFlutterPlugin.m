#import "RtcxOpenAccountFlutterPlugin.h"
#import <RTCXOpenAccountCloud/RTCXOpenAccountCloud.h>

@interface RtcxOpenAccountFlutterPlugin ()
@property (nonatomic, strong) FlutterMethodChannel *channel;
@end

@implementation RtcxOpenAccountFlutterPlugin

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    FlutterMethodChannel* channel = [FlutterMethodChannel
                                     methodChannelWithName:@"rtcx_open_account_flutter"
                                     binaryMessenger:[registrar messenger]];
    RtcxOpenAccountFlutterPlugin* instance = [[RtcxOpenAccountFlutterPlugin alloc] init];
    instance.channel = channel;
    [registrar addMethodCallDelegate:instance channel:channel];
    
    // 设置认证异常回调
    [RTCXService(RTCXOpenAccountProtocol) setAuthenticationAbnormalCallback:^(NSInteger code, NSString * _Nonnull message) {
        [instance.channel invokeMethod:@"onAuthenticationAbnormal" arguments:@{
            @"code": @(code),
            @"message": message
        }];
    }];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    if ([@"registerAccount" isEqualToString:call.method]) {
        [self registerAccount:call.arguments result:result];
    } else if ([@"sendValidateCode" isEqualToString:call.method]) {
        [self sendValidateCode:call.arguments result:result];
    } else if ([@"loginAccount" isEqualToString:call.method]) {
        [self loginAccount:call.arguments result:result];
    } else if ([@"resetPassword" isEqualToString:call.method]) {
        [self resetPassword:call.arguments result:result];
    } else if ([@"modifyPassword" isEqualToString:call.method]) {
        [self modifyPassword:call.arguments result:result];
    } else if ([@"refreshToken" isEqualToString:call.method]) {
        [self refreshToken:call.arguments result:result];
    } else if ([@"logout" isEqualToString:call.method]) {
        [self logout:result];
    } else if ([@"logoff" isEqualToString:call.method]) {
        [self logoff:call.arguments result:result];
    } else if ([@"autoLogin" isEqualToString:call.method]) {
        [self autoLogin:result];
    } else if ([@"isLogin" isEqualToString:call.method]) {
        [self isLogin:result];
    } else if ([@"updateUserProfile" isEqualToString:call.method]) {
        [self updateUserProfile:call.arguments result:result];
    } else if ([@"getUserProfile" isEqualToString:call.method]) {
        //[self getUserProfile:result];
    } else {
        result(FlutterMethodNotImplemented);
    }
}

- (void)registerAccount:(NSDictionary *)arguments result:(FlutterResult)result {
    RTCXOpenAccountRegisterReq *req = [[RTCXOpenAccountRegisterReq alloc] init];
    req.accountType = [arguments[@"accountType"] integerValue];
    req.account = arguments[@"account"];
    req.userExtra = arguments[@"userExtra"];
    req.country = arguments[@"country"];
    req.pwdType = [arguments[@"pwdType"] integerValue];
    req.password = arguments[@"password"];
    req.loginName = arguments[@"loginName"];
    req.verifyCode = arguments[@"verifyCode"];
    
    [RTCXService(RTCXOpenAccountProtocol) registerAccountWithReq:req
                                                       onSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)sendValidateCode:(NSDictionary *)arguments result:(FlutterResult)result {
    RTCXOpenAccountValidateCodeParams *params = [[RTCXOpenAccountValidateCodeParams alloc] init];
    params.account = arguments[@"account"];
    params.verifyCodeType = [arguments[@"verifyCodeType"] integerValue];
    params.code = arguments[@"code"];
    
    [RTCXService(RTCXOpenAccountProtocol) sendValidateCodeWithReq:params
                                                        onSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        //result([self convertToFlutterData:data]);
        result(@{@"status": @"success", @"data": data ?: @{}});
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)loginAccount:(NSDictionary *)arguments result:(FlutterResult)result {
    RTCXOpenAccountLoginParams *params = [[RTCXOpenAccountLoginParams alloc] init];
    params.accountType = [arguments[@"accountType"] integerValue];
    params.account = arguments[@"account"];
    params.userExtra = arguments[@"userExtra"];
    params.country = arguments[@"country"];
    params.pwdType = [arguments[@"pwdType"] integerValue];
    params.password = arguments[@"password"];
    params.loginName = arguments[@"loginName"];
    
    [RTCXService(RTCXOpenAccountProtocol) loginAccountWithReq:params
                                                    onSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)resetPassword:(NSDictionary *)arguments result:(FlutterResult)result {
    RTCXOpenAccountResetPwdParams *params = [[RTCXOpenAccountResetPwdParams alloc] init];
    params.account = arguments[@"account"];
    params.password = arguments[@"password"];
    params.verifyCode = arguments[@"verifyCode"];
    
    [RTCXService(RTCXOpenAccountProtocol) resetPasswordWithReq:params
                                                     onSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)modifyPassword:(NSDictionary *)arguments result:(FlutterResult)result {
    RTCXOpenAccountModifyPwdReq *req = [[RTCXOpenAccountModifyPwdReq alloc] init];
    req.oldPassword = arguments[@"oldPassword"];
    req.updatedPassword = arguments[@"updatedPassword"];
    
    [RTCXService(RTCXOpenAccountProtocol) modifyPasswordWithReq:req
                                                      onSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)refreshToken:(NSDictionary *)arguments result:(FlutterResult)result {
    RTCXOpenAccountRefreshTokenReq *req = [[RTCXOpenAccountRefreshTokenReq alloc] init];
    req.refreshToken = arguments[@"refreshToken"];
    
    [RTCXService(RTCXOpenAccountProtocol) refreshTokenWithReq:req
                                                    onSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)logout:(FlutterResult)result {
    [RTCXService(RTCXOpenAccountProtocol) logoutOnSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)logoff:(NSDictionary *)arguments result:(FlutterResult)result {
    RTCXOpenAccountLogoffReq *req = [[RTCXOpenAccountLogoffReq alloc] init];
    req.verifyCode = arguments[@"verifyCode"];
    
    [RTCXService(RTCXOpenAccountProtocol) logoffWithReq:req
                                              onSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)autoLogin:(FlutterResult)result {
    [RTCXService(RTCXOpenAccountProtocol) autoLoginOnSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (void)isLogin:(FlutterResult)result {
    BOOL isLogin = [RTCXService(RTCXOpenAccountProtocol) isLogin];
    result(@(isLogin));
}

- (void)updateUserProfile:(NSDictionary *)arguments result:(FlutterResult)result {
    RTCXUpdateUserProfileReq *req = [[RTCXUpdateUserProfileReq alloc] init];
    req.nickName = arguments[@"nickName"];
    
    NSString *imageDataString = arguments[@"imageData"];
    if (imageDataString) {
        NSData *imageData = [[NSData alloc] initWithBase64EncodedString:imageDataString options:0];
        req.imageData = imageData;
    }
    
    [RTCXService(RTCXOpenAccountProtocol) updateUserProfileWithReq:req
                                                         onSuccess:^(id  _Nullable data, id  _Nullable rawData) {
        result([self convertToFlutterData:data]);
    } onError:^(NSError * _Nullable error) {
        result([FlutterError errorWithCode:[@(error.code) stringValue]
                                   message:error.localizedDescription
                                   details:nil]);
    }];
}

- (id)convertToFlutterData:(id)data {
    //    if (!data) {
    //        return [NSNull null];
    //    }
    
    return [NSNull null];
}

@end
