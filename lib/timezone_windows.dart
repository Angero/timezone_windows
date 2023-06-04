
import 'timezone_windows_platform_interface.dart';

class TimezoneWindows {
  Future<String?> getPlatformVersion() {
    return TimezoneWindowsPlatform.instance.getPlatformVersion();
  }

  Future<String?> getLocalTimezone() {
    return TimezoneWindowsPlatform.instance.getLocalTimezone();
  }

  Future<String?> getCurrentPath() {
    return TimezoneWindowsPlatform.instance.getCurrentPath();
  }
}
