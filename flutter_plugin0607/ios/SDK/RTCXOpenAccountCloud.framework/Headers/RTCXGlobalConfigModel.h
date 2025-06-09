//
//  RTCXGlobalConfigModel.h
//  RTCXOpenAccountCloud
//
//  Created by Apple on 2024/12/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXGlobalConfigModel : NSObject

@end

@interface RTCXGlobalConfigReq : NSObject
// id描述实体属性内容，必选， 例如 2000:直播时长配置. 如：[@(2000)]
@property (nonatomic, strong) NSArray<NSNumber *> *attributeIdList;
// 最近一次更新的时间，用于差量获取。单位毫秒。可选
@property (nonatomic, strong) NSNumber *lastUpdateTime;
@end

@interface RTCXGlobalConfigRsp : NSObject
// 配置Map
@property (nonatomic, strong) NSDictionary *attributeMap;
// 最后更新时间
@property (nonatomic, assign) NSInteger maxUpdateTimeValue;
@end

@interface RTCXI18NReq : NSObject
// 配置名称列表，不填则获取所有的国际化数据，array[string]，可选
@property (nonatomic, strong) NSArray *keys;
// 最近一次更新的时间，用于差量获取，可选
@property (nonatomic, strong) NSNumber *lastUpdateTime;
@end


@interface RTCXI18NRsp : NSObject
// key
@property (nonatomic, copy) NSString *key;
// value
@property (nonatomic, copy) NSString *value;
@end

@interface RTCXI18NListRsp : NSObject
// 国际化数组<RTCXI18NRsp>
@property (nonatomic, strong) NSArray *list;
// 最后更新时间
@property (nonatomic, assign) NSInteger updateTime;
@end

@interface RTCXGlobalAttrReq : NSObject
// 配置名称列表，array[string]，eg:["countryList"]，获取国家列表，必选
@property (nonatomic, strong) NSArray *keys;
// 最近一次更新的时间，用于差量获取，可选
@property (nonatomic, strong) NSNumber *lastUpdateTime;
@end

@interface RTCXGlobalAttrRsp : NSObject
// key
@property (nonatomic, copy) NSString *key;
// value
@property (nonatomic, copy) NSString *value;
@end

@interface RTCXGlobalAttrListRsp : NSObject
// 国际化数组<RTCXGlobalAttrRsp>
@property (nonatomic, strong) NSArray *list;
// 最后更新时间
@property (nonatomic, assign) NSInteger updateTime;
@end
NS_ASSUME_NONNULL_END
