import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_plugin0607/flutter_plugin0607.dart';
import 'package:flutter_plugin0607/flutter_plugin0607_platform_interface.dart';
import 'package:flutter_plugin0607/flutter_plugin0607_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockFlutterPlugin0607Platform
    with MockPlatformInterfaceMixin
    implements FlutterPlugin0607Platform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final FlutterPlugin0607Platform initialPlatform = FlutterPlugin0607Platform.instance;

  test('$MethodChannelFlutterPlugin0607 is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelFlutterPlugin0607>());
  });

  test('getPlatformVersion', () async {
    FlutterPlugin0607 flutterPlugin0607Plugin = FlutterPlugin0607();
    MockFlutterPlugin0607Platform fakePlatform = MockFlutterPlugin0607Platform();
    FlutterPlugin0607Platform.instance = fakePlatform;

    expect(await flutterPlugin0607Plugin.getPlatformVersion(), '42');
  });
}
