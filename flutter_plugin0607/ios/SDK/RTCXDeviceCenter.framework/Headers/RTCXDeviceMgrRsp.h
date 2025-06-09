//
//  RTCXDeviceMgrRsp.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/21.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXCloudServicesModel.h>

@interface RTCXDeviceMgrRsp : NSObject

@end

@interface RTCXDeviceInfo : RTCXDeviceMgrRsp
// 绑定设备的时间
@property (nonatomic, assign) NSInteger gmtModified;
// 创建时间
@property (nonatomic, assign) NSInteger gmtCreate;
// 产品下设备的联网方式，可取值：NET_LORA（表示LoRa）；NET_CELLULAR（表示2G/3G/4G/5G蜂窝网）；NET_WIFI（表示Wi-Fi）；NET_ZIGBEE（表示ZigBee）；NET_ETHERNET（表示以太网）；NET_OTHER（表示其他网络类型）。
@property (nonatomic, copy) NSString *netType;
// 设备型号 如：xLeWcoelZbyOePbJludl
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002
@property (nonatomic, copy) NSString *deviceName;
// 平台为设备颁发的ID，设备的唯一标识符
@property (nonatomic, copy) NSString *iotId;
// 设备的昵称
@property (nonatomic, copy) NSString *nickName;
// 用户的身份ID
@property (nonatomic, assign) NSInteger identityId;
// 设备和用户的关系，可取值：0（表示分享者），1（表示拥有者）
@property (nonatomic, assign) NSInteger owned;
// 设备的节点类型，可取值包括：DEVICE，GATEWAY(网关设备)
@property (nonatomic, copy) NSString *nodeType;
// 网关ID(子设备才会有该值)
@property (nonatomic, copy) NSString *gatewayId;
// DEVICE:普通设备
@property (nonatomic, copy) NSString *thingType;
// 设备状态。0（表示未激活）；1（表示在线）；2（表示休眠）；3（表示离线）；8（表示禁用）
@property (nonatomic, assign) NSInteger status;
// 设备当前所在的机房
@property (nonatomic, copy) NSString *region;
// 只有owned=0有值，分享权限列表，live：直播，control：设备控制，record：录像回看，ptz：云台控制，voiceIntercom：语音对讲，setting：高级设置，notification：消息通知
@property (nonatomic, strong) NSArray *sharePermissionList;
// 分组id
@property (nonatomic, assign) NSInteger groupId;
// 播放策略
@property (nonatomic, copy) NSString *playStrategy;
// 设备属性值
@property (nonatomic, strong) NSDictionary *propertyMap;
// 设备云存套餐信息
@property (nonatomic, strong) RTCXCloudServicesRsp *cloudServices;
@end

@interface RTCXDeviceInfoList : RTCXDeviceMgrRsp
// 设备总数量
@property (nonatomic, assign) NSInteger total;
// 当前页
@property (nonatomic, assign) NSInteger pageNo;
// 每页数量
@property (nonatomic, assign) NSInteger pageSize;
// 设备数组<RTCXDeviceInfo>
@property (nonatomic, strong) NSArray *data;

@end

@interface RTCXBindTokenInfo : RTCXDeviceMgrRsp
// 平台生成的用于绑定设备的Token
@property (nonatomic, copy) NSString *token;
// 配网所需随机数
@property (nonatomic, copy) NSString *random;
// Token的过期时间点，UTC时间戳
@property (nonatomic, assign) long expireTime;

@end

@interface RTCXDeviceBindResult : RTCXDeviceMgrRsp
// 平台为设备颁发的ID，设备的唯一标识符
@property (nonatomic, copy) NSString *iotId;
// 类目键
@property (nonatomic, copy) NSString *categoryKey;
// 页面路由的链接
@property (nonatomic, copy) NSString *pageRouterUrl;
// TraceId
@property (nonatomic, copy) NSString *bindTraceId;

@end

