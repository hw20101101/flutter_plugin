//
//  RTCXDeviceMgrReq.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/21.
//

#import <Foundation/Foundation.h>

@interface RTCXDeviceMgrReq : NSObject

@end

@interface RTCXQueryDeviceListReq : RTCXDeviceMgrReq
// 当前页码，从1开始 必选
@property (nonatomic, assign) NSInteger pageNo;
// 分页大小，大于等于1，小于等于100 必选
@property (nonatomic, assign) NSInteger pageSize;
// 绑定类型。取值为：0（表示被分享的设备）；1（表示拥有的设备）；null（表示所有的设备）可选
@property (nonatomic, copy) NSString *owned;
// 分组id，可按照分组id过滤列表 可选
@property (nonatomic, strong) NSNumber *groupId;
// 是否为子设备，true（表示获取子设备列表），false（表示获取直连设备列表）可选
@property (nonatomic, assign) BOOL isSubDevice;

@end

@interface RTCXQuerySubDeviceListReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符（网关设备的iotId） 必选
@property (nonatomic, copy) NSString *iotId;
// 当前页码，从1开始 必选
@property (nonatomic, assign) NSInteger pageNo;
// 分页大小，大于等于1，小于等于100 必选
@property (nonatomic, assign) NSInteger pageSize;
// 分组id，可按照分组id过滤列表 可选
@property (nonatomic, strong) NSNumber *groupId;

@end

@interface RTCXBindTokenReq : RTCXDeviceMgrReq
// 额外信息 可选
@property (nonatomic, copy) NSString *extra;

@end

@interface RTCXDeviceBindReq : RTCXDeviceMgrReq
// 设备型号 如：xLeWcoelZbyOePbJludl 必选
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002 必选
@property (nonatomic, copy) NSString *deviceName;
// /client/living/awss/token/create接口获取该 Token 必选
@property (nonatomic, copy) NSString *token;
// 业务来源 可选
@property (nonatomic, copy) NSString *origin;

@end

@interface RTCXDeviceUnbindReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;

@end

@interface RTCXDeviceNickdNameSetReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 设备的昵称或别名。
@property (nonatomic, copy) NSString *nickName;

@end

@interface RTCXDeviceQuickBindReq : RTCXDeviceMgrReq
// 设备型号 如：xLeWcoelZbyOePbJludl 必选
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002 必选
@property (nonatomic, copy) NSString *deviceName;
// 业务来源 可选
@property (nonatomic, copy) NSString *origin;

@end

@interface RTCXDeviceQrcodeQuickBindReq : NSObject
// 设备型号 如：xLeWcoelZbyOePbJludl 必选
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002 必选
@property (nonatomic, copy) NSString *deviceName;
// 业务来源,例如：demoApp 可选
@property (nonatomic, copy) NSString *origin;

@end

/** 检查设备绑定状态 */
@interface RTCXDeviceBindStatusReq : RTCXDeviceMgrReq
// 设备型号 如：xLeWcoelZbyOePbJludl 必选
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002 必选
@property (nonatomic, copy) NSString *deviceName;
// TraceId 可选
@property (nonatomic, copy) NSString *bindTraceId;
@end

@interface RTCXFirmwareUpdateCheckReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 设备子模块的名称，控制台的OTA固件上传界面，在操作固件上传时输入的子模块名称。入参为空时，则表示获取默认的default模块 可选
@property (nonatomic, copy) NSString *moduleName;
// 语言，默认zh_CN 可选
@property (nonatomic, copy) NSString *language;

@end 

@interface RTCXFirmwareUpdateReq : RTCXDeviceMgrReq
// 存放设备iotId的数组，一次最多允许操作20个设备。如：[{"iotId":"iotId_1"},{"iotId":"iotId_2"}] 必选
@property (nonatomic, strong) NSArray<NSDictionary *> *devices;

@end

@interface RTCXFirmwareUpdateProgressReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 设备子模块的名称，控制台的OTA固件上传界面，在操作固件上传时输入的子模块名称。入参为空时，则表示获取默认的default模块 可选
@property (nonatomic, copy) NSString *moduleName;

