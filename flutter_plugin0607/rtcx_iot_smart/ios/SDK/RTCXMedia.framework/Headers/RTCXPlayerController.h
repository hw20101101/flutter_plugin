//
//  RTCXPlayerController.h
//  LinkvisualMedia
//
//  Created by Apple on 2024/8/26.
//

#import <Foundation/Foundation.h>
#import <RTCXMedia/RTCXPlayerDelegate.h>
#import <RTCXMedia/RTCXPlayerDataSource.h>
#import <RTCXMedia/RTCXPlayerInterface.h>

NS_ASSUME_NONNULL_BEGIN
@protocol  RTCXPlayerViewDataSource;
@interface RTCXPlayerController : NSObject<RTCXPlayerInterface>

@property (nonatomic, weak) id <RTCXPlayerDelegate> delegate;
@property (nonatomic, weak) id <RTCXPlayerDataSource> dataSource;

/**
 初始化PlayerController，SDK内部已调用此方法初始化，App不需要调用
 */
- (id)initPlayerController:(UIView *)playerLayer observer:(id<RTCXPlayerViewDataSource>)observer;

@end

NS_ASSUME_NONNULL_END
