import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_plugin2/flutter_plugin2.dart';
import 'package:flutter_plugin2/flutter_plugin2_platform_interface.dart';
import 'package:flutter_plugin2/flutter_plugin2_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockFlutterPlugin2Platform
    with MockPlatformInterfaceMixin
    implements FlutterPlugin2Platform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final FlutterPlugin2Platform initialPlatform = FlutterPlugin2Platform.instance;

  test('$MethodChannelFlutterPlugin2 is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelFlutterPlugin2>());
  });

  test('getPlatformVersion', () async {
    FlutterPlugin2 flutterPlugin2Plugin = FlutterPlugin2();
    MockFlutterPlugin2Platform fakePlatform = MockFlutterPlugin2Platform();
    FlutterPlugin2Platform.instance = fakePlatform;

    expect(await flutterPlugin2Plugin.getPlatformVersion(), '42');
  });
}
