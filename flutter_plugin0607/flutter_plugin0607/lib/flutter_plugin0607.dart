import 'flutter_plugin0607_platform_interface.dart';

class FlutterPlugin0607 {
  Future<String?> getPlatformVersion() {
    return FlutterPlugin0607Platform.instance.getPlatformVersion();
  }

  Future<String?> initWechatSDK() {
    return FlutterPlugin0607Platform.instance.initWechatSDK();
  }
}
