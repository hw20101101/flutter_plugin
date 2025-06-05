
import 'flutter_plugin2_platform_interface.dart';

class FlutterPlugin2 {
  Future<String?> getPlatformVersion() {
    return FlutterPlugin2Platform.instance.getPlatformVersion();
  }
}
