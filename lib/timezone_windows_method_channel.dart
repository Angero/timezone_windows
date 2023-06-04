import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'timezone_windows_platform_interface.dart';

/// An implementation of [TimezoneWindowsPlatform] that uses method channels.
class MethodChannelTimezoneWindows extends TimezoneWindowsPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('timezone_windows');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }

  @override
  Future<String?> getLocalTimezone() async {
    final version = await methodChannel.invokeMethod<String>('getLocalTimezone');
    return version;
  }
}
