//
//  Utility.h
//  XSIOTSDK
//
//  Created by Apple on 2024/8/15.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
#import <SystemConfiguration/CaptiveNetwork.h>
#import <CommonCrypto/CommonCryptor.h>


#define DegreesToRadians(x) (M_PI * (x) / 180.0)
#define IOS8_DEVICE_VERSION ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8)

#if __has_feature(objc_arc)
#define AS_AUTORELEASE(exp) exp
#define AS_RELEASE(exp) exp
#define AS_SAFE_RELEASE(exp) do{exp = nil;} while(0)
#define AS_RETAIN(exp) exp
#else
#define AS_AUTORELEASE(exp) [exp autorelease]
#define AS_RELEASE(exp) [exp release]
#define AS_SAFE_RELEASE(exp) do{[exp release]; exp=nil;} while(0)
#define AS_RETAIN(exp) [exp retain]
#endif

NS_ASSUME_NONNULL_BEGIN

@interface NSData (Base64)

+ (NSData *)dataWithBase64EncodedString:(NSString *)string;
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;
- (NSString *)base64EncodedString;

@end

@interface NSData (NSDataExtensions)

- (BOOL) appendToFile: (NSString *) path atomically: (BOOL) flag;
- (NSString *)base64Encoded;
+ (NSData *)decompressZlibData:(NSData *)compressedData;
@end

@interface NSString (NSStringExtensions)

- (BOOL)contains:(NSString *)aString;
@end

@interface NSString (VideoTitleKeySort)

- (NSComparisonResult)customVideoTitleKeySort:(NSString *)arrayToCompare;

@end

@interface NSString (VideoDateKeySort)

- (NSComparisonResult)customVideoDateKeySort:(NSString *)arrayToCompare;

@end

@interface NSString (Base64)

+ (NSString *)stringWithBase64EncodedString:(NSString *)string;
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;
- (NSString *)base64EncodedString;
- (NSString *)base64DecodedString;
- (NSData *)base64DecodedData;
- (NSString *)base64DecodedAfterMD5;
- (NSString*)MD5;
- (NSString *)MD5LowercaseStr;
@end

@interface NSString (Smartlink)

// 加解密, 用在二维码、smartlink
+ (NSString *)strEncrypt:(NSString *)string;
+ (NSString *)deStrEncrypt:(NSString *)string;

// json 转 string
+ (NSString *)jsonStringWithObject:(id)jsonObject;
/// 十进制转十六进制
+ (NSString *)getHexByDecimal:(NSInteger)decimal;
/// 十六进制转十进制
+ (NSString *)getDecimalByHex:(NSString *)hex;

@end


@interface NSDate (convert)

- (NSString *)stringWithFormat:(NSString *)dateformat timeZone:(NSString *)timeZone;

@end

@interface Utility : NSObject

+ (NSString *)getCurrentUniqueIdentifier;

+ (NSString *)networkType;

+ (NSString *)userAgent;

+ (NSString *)calculateRequestId;

+ (NSString *)uuidString;

+ (BOOL)supportHardwareDecoder;

+ (BOOL)Is24HourFormat;

+ (NSString *)platformString;

+ (NSDictionary *)fetchSSIDInfo;
// 获取当前语言
+ (NSString *)getCurrentLanguage:(BOOL)bUpcase;
// 获取系统语言
+(NSString *)getCurrentSysLang:(BOOL)bUpcase;

+ (NSString *)standardSystemLanguageCode;
@end

NS_ASSUME_NONNULL_END