@interface RTCXDeviceBindStatusRsp : RTCXDeviceMgrRsp
// 平台为设备颁发的ID，设备的唯一标识符
@property (nonatomic, copy) NSString *iotId;
// 设备型号 如：xLeWcoelZbyOePbJludl 必选
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002 必选
@property (nonatomic, copy) NSString *deviceName;
// 绑定状态，0未绑定，1绑定
@property (nonatomic, assign) NSInteger bindStatus;

@end

@interface RTCXFirmwareUpdateCheckRsp : RTCXDeviceMgrRsp
// 当前固件对应的设备子模块名称，为空或default表示主模块。
@property (nonatomic, copy) NSString *moduleName;
// 当前设备子模块实际烧录的固件版本号。
@property (nonatomic, copy) NSString *currentVersion;
// 固件升级状态。可取值： TO_BE_UPGRADED（表示待升级）；SUCCEEDED（表示升级成功）。
@property (nonatomic, copy) NSString *status;
// 当前固件的版本号。固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, copy) NSString *firmwareVersion;
// 固件文件包大小，单位Byte，固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, assign) NSInteger size;
// 版本固件文件加签处理后的数据内容，固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, copy) NSString *sign;
// 当前固件校验数据的加签方式，可取值：MD5（表示采用md5加签）；SHA256（表示采用sha256加签），固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, copy) NSString *signMethod;
// 当前固件文件的下载地址，固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, copy) NSString *url;
// 固件的信息描述，固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, copy) NSString *details;
// 固件信息的推送类型，可取值：CONFIRM（用户确认升级）； COMPELLENT（强制升级），固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, copy) NSString *otaType;

@end

@interface RTCXFirmwareUpdateProgressRsp : RTCXDeviceMgrRsp
// 平台为设备颁发的ID，设备的唯一标识符 必选
@property (nonatomic, copy) NSString *iotId;
// 当前固件对应的设备子模块名称，为空或default表示主模块。
@property (nonatomic, copy) NSString *moduleName;
// 当前设备子模块实际烧录的固件版本号。
@property (nonatomic, copy) NSString *currentVersion;
// 当前固件的版本号。固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, copy) NSString *firmwareVersion;
// 固件信息的推送类型，可取值：CONFIRM（用户确认升级）； COMPELLENT（强制升级）。固件升级状态为TO_BE_UPGRADED时该参数有效。
@property (nonatomic, copy) NSString *otaType;
// 固件升级状态。可取值： TO_BE_UPGRADED（表示待升级）；UPGRADING（表示升级中）；SUCCEEDED（表示升级成功）；FAILED（表示升级失败）。注意：如果升级时间超过10分钟（从在平台创建升级任务开始计算）还处于升级中，就返回upgradeStatus为2。
@property (nonatomic, copy) NSString *status;
// 固件进度的描述信息。
@property (nonatomic, copy) NSString *desc;
@end

@interface RTCXShareNoticeInfoRsp : RTCXDeviceMgrRsp
// 发起分享用户的账号
@property (nonatomic, copy) NSString *initiatorAlias;
// 被分享用户的账号
@property (nonatomic, copy) NSString *receiverAlias;
// 设备型号 如：xLeWcoelZbyOePbJludl
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002
@property (nonatomic, copy) NSString *deviceName;
// 当前用户是否是消息接收者。0（表示当前用户是此消息的发起者）；1（表示当前用户是接收者）。
@property (nonatomic, assign) NSInteger isReceiver;
// 创建时间。
@property (nonatomic, assign) NSInteger gmtCreate;
// 修改时间。
@property (nonatomic, assign) NSInteger gmtModified;
// 分享记录唯一标识。按照BATCH查询时，如果批次内有多个记录，此字段不会返回。
@property (nonatomic, assign) NSInteger recordId;
// 分享批次ID。批量分享设备时，同一批次ID相同，客户端可以根据此判断是否为同一批分享，由此做聚合展示等。
@property (nonatomic, assign) NSInteger batchId;
// 状态 。-1:（表示初始化）；0（表示同意）；1（表示拒绝 ）；2（表示取消）；3（表示过期）；4（表示抢占）；5（表示删除）；6（表示发起者已解绑）；99（表示异常）。
@property (nonatomic, assign) NSInteger status;
// 描述
@property (nonatomic, copy) NSString *description;
// 批次信息。如果批次内包含多个记录，此字段不为空，其中包含了该批次的信息。{"recordCount":"xxx"}, recordCount: 当前批次中所包含的分享记录的数量。例如在一个批次中分享了 10 个设备，那么对应包含有 10 个分享记录。
@property (nonatomic, strong) NSDictionary *batchInfo;
// 发起分享用户的账号id。
@property (nonatomic, assign) NSInteger initiatorIdentityId;
// 被分享用户的账号id。
@property (nonatomic, assign) NSInteger receiverIdentityId;
// 权限列表
@property (nonatomic, strong) NSArray *permissionList;
@end

