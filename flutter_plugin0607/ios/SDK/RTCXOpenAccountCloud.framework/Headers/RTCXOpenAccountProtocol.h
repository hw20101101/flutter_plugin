//
//  RTCXOpenAccountProtocol.h
//  RTCXOpenAccountCloud
//
//  Created by Apple on 2024/8/21.
//

#import <Foundation/Foundation.h>
#import <RTCXOpenAccountCloud/RTCXOpenAccountParams.h>

typedef void (^RTCXOpenAccountOnSuccess)(id _Nullable data, id _Nullable rawData);;
typedef void (^RTCXOpenAccountOnError)(NSError * _Nullable error);

typedef void (^RTCXAuthenticationAbnormalCallback)(NSInteger code, NSString * _Nonnull message);

@protocol RTCXOpenAccountProtocol <NSObject>
/**
 *  通过手机验号、邮件 注册
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)registerAccountWithReq:(nonnull RTCXOpenAccountRegisterReq *)req onSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  发送验证码
 *
 *  @param requestParams        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)sendValidateCodeWithReq:(nonnull RTCXOpenAccountValidateCodeParams *)requestParams onSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  通过账号密码、手机验证码、OAuthCode授权码 登录
 *
 *  @param requestParams        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)loginAccountWithReq:(nonnull RTCXOpenAccountLoginParams *)requestParams onSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  重置密码
 *
 *  @param requestParams        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)resetPasswordWithReq:(nonnull RTCXOpenAccountResetPwdParams *)requestParams onSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  修改密码
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)modifyPasswordWithReq:(nonnull RTCXOpenAccountModifyPwdReq *)req onSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  刷新Token
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)refreshTokenWithReq:(nullable RTCXOpenAccountRefreshTokenReq *)req onSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  退出登录
 *
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)logoutOnSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  用户注销
 *
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)logoffWithReq:(nullable RTCXOpenAccountLogoffReq *)req onSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  自动登录
 *
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)autoLoginOnSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  是否登录
 *
 *  @return 是否登录
 */
- (BOOL)isLogin;

/**
 *  用户鉴权异常回调，如： code == 30314，token失效
 *
 */
- (void)setAuthenticationAbnormalCallback:(nullable RTCXAuthenticationAbnormalCallback)abnormalCallback;
/**
 *  更新昵称和头像
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)updateUserProfileWithReq:(nullable RTCXUpdateUserProfileReq *)req onSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
/**
 *  获取用户信息(包括昵称和图像)
 *
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getUserProfileOnSuccess:(nullable RTCXOpenAccountOnSuccess)onSuccess onError:(nullable RTCXOpenAccountOnError)onError;
@end


