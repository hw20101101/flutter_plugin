import 'rtcx_account_platform.dart';

class RtcxOpenAccountFlutter {
  // 注册账号
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
    return RtcxOpenAccountFlutterPlatform.instance.registerAccount(
      accountType: accountType,
      account: account,
      userExtra: userExtra,
      country: country,
      pwdType: pwdType,
      password: password,
      loginName: loginName,
      verifyCode: verifyCode,
    );
  }

  // 发送验证码
  Future<Map<String, dynamic>?> sendValidateCode({
    required String account,
    required int verifyCodeType,
    String? code,
  }) {
    return RtcxOpenAccountFlutterPlatform.instance.sendValidateCode(
      account: account,
      verifyCodeType: verifyCodeType,
      code: code,
    );
  }

  // 登录账号
  Future<Map<String, dynamic>?> loginAccount({
    required int accountType,
    String? account,
    String? userExtra,
    required String country,
    required int pwdType,
    required String password,
    String? loginName,
  }) {
    return RtcxOpenAccountFlutterPlatform.instance.loginAccount(
      accountType: accountType,
      account: account,
      userExtra: userExtra,
      country: country,
      pwdType: pwdType,
      password: password,
      loginName: loginName,
    );
  }

  // 重置密码
  Future<Map<String, dynamic>?> resetPassword({
    required String account,
    required String password,
    required String verifyCode,
  }) {
    return RtcxOpenAccountFlutterPlatform.instance.resetPassword(
      account: account,
      password: password,
      verifyCode: verifyCode,
    );
  }

  // 修改密码
  Future<Map<String, dynamic>?> modifyPassword({
    required String oldPassword,
    required String updatedPassword,
  }) {
    return RtcxOpenAccountFlutterPlatform.instance.modifyPassword(
      oldPassword: oldPassword,
      updatedPassword: updatedPassword,
    );
  }

  // 刷新Token
  Future<Map<String, dynamic>?> refreshToken({
    required String refreshToken,
  }) {
    return RtcxOpenAccountFlutterPlatform.instance.refreshToken(
      refreshToken: refreshToken,
    );
  }

  // 退出登录
  Future<Map<String, dynamic>?> logout() {
    return RtcxOpenAccountFlutterPlatform.instance.logout();
  }

  // 用户注销
  Future<Map<String, dynamic>?> logoff({
    required String verifyCode,
  }) {
    return RtcxOpenAccountFlutterPlatform.instance.logoff(
      verifyCode: verifyCode,
    );
  }

  // 自动登录
  Future<Map<String, dynamic>?> autoLogin() {
    return RtcxOpenAccountFlutterPlatform.instance.autoLogin();
  }

  // 是否登录
  Future<bool> isLogin() {
    return RtcxOpenAccountFlutterPlatform.instance.isLogin();
  }

  // 更新用户资料
  Future<Map<String, dynamic>?> updateUserProfile({
    String? nickName,
    String? imageData,
  }) {
    return RtcxOpenAccountFlutterPlatform.instance.updateUserProfile(
      nickName: nickName,
      imageData: imageData,
    );
  }

  // 获取用户资料
  Future<Map<String, dynamic>?> getUserProfile() {
    return RtcxOpenAccountFlutterPlatform.instance.getUserProfile();
  }

  // 设置认证异常回调
  void setAuthenticationAbnormalCallback(
      Function(int code, String message) callback) {
    RtcxOpenAccountFlutterPlatform.instance
        .setAuthenticationAbnormalCallback(callback);
  }
}
