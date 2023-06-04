#include "include/timezone_windows/timezone_windows_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "timezone_windows_plugin.h"

void TimezoneWindowsPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  timezone_windows::TimezoneWindowsPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
