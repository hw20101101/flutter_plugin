import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:flutter_plugin0607/flutter_plugin0607.dart';
import 'package:rtcx_iot_smart/rtcx_account.dart';
import 'package:rtcx_iot_smart/rtcx_iot_smart.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  String _platformVersion = 'Unknown';
  final _flutterPlugin0607Plugin = FlutterPlugin0607();

  final _rtcxIotSmart = RtcxIotSmart.instance;
  String _sdkVersion = 'Unknown';
  String _currentLanguage = 'Unknown';
  List<IotCountry> _countries = [];
  IotCountry? _currentCountry;
  bool _isInitialized = false;

  @override
  void initState() {
    super.initState();
    initPlatformState();
    _initializeSDK();
  }

  Future<void> _initializeSDK() async {
    try {
      // 配置SDK
      const config = IotSmartConfig(
        appKey: 'bOk9F2kUwgb1z4n3F6evQCc4l',
        appSecret: 'fg5d0HyycDjnEmYuO0aGuRgO1RvVnQz',
        appType: AppType.develop,
        regionType: RegionType.all,
      );

      // 设置初始化完成回调
      _rtcxIotSmart.setSdkInitCompletedCallback(() {
        print('相速 SDK初始化:$_isInitialized');
        _sendValidateCode();

        setState(() {
          _isInitialized = true;
        });
      });

      // 初始化SDK
      await _rtcxIotSmart.initialize(config);

      // 开启调试模式
      await _rtcxIotSmart.setDebug(true);

      // 获取SDK版本
      final version = await _rtcxIotSmart.getCurrentSDKVersion();

      // 获取当前语言
      final language = await _rtcxIotSmart.getLanguage();

      // 获取国家列表
      final countries = await _rtcxIotSmart.getCountryList();

      // 获取当前国家
      final currentCountry = await _rtcxIotSmart.getCountry();

      setState(() {
        _sdkVersion = version;
        _currentLanguage = language;
        _countries = countries;
        _currentCountry = currentCountry;
      });

      print(
          '相速 SDK 初始化 版本:$_sdkVersion,当前语言:$_currentLanguage,国家:${_currentCountry?.areaName}');
    } catch (e) {
      print('SDK初始化失败: $e');
    }
  }

  Future<void> _sendValidateCode() async {
    try {
      final rtcxPlugin = RtcxOpenAccountFlutter();
      final result = await rtcxPlugin.sendValidateCode(
        account: '18578534541',
        verifyCodeType: 1, // 登录验证码
        code: '86', // 国家码
      );
      print('sendCode success: $result');
    } catch (e) {
      print('sendCode error: $e');
    }
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initPlatformState() async {
    String platformVersion;
    // Platform messages may fail, so we use a try/catch PlatformException.
    // We also handle the message potentially returning null.
    try {
      platformVersion = await _flutterPlugin0607Plugin.getPlatformVersion() ??
          'Unknown platform version';
    } on PlatformException {
      platformVersion = 'Failed to get platform version.';
    }

    // If the widget was removed from the tree while the asynchronous platform
    // message was in flight, we want to discard the reply rather than calling
    // setState to update our non-existent appearance.
    if (!mounted) return;

    setState(() {
      _platformVersion = platformVersion;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
          child: Text('Running on: $_platformVersion\n'),
        ),
      ),
    );
  }
}
