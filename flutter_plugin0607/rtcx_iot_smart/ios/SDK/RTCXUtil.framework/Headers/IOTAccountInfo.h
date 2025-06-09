//
//  IOTAccountInfo.h
//  XSIOTSDK
//
//  Created by Apple on 2024/8/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol IotAccountInfo <NSObject>
/// 租户id
@property (nonatomic, assign) NSInteger tenantId;
/// appKey
@property (nonatomic, copy) NSString *appKey;
/// 用户id
@property (nonatomic, assign) NSInteger userId;
/// 用户accessToken
@property (nonatomic, copy) NSString *accessToken;
/// accessToken创建时间
@property (nonatomic, assign) NSTimeInterval accessTokenCreateTime;
/// accessToken过期时间
@property (nonatomic, assign) NSTimeInterval accessTokenExpireTime;
/// refreshToken，jwt格式，用于后续的token刷新接口
@property (nonatomic, copy) NSString *refreshToken;
/// accessToken的过期秒数
@property (nonatomic, assign) NSTimeInterval expireTime;
///  账号
@property (nonatomic, copy) NSString *account;
///  用户名
@property (nonatomic, copy) NSString *userName;
///  0：不切换region，1：切换region到对应的数据中心
@property (nonatomic, assign) NSInteger changeRegion;
///  新数据中心id
@property (nonatomic, assign) NSInteger regionId;
/// 新数据中心网关域名
@property (nonatomic, copy) NSString *regionGatewayDomain;
/// 新数据中心网关协议， https
@property (nonatomic, copy) NSString *regionGatewayProtocol;
@end

@interface IOTAccountInfo : NSObject<IotAccountInfo>

@end

NS_ASSUME_NONNULL_END
