import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'flutter_plugin0607_platform_interface.dart';

/// An implementation of [FlutterPlugin0607Platform] that uses method channels.
class MethodChannelFlutterPlugin0607 extends FlutterPlugin0607Platform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('flutter_plugin0607');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
