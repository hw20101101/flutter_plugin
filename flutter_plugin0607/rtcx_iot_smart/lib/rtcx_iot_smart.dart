import 'dart:async';
import 'package:flutter/services.dart';

/// 区域类型枚举
enum RegionType {
  /// 只支持中国大陆服务器
  chinaOnly,
  /// 支持全球服务器
  all,
}

/// APP类型枚举
enum AppType {
  /// 正式版APP
  production,
  /// 测试版APP
  develop,
}

/// 国家/地区信息
class IotCountry {
  /// 国家（地区）名称
  final String areaName;
  
  /// 国家（地区）区号
  final String code;
  
  /// 国家（地区）名称的拼音
  final String pinyin;
  
  /// ISO Country Code - 标准国家码
  final String isoCode;
  
  /// 标准国家码简写
  final String? domainAbbreviation;

  const IotCountry({
    required this.areaName,
    required this.code,
    required this.pinyin,
    required this.isoCode,
    this.domainAbbreviation,
  });

  factory IotCountry.fromMap(Map<String, dynamic> map) {
    return IotCountry(
      areaName: map['areaName'] as String,
      code: map['code'] as String,
      pinyin: map['pinyin'] as String,
      isoCode: map['isoCode'] as String,
      domainAbbreviation: map['domainAbbreviation'] as String?,
    );
  }

  Map<String, dynamic> toMap() {
    return {
      'areaName': areaName,
      'code': code,
      'pinyin': pinyin,
      'isoCode': isoCode,
      'domainAbbreviation': domainAbbreviation,
    };
  }
}

/// SDK配置类
class IotSmartConfig {
  /// App Key
  final String appKey;
  
  /// App Secret
  final String appSecret;
  
  /// APP类型
  final AppType appType;
  
  /// 区域类型
  final RegionType regionType;

  const IotSmartConfig({
    required this.appKey,
    required this.appSecret,
    this.appType = AppType.production,
    this.regionType = RegionType.chinaOnly,
  });

  Map<String, dynamic> toMap() {
    return {
      'appKey': appKey,
      'appSecret': appSecret,
      'appType': appType.index,
      'regionType': regionType.index,
    };
  }
}

/// RTCXIotSmart Flutter插件主类
class RtcxIotSmart {
  static const MethodChannel _channel = MethodChannel('rtcx_iot_smart');
  
  static RtcxIotSmart? _instance;
  
  /// 单例
  static RtcxIotSmart get instance {
    _instance ??= RtcxIotSmart._();
    return _instance!;
  }
  
  RtcxIotSmart._();

  /// 初始化SDK配置
  Future<void> initialize(IotSmartConfig config) async {
    await _channel.invokeMethod('initialize', config.toMap());
  }

  /// 设置SDK初始化完成回调
  void setSdkInitCompletedCallback(VoidCallback callback) {
    _channel.setMethodCallHandler((call) async {
      if (call.method == 'sdkInitCompleted') {
        callback();
      }
    });
  }

  /// 设置调试模式
  Future<void> setDebug(bool debug) async {
    await _channel.invokeMethod('setDebug', {'debug': debug});
  }

  /// 获取当前SDK版本
  Future<String> getCurrentSDKVersion() async {
    final version = await _channel.invokeMethod<String>('getCurrentSDKVersion');
    return version ?? '';
  }

  /// 检查SDK是否初始化完成
  Future<bool> sdkInitializationCompleted() async {
    final completed = await _channel.invokeMethod<bool>('sdkInitializationCompleted');
    return completed ?? false;
  }

  /// 设置语言
  /// 支持语言: zh-CN、en-US、fr-FR、de-DE、ja-JP、ko-KR、es-ES、ru-RU、hi-IN、it-IT、tr-TR、zh-TW
  Future<void> setLanguage(String language) async {
    await _channel.invokeMethod('setLanguage', {'language': language});
  }

  /// 获取当前设置的语言
  Future<String> getLanguage() async {
    final language = await _channel.invokeMethod<String>('getLanguage');
    return language ?? 'zh-CN';
  }

  /// 设置国家/地区
  Future<IotCountry?> setCountry(IotCountry country) async {
    try {
      final result = await _channel.invokeMethod('setCountry', country.toMap());
      if (result != null) {
        return IotCountry.fromMap(Map<String, dynamic>.from(result));
      }
      return null;
    } catch (e) {
      throw Exception('Failed to set country: $e');
    }
  }

  /// 获取国家列表
  Future<List<IotCountry>> getCountryList() async {
    final result = await _channel.invokeMethod<List>('getCountryList');
    if (result != null) {
      return result
          .map((item) => IotCountry.fromMap(Map<String, dynamic>.from(item)))
          .toList();
    }
    return [];
  }

  /// 获取当前设置的国家/地区
  Future<IotCountry?> getCountry() async {
    final result = await _channel.invokeMethod('getCountry');
    if (result != null) {
      return IotCountry.fromMap(Map<String, dynamic>.from(result));
    }
    return null;
  }
}