//
//  IOTAccountInfoCenter.h
//  XSIOTSDK
//
//  Created by Apple on 2024/8/20.
//

#import <Foundation/Foundation.h>
@class IOTAccountInfo;

NS_ASSUME_NONNULL_BEGIN

extern NSString * _Nullable const IoT_AccountInfoCenterGateNotification;// 登入，登出通知

extern NSString *const IoT_AccountInfoCenterGateLoginErrorNotification;

@interface IOTAccountInfoCenter : NSObject

@property (nonatomic, readwrite, assign) NSInteger tenantId;
@property (nonatomic, readwrite, copy) NSString *appKey;
@property (nonatomic, readwrite, assign) NSInteger userId;
@property (nonatomic, readwrite, copy) NSString *accessToken;
@property (nonatomic, readwrite, assign) NSTimeInterval accessTokenCreateTime;
@property (nonatomic, readwrite, assign) NSTimeInterval accessTokenExpireTime;
@property (nonatomic, readwrite, copy) NSString *refreshToken;
@property (nonatomic, readwrite, assign) NSTimeInterval expireTime;
@property (nonatomic, readwrite, copy) NSString *account;
@property (nonatomic, readwrite, copy) NSString *userName;

+ (instancetype)sharedInstance;
/**
  是否登录
 */
- (BOOL)isLogin;

- (void)loginError;

-(void)setAccountInfoWith:(IOTAccountInfo *)accountInfo;

- (void)clearAccountInfo;

@end

NS_ASSUME_NONNULL_END
