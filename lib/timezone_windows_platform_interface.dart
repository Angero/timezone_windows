import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'timezone_windows_method_channel.dart';

abstract class TimezoneWindowsPlatform extends PlatformInterface {
  /// Constructs a TimezoneWindowsPlatform.
  TimezoneWindowsPlatform() : super(token: _token);

  static final Object _token = Object();

  static TimezoneWindowsPlatform _instance = MethodChannelTimezoneWindows();

  /// The default instance of [TimezoneWindowsPlatform] to use.
  ///
  /// Defaults to [MethodChannelTimezoneWindows].
  static TimezoneWindowsPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [TimezoneWindowsPlatform] when
  /// they register themselves.
  static set instance(TimezoneWindowsPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }

  Future<String?> getLocalTimezone() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