@interface RTCXShareNoticeListRsp : RTCXDeviceMgrRsp
// 设备总数量
@property (nonatomic, assign) NSInteger total;
// 当前页
@property (nonatomic, assign) NSInteger pageNo;
// 每页数量
@property (nonatomic, assign) NSInteger pageSize;
// 设备数组<RTCXShareNoticeInfoRsp>
@property (nonatomic, strong) NSArray *data;
@end

@interface RTCXDeviceShareRecordInfoRsp : RTCXDeviceMgrRsp
// 发起分享用户的账号
@property (nonatomic, copy) NSString *initiatorAlias;
// 被分享用户的账号
@property (nonatomic, copy) NSString *receiverAlias;
// 设备型号 如：xLeWcoelZbyOePbJludl
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002
@property (nonatomic, copy) NSString *deviceName;
// 当前用户是否是消息接收者。0（表示当前用户是此消息的发起者）；1（表示当前用户是接收者）。
@property (nonatomic, assign) NSInteger isReceiver;
// 创建时间。
@property (nonatomic, assign) NSInteger gmtCreate;
// 修改时间。
@property (nonatomic, assign) NSInteger gmtModified;
// 分享记录唯一标识。按照BATCH查询时，如果批次内有多个记录，此字段不会返回。
@property (nonatomic, assign) NSInteger recordId;
// 分享批次ID。批量分享设备时，同一批次ID相同，客户端可以根据此判断是否为同一批分享，由此做聚合展示等。
@property (nonatomic, assign) NSInteger batchId;
// 状态 。-1:（表示初始化）；0（表示同意）；1（表示拒绝 ）；2（表示取消）；3（表示过期）；4（表示抢占）；5（表示删除）；6（表示发起者已解绑）；99（表示异常）。
@property (nonatomic, assign) NSInteger status;
// 描述
@property (nonatomic, copy) NSString *description;
// 批次信息。如果批次内包含多个记录，此字段不为空，其中包含了该批次的信息。{"recordCount":"xxx"}, recordCount: 当前批次中所包含的分享记录的数量。例如在一个批次中分享了 10 个设备，那么对应包含有 10 个分享记录。
@property (nonatomic, strong) NSDictionary *batchInfo;
// 发起分享用户的账号id。
@property (nonatomic, assign) NSInteger initiatorIdentityId;
// 被分享用户的账号id。
@property (nonatomic, assign) NSInteger receiverIdentityId;
// 权限列表
@property (nonatomic, strong) NSArray *permissionList;
@end

@interface RTCXDeviceShareRecordListRsp : RTCXDeviceMgrRsp
// 设备总数量
@property (nonatomic, assign) NSInteger total;
// 当前页
@property (nonatomic, assign) NSInteger pageNo;
// 每页数量
@property (nonatomic, assign) NSInteger pageSize;
// 设备数组<RTCXDeviceShareRecordInfoRsp>
@property (nonatomic, strong) NSArray *data;
@end

