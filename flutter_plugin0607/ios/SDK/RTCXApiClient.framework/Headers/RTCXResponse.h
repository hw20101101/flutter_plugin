//
//  RTCXResponse.h
//  RTCXApiClient
//
//  Created by Apple on 2024/8/14.
//

#import <Foundation/Foundation.h>
#import <RTCXApiClient/RTCXRequest.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXResponse : NSObject

- (NSInteger)code;                          ///< 服务器返回的 code，其中 200 为成功，其他情况为失败
- (id _Nullable)data;                       ///< 服务器返回 json 的 data 字段
- (NSString * _Nullable)message;            ///< 服务器返回的错误原因详情，可用于开发排查问题
- (NSString * _Nullable)localizedMsg;       ///< 服务器返回的用户可读的错误信息

// 下面的方法仅用于 Debug 用途
- (RTCXRequest * _Nonnull)request;           ///< 该响应对应的请求对象
- (id _Nullable)rawData;                    ///< 服务器应答的原始报文

@end

NS_ASSUME_NONNULL_END
