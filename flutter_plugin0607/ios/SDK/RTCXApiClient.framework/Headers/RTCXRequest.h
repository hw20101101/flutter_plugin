//
//  RTCXRequest.h
//  RTCXApiClient
//
//  Created by Apple on 2024/8/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXRequest : NSObject

@property (nonatomic, copy, readonly) NSString *requestId;        ///< API 请求的消息标示，可用于问题排查

@property (nonatomic, copy, readonly) NSString *host;         ///< API 请求的域名
@property (nonatomic, copy, readonly) NSString *apiVersion;   ///< API 版本
@property (nonatomic, strong, readonly) NSDictionary *params; ///< API 参数
@property (nonatomic, assign, readonly) NSUInteger timeoutInterval; ///< 请求超时时间，单位为秒
@property (nonatomic, assign, readonly) NSString *iotToken; ///< 请求iotToken

- (void)refreshRequestToken;
@end

NS_ASSUME_NONNULL_END
