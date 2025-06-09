//
//  RTCXOpenAccountParams.h
//  RTCXOpenAccountCloud
//
//  Created by Apple on 2024/8/21.
//

#import <Foundation/Foundation.h>


@interface RTCXOpenAccountParams : NSObject

@end

@interface RTCXOpenAccountLoginParams : RTCXOpenAccountParams
// 登录注册的授权类型，比如：1：username用户名，2:mobile手机号码，3：email邮箱，4：一键登录，6：OAuthCode授权码登录 必选
@property (nonatomic, assign) NSInteger accountType;
// 登录注册的授权值，比如：一个具体的手机号码（OAuthCode授权码登录可不填，其他登录方式必填） 可选
@property (nonatomic, copy) NSString *account;
// 登录注册用户的额外信息 可选
@property (nonatomic, copy) NSString *userExtra;
// 国家 如：CN 必选
@property (nonatomic, copy) NSString *country;
// 密码类型：1:密码,2:邮件验证码，3:手机号验证码，4：OAuthCode授权码（password传入OAuthCode） 必选
@property (nonatomic, assign) NSInteger pwdType;
// 密码值：密码、 验证码、OAuthCode授权码 必选
@property (nonatomic, copy) NSString *password;
// 登录名 可选
@property (nonatomic, copy) NSString *loginName;
@end

@interface RTCXOpenAccountValidateCodeParams : RTCXOpenAccountParams
// 邮箱或手机号码 必选
@property (nonatomic, copy) NSString *account;
// 验证码类型，暂时支持 1-登录，2-重置密码，3-注册，4-注销 必选
@property (nonatomic, assign) NSInteger verifyCodeType;
// 邮箱或手机号码国别PhoneCode，account为手机号码且是海外则必填，否则选填。比如：86 可选
@property (nonatomic, copy) NSString *code;
@end

@interface RTCXOpenAccountLogoutParams : RTCXOpenAccountParams

@end

@interface RTCXOpenAccountResetPwdParams : RTCXOpenAccountParams
// 登录注册的授权值，比如：一个具体的手机号码 必选
@property (nonatomic, copy) NSString *account;
// 密码值：密码 必选
@property (nonatomic, copy) NSString *password;
// 手机或邮箱收到的验证码
@property (nonatomic, copy) NSString *verifyCode;
@end

@interface RTCXOpenAccountRegisterReq : RTCXOpenAccountLoginParams
// 手机或邮箱收到的验证码，pwdType为2&3时必填 可选
@property (nonatomic, copy) NSString *verifyCode;
@end

@interface RTCXOpenAccountModifyPwdReq : RTCXOpenAccountParams
// 旧密码 必选
@property (nonatomic, copy) NSString *oldPassword;
// 新密码 必选
@property (nonatomic, copy) NSString *updatedPassword;

@end

@interface RTCXOpenAccountRefreshTokenReq : RTCXOpenAccountParams
// 登录时返回的refreshToken 必选
@property (nonatomic, copy) NSString *refreshToken;

@end

@interface RTCXOpenAccountLogoffReq : RTCXOpenAccountParams
// 手机或邮箱收到的验证码 必选
@property (nonatomic, copy) NSString *verifyCode;

@end

@interface RTCXUpdateUserProfileReq : RTCXOpenAccountParams
// 用户昵称不超过128位 可选
@property (nonatomic, copy) NSString *nickName;
// 用户图像data  可选
// 1.建议尺寸为200x200像素或更大，以确保清晰度; 2.支持的格式：JPEG、PNG、GIF等常见图片格式; 3.头像文件大小一般限制在2MB以内
@property (nonatomic, strong) NSData *imageData;

@end

@interface RTCXUserAccountRsp : RTCXOpenAccountParams
// 账号
@property (nonatomic, copy) NSString *account;
/// 账号类型
@property (nonatomic, assign) NSInteger accountType;

@end

@interface RTCXGetUserProfileRsp : RTCXOpenAccountParams
/// 用户id
@property (nonatomic, assign) NSInteger userId;
/// 租户id
@property (nonatomic, assign) NSInteger tenantId;
// 用户昵称
@property (nonatomic, copy) NSString *loginName;
// 用户头像url
@property (nonatomic,copy) NSString *avatarUrl;
// 用户头像地址
@property (nonatomic,copy) NSString *imageUrl;
/// 语言
@property (nonatomic, copy) NSString *language;
/// 账号列表
@property (nonatomic, strong) NSArray<RTCXUserAccountRsp*> *userAccountList;

@end