@interface RTCXDeviceShareUserInfoRsp : RTCXDeviceMgrRsp
// 分享记录唯一标识。按照BATCH查询时，如果批次内有多个记录，此字段不会返回。
@property (nonatomic, assign) NSInteger recordId;
// 分享批次ID。批量分享设备时，同一批次ID相同，客户端可以根据此判断是否为同一批分享，由此做聚合展示等。
@property (nonatomic, assign) NSInteger batchId;
// 状态 。-1:（表示初始化）；0（表示同意）；1（表示拒绝 ）；2（表示取消）；3（表示过期）；4（表示抢占）；5（表示删除）；6（表示发起者已解绑）；99（表示异常）。
@property (nonatomic, assign) NSInteger status;
// 被分享用户的账号id。
@property (nonatomic, assign) NSInteger receiverIdentityId;
// 被分享用户的账号
@property (nonatomic, copy) NSString *receiverAlias;
// 权限列表
@property (nonatomic, strong) NSArray *permissionList;
@end

@interface RTCXDeviceShareUserListRsp : RTCXDeviceMgrRsp
// 设备总数量
@property (nonatomic, assign) NSInteger total;
// 当前页
@property (nonatomic, assign) NSInteger pageNo;
// 每页数量
@property (nonatomic, assign) NSInteger pageSize;
// 设备数组<RTCXDeviceShareUserInfoRsp>
@property (nonatomic, strong) NSArray *items;
@end

@interface RTCXDeviceShareCountInfoRsp : RTCXDeviceMgrRsp
// 设备唯一标识
@property (nonatomic, copy) NSString *iotId;
// 设备序列号SN 如：TEST20240820002 必选
@property (nonatomic, copy) NSString *deviceName;
// 设备的昵称
@property (nonatomic, copy) NSString *nickName;
// 分享数量，包括未处理的和已接受的
@property (nonatomic, assign) NSInteger shareCount;
@end

@interface RTCXDeviceShareCountListRsp : RTCXDeviceMgrRsp
// 设备总数量
@property (nonatomic, assign) NSInteger total;
// 当前页
@property (nonatomic, assign) NSInteger pageNo;
// 每页数量
@property (nonatomic, assign) NSInteger pageSize;
// 最大分享数量
@property (nonatomic, assign) NSInteger maxShareCount;
// 设备数组<RTCXDeviceShareCountInfoRsp>
@property (nonatomic, strong) NSArray *items;
@end

@interface RTCXGroupInfoRsp : RTCXDeviceMgrRsp
// 设备组的id
@property (nonatomic, assign) NSInteger groupId;
// 设备组的名称
@property (nonatomic, copy) NSString *name;
// 分组下设备数量
@property (nonatomic, assign) NSInteger deviceCount;
@end

@interface RTCXGroupListRsp : RTCXDeviceMgrRsp
// 设备总数量
@property (nonatomic, assign) NSInteger total;
// 当前页
@property (nonatomic, assign) NSInteger pageNo;
// 每页数量
@property (nonatomic, assign) NSInteger pageSize;
// 设备数组<RTCXGroupInfoRsp>
@property (nonatomic, strong) NSArray *items;
@end

@interface RTCXDeviceConfigRsp : NSObject
// 配置Map
@property (nonatomic, strong) NSDictionary *attributeMap;
// 最后更新时间
@property (nonatomic, assign) NSInteger maxUpdateTimeValue;
@end

@interface RTCXGetPtzPresetPositionInfoRsp : RTCXDeviceMgrRsp
// 名称
@property (nonatomic, copy) NSString *name;
// 文件名
@property (nonatomic, copy) NSString *picId;
// ptz信息
@property (nonatomic, copy) NSString *ptz;
// 图片地址
@property (nonatomic, copy) NSString *url;
@end

@interface RTCXGetPtzPresetPositionListRsp : RTCXDeviceMgrRsp
// PTZ预置位数组<RTCXGetPtzPresetPositionInfoRsp>
@property (nonatomic, strong) NSArray *presetPositionList;
@end
