//
//  RTCXRequestPayload.h
//  RTCXApiClient
//
//  Created by Apple on 2024/8/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*
 IoT 请求协议 payload，目前是 json 格式，详细如下：
 {
     "id": "123",
     "version": "1.0",
     "request": {
        "appKey"："",
        "apiVer": "",
        "iotToken": "" //可选，如需 IoT 统一身份鉴权时填写
     },
     "params": {
        // biz parameters
     }
 }
 */
@interface RTCXRequestPayload : NSObject

@property (nonatomic, strong, nonnull) NSDictionary *request;
@property (nonatomic, strong, nonnull) NSDictionary *params;

@property (nonatomic, copy, readonly, nonnull) NSString *requestId;
@property (nonatomic, copy, readonly, nonnull) NSString *version;

@property (nonatomic, copy, readonly, nonnull) NSString *requestPath;

- (instancetype _Nonnull)initWithRequestId:(NSString * _Nonnull)requestId version:(NSString * _Nonnull)version requestPath:(NSString * _Nonnull)requestPath;

@end

NS_ASSUME_NONNULL_END
