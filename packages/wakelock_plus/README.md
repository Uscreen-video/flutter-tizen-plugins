
# wakelock_plus_tizen

The Tizen implementation of [`wakelock_plus`](https://pub.dev/packages/wakelock_plus).

## Usage

This package is not an _endorsed_ implementation of `wakelock_plus`. Therefore, you have to include `wakelock_plus_tizen` alongside `wakelock_plus` as dependencies in your `pubspec.yaml` file.

```yaml
dependencies:
  wakelock_plus: ^0.0.1
  wakelock_plus_tizen: ^0.0.1
```

Then you can import `wakelock_plus` in your Dart code:

```dart
import 'package:wakelock_plus/wakelock_plus.dart';
```

For detailed usage, see https://pub.dev/packages/wakelock_plus#usage.

## Required privileges

To use the `wakelock_plus_tizen` plugin in a Tizen application, the display privilege must be added in your `tizen-manifest.xml` file. If you don't know where to place the privilege, see the `example/tizen/tizen-manifest.xml` file.

```xml
<privileges>
  <privilege>http://tizen.org/privilege/display</privilege>
</privileges>
```

## Supported devices

- Samsung Smart TVs (running Tizen)
- Galaxy Watch series (running Tizen 5.5)
