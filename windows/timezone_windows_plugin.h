#ifndef FLUTTER_PLUGIN_TIMEZONE_WINDOWS_PLUGIN_H_
#define FLUTTER_PLUGIN_TIMEZONE_WINDOWS_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace timezone_windows {

class TimezoneWindowsPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  TimezoneWindowsPlugin();

  virtual ~TimezoneWindowsPlugin();

  // Disallow copy and assign.
  TimezoneWindowsPlugin(const TimezoneWindowsPlugin&) = delete;
  TimezoneWindowsPlugin& operator=(const TimezoneWindowsPlugin&) = delete;

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace timezone_windows

#endif  // FLUTTER_PLUGIN_TIMEZONE_WINDOWS_PLUGIN_H_
