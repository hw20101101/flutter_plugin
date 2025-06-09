import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';
import 'rtcx_account_platform.dart';

class MethodChannelRtcxOpenAccountFlutter
    extends RtcxOpenAccountFlutterPlatform {
  @visibleForTesting
  final methodChannel = const MethodChannel('rtcx_open_account_flutter');

  Function(int code, String message)? _authAbnormalCallback;

  MethodChannelRtcxOpenAccountFlutter() {
    methodChannel.setMethodCallHandler(_handleMethodCall);
  }

  Future<dynamic> _handleMethodCall(MethodCall call) async {
    switch (call.method) {
      case 'onAuthenticationAbnormal':
        final int code = call.arguments['code'];
        final String message = call.arguments['message'];
        _authAbnormalCallback?.call(code, message);
        break;
      default:
        throw PlatformException(
          code: 'Unimplemented',
          details: 'Method ${call.method} is not implemented',
        );
    }
  }

  @override
  Future<Map<String, dynamic>?> registerAccount({
    required int accountType,
    String? account,
    String? userExtra,
    required String country,
    required int pwdType,
    required String password,
    String? loginName,
    String? verifyCode,
  }) async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'registerAccount',
      {
        'accountType': accountType,
        'account': account,
        'userExtra': userExtra,
        'country': country,
        'pwdType': pwdType,
        'password': password,
        'loginName': loginName,
        'verifyCode': verifyCode,
      },
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> sendValidateCode({
    required String account,
    required int verifyCodeType,
    String? code,
  }) async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'sendValidateCode',
      {
        'account': account,
        'verifyCodeType': verifyCodeType,
        'code': code,
      },
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> loginAccount({
    required int accountType,
    String? account,
    String? userExtra,
    required String country,
    required int pwdType,
    required String password,
    String? loginName,
  }) async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'loginAccount',
      {
        'accountType': accountType,
        'account': account,
        'userExtra': userExtra,
        'country': country,
        'pwdType': pwdType,
        'password': password,
        'loginName': loginName,
      },
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> resetPassword({
    required String account,
    required String password,
    required String verifyCode,
  }) async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'resetPassword',
      {
        'account': account,
        'password': password,
        'verifyCode': verifyCode,
      },
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> modifyPassword({
    required String oldPassword,
    required String updatedPassword,
  }) async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'modifyPassword',
      {
        'oldPassword': oldPassword,
        'updatedPassword': updatedPassword,
      },
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> refreshToken({
    required String refreshToken,
  }) async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'refreshToken',
      {
        'refreshToken': refreshToken,
      },
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> logout() async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'logout',
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> logoff({
    required String verifyCode,
  }) async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'logoff',
      {
        'verifyCode': verifyCode,
      },
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> autoLogin() async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'autoLogin',
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<bool> isLogin() async {
    return await methodChannel.invokeMethod<bool>('isLogin') ?? false;
  }

  @override
  Future<Map<String, dynamic>?> updateUserProfile({
    String? nickName,
    String? imageData,
  }) async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'updateUserProfile',
      {
        'nickName': nickName,
        'imageData': imageData,
      },
    );
    return result?.cast<String, dynamic>();
  }

  @override
  Future<Map<String, dynamic>?> getUserProfile() async {
    final result = await methodChannel.invokeMethod<Map<Object?, Object?>?>(
      'getUserProfile',
    );
    return result?.cast<String, dynamic>();
  }

  @override
  void setAuthenticationAbnormalCallback(
      Function(int code, String message) callback) {
    _authAbnormalCallback = callback;
  }
}
