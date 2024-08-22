import 'package:flutter/services.dart';
import 'package:wakelock_plus_platform_interface/wakelock_plus_platform_interface.dart';

const MethodChannel _channel = MethodChannel('tizen/wakelock_plugin');

/// A Tizen implementation of [WakelockPlusPlatformInterface].
class WakelockPlusTizen extends WakelockPlusPlatformInterface {
  /// Registers this class as the default platform implementation.
  static void register() {
    WakelockPlusPlatformInterface.instance = WakelockPlusTizen();
  }

  @override
  Future<void> toggle({required bool enable}) async {
    await _channel.invokeMethod<void>('toggle', enable);
  }

  @override
  Future<bool> get enabled async =>
      await _channel.invokeMethod<bool>('isEnabled') ?? false;
}