@end

@interface RTCXGeneralShareQrcodeReq : RTCXDeviceMgrReq
// 要分享的设备列表。一次最多20 必选
@property (nonatomic, strong) NSArray<NSString *> *iotIdList;
// 权限列表，live：直播，control：设备控制，record：录像回看，ptz：云台控制，voiceIntercom：语音对讲，setting：高级设置，notification：消息通知 必选
@property (nonatomic, strong) NSArray<NSString *> *permissionList;

@end

@interface RTCXScanShareQrCodeBindReq : RTCXDeviceMgrReq
// 设备的唯一标识符列表 必选
@property (nonatomic, copy) NSString *qrKey;

@end

@interface RTCXDeviceShareReq : RTCXDeviceMgrReq
// 要分享的设备列表。一次最多20 必选
@property (nonatomic, strong) NSArray<NSString *> *iotIdList;
// 目标用户唯一属性的类型。MOBILE（表示手机号）；EMAIL（表示邮箱）。 必选
@property (nonatomic, copy) NSString *accountAttr;
// 唯一标识目标用户的属性类型（如：手机号、邮箱等），手机号："MOBILE"，邮箱："EMAIL"。 必选
@property (nonatomic, copy) NSString *accountAttrType;
// 手机号的区位码。 可选
@property (nonatomic, copy) NSString *mobileLocationCode;
// 权限列表，live：直播，control：设备控制，record：录像回看，ptz：云台控制，voiceIntercom：语音对讲，setting：高级设置，notification：消息通知 必选
@property (nonatomic, strong) NSArray<NSString *> *permissionList;
@end

@interface RTCXDeviceShareNoticeListReq : RTCXDeviceMgrReq
/// 当前页码，从1开始  必选
@property (nonatomic, assign) NSInteger pageNo;
// 页大小，单页item的数量上限，最大值为200 必选
@property (nonatomic, assign) NSInteger pageSize;
// 是否按照批次的方式来获取通知列表，默认是NONE。可取值为：NONE（表示不作 groupBy 处理）；BATCH（表示同一批次的分享只会有一条通知）。 必选
@property (nonatomic, copy) NSString *groupBy;
@end

@interface RTCXConfirmShareReq : RTCXDeviceMgrReq
// 分享记录列表， 和batchId必填一个 必选
@property (nonatomic, strong) NSArray<NSString *> *recordIdList;
// 批次id， 和recordIdList 必填一个 可选
@property (nonatomic, copy) NSString *batchId;
// 0（表示不同意）；1（表示同意）。 必选
@property (nonatomic, assign) NSInteger agree;
@end

@interface RTCXCancelShareReq : RTCXDeviceMgrReq
// 分享记录列表， 和batchId必填一个 必选
@property (nonatomic, strong) NSArray<NSString *> *recordIdList;
@end

@interface RTCXDeviceShareRecordReq : RTCXDeviceMgrReq
/// 当前页码，从1开始  必选
@property (nonatomic, assign) NSInteger pageNo;
// 页大小，单页item的数量上限，最大值为200 必选
@property (nonatomic, assign) NSInteger pageSize;
// 是否按照批次的方式来获取通知列表，默认是NONE。可取值为：NONE（表示不作 groupBy 处理）；BATCH（表示同一批次的分享只会有一条通知) 必选
@property (nonatomic, assign) NSInteger batchId;
@end

@interface RTCXSetPermissionListReq : RTCXDeviceMgrReq
/// 分享记录id  必选
@property (nonatomic, assign) NSInteger recordId;
// 权限列表，live：直播，control：设备控制，record：录像回看，ptz：云台控制，voiceIntercom：语音对讲，setting：高级设置，notification：消息通知 必选
@property (nonatomic, strong) NSArray<NSString *> *permissionList;
@end

@interface RTCXDeviceShareUserListReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
/// 当前页码，从1开始  必选
@property (nonatomic, assign) NSInteger pageNo;
// 页大小，单页item的数量上限，最大值为200 必选
@property (nonatomic, assign) NSInteger pageSize;
@end

@interface RTCXGroupCreatReq : RTCXDeviceMgrReq
// 设备组的名称 必选
@property (nonatomic, copy) NSString *name;
// 待添加到设备组内的设备ID列表 可选
@property (nonatomic, strong) NSArray<NSString *> *iotIdList;
@end

@interface RTCXGroupDeleteReq : RTCXDeviceMgrReq
// 设备组的id 必选
@property (nonatomic, assign) NSInteger groupId;
@end

@interface RTCXGroupUpdateReq : RTCXDeviceMgrReq
// 设备组的名称 必选
@property (nonatomic, copy) NSString *name;
// 设备组的id 必选
@property (nonatomic, assign) NSInteger groupId;
@end

@interface RTCXGroupListReq : RTCXDeviceMgrReq
/// 当前页码，从1开始  必选
@property (nonatomic, assign) NSInteger pageNo;
// 分页大小，取值范围：1~20 必选
@property (nonatomic, assign) NSInteger pageSize;
@end

@interface RTCXGroupAddDeviceReq : RTCXDeviceMgrReq
// 设备组的id 必选
@property (nonatomic, assign) NSInteger groupId;
// 待添加到设备组内的设备ID列表 必选
@property (nonatomic, strong) NSArray<NSString *> *iotIdList;
@end

@interface RTCXGroupDeleteDeviceReq : RTCXDeviceMgrReq
// 设备组的id 必选
@property (nonatomic, assign) NSInteger groupId;
// 待添加到设备组内的设备ID列表 必选
@property (nonatomic, strong) NSArray<NSString *> *iotIdList;
@end

@interface RTCXDeviceShareCountListReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符，如果填了，只查询这一个数据， 可选
@property (nonatomic, copy) NSString *iotId;
/// 当前页码，从1开始  必选
@property (nonatomic, assign) NSInteger pageNo;
// 页大小，单页item的数量上限，最大值为200 必选
@property (nonatomic, assign) NSInteger pageSize;
@end

@interface RTCXGetDeviceConfigReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// id描述实体属性内容，例如 1000:直播策略. 如：[@(1000)]，必选
@property (nonatomic, strong) NSArray<NSNumber *> *attributeIdList;
// 最近一次更新的时间，用于差量获取。单位毫秒。可选
@property (nonatomic, strong) NSNumber *lastUpdateTime;
// 实体类型， 默认0，0：设备维度类型，2：用户设备类型, 可选
@property (nonatomic, strong) NSNumber *entityType;
@end

@interface RTCXSetDeviceConfigReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// id描述实体属性内容， 例如 1003:控制设备推送schedule. 如：[{"id":"1000","value":"xxx"}}]，必选
@property (nonatomic, strong) NSArray<NSDictionary *> *attributeList;
// 实体类型， 默认0，0：设备维度类型，2：用户设备类型, 可选
@property (nonatomic, strong) NSNumber *entityType;
@end

@interface RTCXSavePtzPresetPositionReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 预置位名称 可选
@property (nonatomic, copy) NSString *name;
// 预置位坐标信息，必选
@property (nonatomic, strong) NSString *ptz;
// 预置位缩略图data
@property (nonatomic, strong) NSData *imageData;

@end

@interface RTCXGetPtzPresetPositionListReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 是否禁止请求预置位的url地址，默认不禁止， 可选
@property (nonatomic, assign) BOOL forbitLoadImageUrl;

@end

@interface RTCXDeletePtzPresetPositionReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 预置位ID, 必选
@property (nonatomic, copy) NSString *picId;

@end

@interface RTCXUpdatePtzPresetPositionReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 预置位ID, 必选
@property (nonatomic, copy) NSString *picId;
// 预置位名称 必选
@property (nonatomic, copy) NSString *name;
@end

@interface RTCXWakeupDeviceReq : RTCXDeviceMgrReq
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
@end

