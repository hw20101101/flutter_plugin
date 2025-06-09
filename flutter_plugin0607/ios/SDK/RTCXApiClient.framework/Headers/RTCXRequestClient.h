//
//  RTCXRequestClient.h
//  RTCXApiClient
//
//  Created by Apple on 2024/8/14.
//

#import <Foundation/Foundation.h>
#import <RTCXApiClient/RTCXDefine.h>
#import <RTCXApiClient/RTCXRequest.h>
#import <RTCXApiClient/RTCXAuthenticationDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXRequestClient : NSObject

/**
 注册 API 请求的认证处理 Delegate
 
 @param delegate 认证处理 delegate
 @param authType 认证类型
 */
+ (void)registerDelegate:(id<RTCXAuthenticationDelegate>)delegate forAuthenticationType:(NSString *)authType;

/**
 异步发送请求，响应会通过主线程回调
 
 @param request 请求对象
 @param responseHandler 响应回调
 */
+ (void)asyncSendRequest:(RTCXRequest *)request responseHandler:(RTCXResponseHandler)responseHandler;

+ (void)asyncSendUploadFileRequest:(NSString *)url fileData:(NSData *)data fileName:(NSString *)fileName completion:(RTCXHttpTaskCompletionHandler)completion;
@end

NS_ASSUME_NONNULL_END
