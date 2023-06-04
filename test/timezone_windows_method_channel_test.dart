import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:timezone_windows/timezone_windows_method_channel.dart';

void main() {
  MethodChannelTimezoneWindows platform = MethodChannelTimezoneWindows();
  const MethodChannel channel = MethodChannel('timezone_windows');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await platform.getPlatformVersion(), '42');
  });
}
