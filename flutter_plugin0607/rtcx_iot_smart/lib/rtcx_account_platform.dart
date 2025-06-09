import 'package:plugin_platform_interface/plugin_platform_interface.dart';
import 'rtcx_account_channel.dart';

abstract class RtcxOpenAccountFlutterPlatform extends PlatformInterface {
  RtcxOpenAccountFlutterPlatform() : super(token: _token);

  static final Object _token = Object();

  static RtcxOpenAccountFlutterPlatform _instance =
      MethodChannelRtcxOpenAccountFlutter();

  static RtcxOpenAccountFlutterPlatform get instance => _instance;

  static set instance(RtcxOpenAccountFlutterPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<Map<String, dynamic>?> registerAccount({
    required int accountType,
    String? account,
    String? userExtra,
    required String country,
    required int pwdType,
    required String password,
    String? loginName,
    String? verifyCode,
  }) {
    throw UnimplementedError('registerAccount() has not been implemented.');
  }

  Future<Map<String, dynamic>?> sendValidateCode({
    required String account,
    required int verifyCodeType,
    String? code,
  }) {
    throw UnimplementedError('sendValidateCode() has not been implemented.');
  }

  Future<Map<String, dynamic>?> loginAccount({
    required int accountType,
    String? account,
    String? userExtra,
    required String country,
    required int pwdType,
    required String password,
    String? loginName,
  }) {
    throw UnimplementedError('loginAccount() has not been implemented.');
  }

  Future<Map<String, dynamic>?> resetPassword({
    required String account,
    required String password,
    required String verifyCode,
  }) {
    throw UnimplementedError('resetPassword() has not been implemented.');
  }

  Future<Map<String, dynamic>?> modifyPassword({
    required String oldPassword,
    required String updatedPassword,
  }) {
    throw UnimplementedError('modifyPassword() has not been implemented.');
  }

  Future<Map<String, dynamic>?> refreshToken({
    required String refreshToken,
  }) {
    throw UnimplementedError('refreshToken() has not been implemented.');
  }

  Future<Map<String, dynamic>?> logout() {
    throw UnimplementedError('logout() has not been implemented.');
  }

  Future<Map<String, dynamic>?> logoff({
    required String verifyCode,
  }) {
    throw UnimplementedError('logoff() has not been implemented.');
  }

  Future<Map<String, dynamic>?> autoLogin() {
    throw UnimplementedError('autoLogin() has not been implemented.');
  }

  Future<bool> isLogin() {
    throw UnimplementedError('isLogin() has not been implemented.');
  }

  Future<Map<String, dynamic>?> updateUserProfile({
    String? nickName,
    String? imageData,
  }) {
    throw UnimplementedError('updateUserProfile() has not been implemented.');
  }

  Future<Map<String, dynamic>?> getUserProfile() {
    throw UnimplementedError('getUserProfile() has not been implemented.');
  }

  void setAuthenticationAbnormalCallback(
      Function(int code, String message) callback) {
    throw UnimplementedError(
        'setAuthenticationAbnormalCallback() has not been implemented.');
  }
}
