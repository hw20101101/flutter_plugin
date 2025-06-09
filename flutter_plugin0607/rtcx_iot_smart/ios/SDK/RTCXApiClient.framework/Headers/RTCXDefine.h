//
//  RTCXDefine.h
//  RTCXApiClient
//
//  Created by Apple on 2024/8/14.
//

#ifndef RTCXDefine_h
#define RTCXDefine_h

@class RTCXResponse;

/**
 请求响应回调
 
 @param error 错误对象，所有无法通过服务端响应的错误都通过该 error 抛出，如，网络错误，host 不可到达
 @param response 服务端响应对象
 */
typedef void(^RTCXResponseHandler)(NSError * _Nullable error, RTCXResponse * _Nullable response);

typedef void (^_Nonnull RTCXHttpTaskCompletionHandler)(BOOL isSucceeded, id _Nullable response, NSError *_Nullable error);
#endif /* RTCXDefine_h */
