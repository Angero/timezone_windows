#include "timezone_windows_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>
#include <filesystem>

typedef char* (*getLocalTimezoneFn)();

namespace timezone_windows {

// static
void TimezoneWindowsPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "timezone_windows",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<TimezoneWindowsPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

TimezoneWindowsPlugin::TimezoneWindowsPlugin() {}

TimezoneWindowsPlugin::~TimezoneWindowsPlugin() {}

void TimezoneWindowsPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {

  if (method_call.method_name().compare("getPlatformVersion") == 0) {
    std::ostringstream version_stream;
    version_stream << "Windows ";
    if (IsWindows10OrGreater()) {
      version_stream << "10+";
    } else if (IsWindows8OrGreater()) {
      version_stream << "8";
    } else if (IsWindows7OrGreater()) {
      version_stream << "7";
    }
    result->Success(flutter::EncodableValue(version_stream.str()));
//  } else {
//    result->NotImplemented();
  }

  if (method_call.method_name().compare("getLocalTimezone") == 0) {
      //HINSTANCE hInstLibrary = LoadLibrary(TEXT("..\\windows\\WindowsTimezone.dll"));
      HINSTANCE hInstLibrary = LoadLibrary(TEXT("WindowsTimezone.dll"));
      if (hInstLibrary != NULL) {
        getLocalTimezoneFn getLocalTimezone = (getLocalTimezoneFn)GetProcAddress(hInstLibrary, "getZone");
        if (getLocalTimezone != NULL) {
          char* timezone = getLocalTimezone();
          std::ostringstream version_stream;
              version_stream << timezone;
              result->Success(flutter::EncodableValue(version_stream.str()));
        } else {
          printf("Could not find getLocalTimezone function in DLL\n");
        }
        FreeLibrary(hInstLibrary);
      } else {
        printf("Could not load WindowsTimezone.dll\n");
      }
    }

  if (method_call.method_name().compare("getCurrentPath") == 0) {
    std::ostringstream version_stream;
    version_stream << std::filesystem::current_path().generic_string();;
    result->Success(flutter::EncodableValue(version_stream.str()));
  }
}

}  // namespace timezone_windows
