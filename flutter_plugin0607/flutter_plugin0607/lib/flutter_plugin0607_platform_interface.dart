import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'flutter_plugin0607_method_channel.dart';

abstract class FlutterPlugin0607Platform extends PlatformInterface {
  /// Constructs a FlutterPlugin0607Platform.
  FlutterPlugin0607Platform() : super(token: _token);

  static final Object _token = Object();

  static FlutterPlugin0607Platform _instance = MethodChannelFlutterPlugin0607();

  /// The default instance of [FlutterPlugin0607Platform] to use.
  ///
  /// Defaults to [MethodChannelFlutterPlugin0607].
  static FlutterPlugin0607Platform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FlutterPlugin0607Platform] when
  /// they register themselves.
  static set instance(FlutterPlugin0607Platform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }

  Future<String?> initWechatSDK() {
    throw UnimplementedError('initWechatSDK() has not been implemented.');
  }
}
