/*
 * MIT License
 *
 * Copyright (C) 2021-2023 by wangwenx190 (Yuhang Zhao)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <QtCore/qglobal.h>
#include <QtCore/qmath.h>
#include <QtCore/qpoint.h>
#include <QtCore/qsize.h>
#include <QtCore/qobject.h>
#include <QtCore/qpointer.h>
#include <QtGui/qcolor.h>
#include <QtGui/qwindowdefs.h>
#include <functional>
#include <optional>
#include <memory>

QT_BEGIN_NAMESPACE
class QEvent;
class QEnterEvent;
QT_END_NAMESPACE

#ifndef FRAMELESSHELPER_CORE_API
#  ifdef FRAMELESSHELPER_CORE_STATIC
#    define FRAMELESSHELPER_CORE_API
#  else // !FRAMELESSHELPER_CORE_STATIC
#    ifdef FRAMELESSHELPER_CORE_LIBRARY
#      define FRAMELESSHELPER_CORE_API Q_DECL_EXPORT
#    else // !FRAMELESSHELPER_CORE_LIBRARY
#      define FRAMELESSHELPER_CORE_API Q_DECL_IMPORT
#    endif // FRAMELESSHELPER_CORE_LIBRARY
#  endif // FRAMELESSHELPER_CORE_STATIC
#endif // FRAMELESSHELPER_CORE_API

#if (defined(Q_OS_WIN) && !defined(Q_OS_WINDOWS))
#  define Q_OS_WINDOWS // Since 5.14
#endif

#ifndef Q_DISABLE_COPY_MOVE // Since 5.13
#  define Q_DISABLE_COPY_MOVE(Class) \
      Q_DISABLE_COPY(Class) \
      Class(Class &&) = delete; \
      Class &operator=(Class &&) = delete;
#endif

#if (QT_VERSION < QT_VERSION_CHECK(5, 10, 0))
   using QStringView = const QString &;
#endif

#if (QT_VERSION < QT_VERSION_CHECK(5, 14, 0))
#  define qExchange(a, b) std::exchange(a, b)
#endif

#ifndef Q_NAMESPACE_EXPORT // Since 5.14
#  define Q_NAMESPACE_EXPORT(...) Q_NAMESPACE
#endif

// QColor can't be constexpr before 5.14
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
#  define Q_COLOR_CONSTEXPR constexpr
#else
#  define Q_COLOR_CONSTEXPR
#endif

// MOC can't handle C++ attributes before 5.15.
#if (QT_VERSION >= QT_VERSION_CHECK(5, 15, 0))
#  define Q_NODISCARD [[nodiscard]]
#  define Q_MAYBE_UNUSED [[maybe_unused]]
#else
#  define Q_NODISCARD
#  define Q_MAYBE_UNUSED
#endif

#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
   using QT_NATIVE_EVENT_RESULT_TYPE = qintptr;
   using QT_ENTER_EVENT_TYPE = QEnterEvent;
#else
   using QT_NATIVE_EVENT_RESULT_TYPE = long;
   using QT_ENTER_EVENT_TYPE = QEvent;
#endif

#ifndef QUtf8String
#  define QUtf8String(str) QString::fromUtf8(str)
#endif

#ifndef Q_GADGET_EXPORT // Since 6.3
#  define Q_GADGET_EXPORT(...) Q_GADGET
#endif

#if (QT_VERSION >= QT_VERSION_CHECK(6, 4, 0))
  using namespace Qt::Literals::StringLiterals;
#endif

#ifndef FRAMELESSHELPER_BYTEARRAY_LITERAL
#  if (QT_VERSION >= QT_VERSION_CHECK(6, 4, 0))
#    define FRAMELESSHELPER_BYTEARRAY_LITERAL(ba) ba##_ba
#  elif (QT_VERSION >= QT_VERSION_CHECK(6, 2, 0))
#    define FRAMELESSHELPER_BYTEARRAY_LITERAL(ba) ba##_qba
#  else
#    define FRAMELESSHELPER_BYTEARRAY_LITERAL(ba) QByteArrayLiteral(ba)
#  endif
#endif

#ifndef FRAMELESSHELPER_STRING_LITERAL
#  if (QT_VERSION >= QT_VERSION_CHECK(6, 4, 0))
#    define FRAMELESSHELPER_STRING_LITERAL(str) u##str##_s
#  elif (QT_VERSION >= QT_VERSION_CHECK(6, 2, 0))
#    define FRAMELESSHELPER_STRING_LITERAL(str) u##str##_qs
#  else
#    define FRAMELESSHELPER_STRING_LITERAL(str) QStringLiteral(str)
#  endif
#endif

#ifndef Q_UNREACHABLE_RETURN // Since 6.5
#  define Q_UNREACHABLE_RETURN(...) \
     do { \
         Q_UNREACHABLE(); \
         return __VA_ARGS__; \
     } while (false)
#endif

#ifndef FRAMELESSHELPER_BYTEARRAY_CONSTANT2
#  define FRAMELESSHELPER_BYTEARRAY_CONSTANT2(name, ba) \
     [[maybe_unused]] static const auto k##name = FRAMELESSHELPER_BYTEARRAY_LITERAL(ba);
#endif

#ifndef FRAMELESSHELPER_STRING_CONSTANT2
#  define FRAMELESSHELPER_STRING_CONSTANT2(name, str) \
     [[maybe_unused]] static const auto k##name = FRAMELESSHELPER_STRING_LITERAL(str);
#endif

#ifndef FRAMELESSHELPER_BYTEARRAY_CONSTANT
#  define FRAMELESSHELPER_BYTEARRAY_CONSTANT(ba) FRAMELESSHELPER_BYTEARRAY_CONSTANT2(ba, #ba)
#endif

#ifndef FRAMELESSHELPER_STRING_CONSTANT
#  define FRAMELESSHELPER_STRING_CONSTANT(str) FRAMELESSHELPER_STRING_CONSTANT2(str, #str)
#endif

#ifndef FRAMELESSHELPER_NAMESPACE
#  define FRAMELESSHELPER_NAMESPACE wangwenx190::FramelessHelper
#endif

#ifndef FRAMELESSHELPER_BEGIN_NAMESPACE
#  define FRAMELESSHELPER_BEGIN_NAMESPACE namespace FRAMELESSHELPER_NAMESPACE {
#endif

#ifndef FRAMELESSHELPER_END_NAMESPACE
#  define FRAMELESSHELPER_END_NAMESPACE }
#endif

#ifndef FRAMELESSHELPER_USE_NAMESPACE
#  define FRAMELESSHELPER_USE_NAMESPACE using namespace FRAMELESSHELPER_NAMESPACE;
#endif

#ifndef FRAMELESSHELPER_PREPEND_NAMESPACE
#  define FRAMELESSHELPER_PREPEND_NAMESPACE(X) ::FRAMELESSHELPER_NAMESPACE::X
#endif

#ifndef FRAMELESSHELPER_MAKE_VERSION
#  define FRAMELESSHELPER_MAKE_VERSION(Major, Minor, Patch) \
     ((((Major) & 0xff) << 24) | (((Minor) & 0xff) << 16) | (((Patch) & 0xff) << 8))
#endif

#ifndef FRAMELESSHELPER_EXTRACT_VERSION
#  define FRAMELESSHELPER_EXTRACT_VERSION(Version, Major, Minor, Patch) \
     { \
         (Major) = (((Version) & 0xff) >> 24); \
         (Minor) = (((Version) & 0xff) >> 16); \
         (Patch) = (((Version) & 0xff) >> 8); \
     }
#endif

#ifndef FRAMELESSHELPER_CORE_NO_BUNDLE_RESOURCE
// Call this function in your main() function if you are using FramelessHelper as a static library,
// it can make sure the resources bundled in the static library are correctly initialized.
// NOTE: This function is intentionally not inside any namespaces.
FRAMELESSHELPER_CORE_API void framelesshelpercore_initResource();
#endif // FRAMELESSHELPER_CORE_NO_BUNDLE_RESOURCE

FRAMELESSHELPER_BEGIN_NAMESPACE

#include "framelesshelper.version"

[[maybe_unused]] inline constexpr const int FRAMELESSHELPER_VERSION =
      FRAMELESSHELPER_MAKE_VERSION(
          FRAMELESSHELPER_VERSION_MAJOR,
          FRAMELESSHELPER_VERSION_MINOR,
          FRAMELESSHELPER_VERSION_PATCH);

namespace Global
{

Q_NAMESPACE_EXPORT(FRAMELESSHELPER_CORE_API)

[[maybe_unused]] inline constexpr const int kDefaultResizeBorderThickness = 8;
[[maybe_unused]] inline constexpr const int kDefaultCaptionHeight = 23;
[[maybe_unused]] inline constexpr const int kDefaultTitleBarHeight = 32;
[[maybe_unused]] inline constexpr const int kDefaultExtendedTitleBarHeight = 48;
[[maybe_unused]] inline constexpr const int kDefaultWindowFrameBorderThickness = 1;
[[maybe_unused]] inline constexpr const int kDefaultTitleBarFontPointSize = 11;
[[maybe_unused]] inline constexpr const int kDefaultTitleBarContentsMargin = 10;
[[maybe_unused]] inline constexpr const int kMacOSChromeButtonAreaWidth = 60;
[[maybe_unused]] inline constexpr const QSize kDefaultWindowIconSize = {16, 16};
// We have to use "qRound()" here because "std::round()" is not constexpr, yet.
[[maybe_unused]] inline constexpr const QSize kDefaultSystemButtonSize = {qRound(qreal(kDefaultTitleBarHeight) * 1.5), kDefaultTitleBarHeight};
[[maybe_unused]] inline constexpr const QSize kDefaultSystemButtonIconSize = kDefaultWindowIconSize;
[[maybe_unused]] inline constexpr const QSize kDefaultWindowSize = {160, 160}; // Value taken from Windows QPA.

#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
#  define kDefaultBlackColor QColorConstants::Black
#  define kDefaultWhiteColor QColorConstants::White
#  define kDefaultTransparentColor QColorConstants::Transparent
#  define kDefaultDarkGrayColor QColorConstants::DarkGray
#else // (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
   [[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultBlackColor = {0, 0, 0}; // #000000
   [[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultWhiteColor = {255, 255, 255}; // #FFFFFF
   [[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultTransparentColor = {0, 0, 0, 0};
   [[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultDarkGrayColor = {169, 169, 169}; // #A9A9A9
#endif // (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))

[[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultSystemLightColor = {240, 240, 240}; // #F0F0F0
[[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultSystemDarkColor = {32, 32, 32}; // #202020
[[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultFrameBorderActiveColor = {77, 77, 77}; // #4D4D4D
[[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultFrameBorderInactiveColorDark = {87, 89, 89}; // #575959
[[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultFrameBorderInactiveColorLight = {166, 166, 166}; // #A6A6A6
[[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultSystemButtonBackgroundColor = {204, 204, 204}; // #CCCCCC
[[maybe_unused]] inline Q_COLOR_CONSTEXPR const QColor kDefaultSystemCloseButtonBackgroundColor = {232, 17, 35}; // #E81123

[[maybe_unused]] inline const QByteArray kDontOverrideCursorVar
    = FRAMELESSHELPER_BYTEARRAY_LITERAL("FRAMELESSHELPER_DONT_OVERRIDE_CURSOR");
[[maybe_unused]] inline const QByteArray kDontToggleMaximizeVar
    = FRAMELESSHELPER_BYTEARRAY_LITERAL("FRAMELESSHELPER_DONT_TOGGLE_MAXIMIZE");

enum class Option
{
    UseCrossPlatformQtImplementation = 0,
    ForceHideWindowFrameBorder = 1,
    ForceShowWindowFrameBorder = 2,
    DisableWindowsSnapLayout = 3,
    WindowUseRoundCorners = 4,
    CenterWindowBeforeShow = 5,
    EnableBlurBehindWindow = 6,
    ForceNonNativeBackgroundBlur = 7,
    DisableLazyInitializationForMicaMaterial = 8
};
Q_ENUM_NS(Option)

enum class SystemTheme
{
    Unknown = -1,
    Light = 0,
    Dark = 1,
    HighContrast = 2
};
Q_ENUM_NS(SystemTheme)

enum class SystemButtonType
{
    Unknown = -1,
    WindowIcon = 0,
    Help = 1,
    Minimize = 2,
    Maximize = 3,
    Restore = 4,
    Close = 5
};
Q_ENUM_NS(SystemButtonType)

#ifdef Q_OS_WINDOWS
enum class DwmColorizationArea
{
    None = 0,
    StartMenu_TaskBar_ActionCenter = 1,
    TitleBar_WindowBorder = 2,
    All = 3
};
Q_ENUM_NS(DwmColorizationArea)
#endif // Q_OS_WINDOWS

enum class ButtonState
{
    Unspecified = -1,
    Hovered = 0,
    Pressed = 1,
    Clicked = 2
};
Q_ENUM_NS(ButtonState)

#ifdef Q_OS_WINDOWS
enum class WindowsVersion
{
    _2000 = 0,
    _XP = 1,
    _XP_64 = 2,
    _WS_03 = _XP_64, // Windows Server 2003
    _Vista = 3,
    _Vista_SP1 = 4,
    _Vista_SP2 = 5,
    _7 = 6,
    _7_SP1 = 7,
    _8 = 8,
    _8_1 = 9,
    _8_1_Update1 = 10,
    _10_1507 = 11,
    _10_1511 = 12,
    _10_1607 = 13,
    _10_1703 = 14,
    _10_1709 = 15,
    _10_1803 = 16,
    _10_1809 = 17,
    _10_1903 = 18,
    _10_1909 = 19,
    _10_2004 = 20,
    _10_20H2 = 21,
    _10_21H1 = 22,
    _10_21H2 = 23,
    _10_22H2 = 24,
    _10 = _10_1507,
    _11_21H2 = 25,
    _11_22H2 = 26,
    _11 = _11_21H2,
    Latest = _11_22H2
};
Q_ENUM_NS(WindowsVersion)
#endif // Q_OS_WINDOWS

enum class BlurMode
{
    Disable = 0, // Do not enable blur behind window
    Default = 1, // Use platform default blur mode
    Windows_Aero = 2, // Windows only, use the traditional DWM blur
    Windows_Acrylic = 3, // Windows only, use the Acrylic blur
    Windows_Mica = 4, // Windows only, use the Mica material
    Windows_MicaAlt = 5 // Windows only, use the Mica Alt material
};
Q_ENUM_NS(BlurMode)

enum class WallpaperAspectStyle
{
    Fill = 0, // Keep aspect ratio to fill, expand/crop if necessary.
    Fit = 1, // Keep aspect ratio to fill, but don't expand/crop.
    Stretch = 2, // Ignore aspect ratio to fill.
    Tile = 3,
    Center = 4,
    Span = 5 // ???
};
Q_ENUM_NS(WallpaperAspectStyle)

#ifdef Q_OS_WINDOWS
enum class RegistryRootKey
{
    ClassesRoot = 0,
    CurrentUser = 1,
    LocalMachine = 2,
    Users = 3,
    PerformanceData = 4,
    CurrentConfig = 5,
    DynData = 6,
    CurrentUserLocalSettings = 7,
    PerformanceText = 8,
    PerformanceNlsText = 9
};
Q_ENUM_NS(RegistryRootKey)
#endif // Q_OS_WINDOWS

enum class WindowEdge : quint32
{
    Left   = 0x00000001,
    Top    = 0x00000002,
    Right  = 0x00000004,
    Bottom = 0x00000008
};
Q_ENUM_NS(WindowEdge)
Q_DECLARE_FLAGS(WindowEdges, WindowEdge)
Q_FLAG_NS(WindowEdges)
Q_DECLARE_OPERATORS_FOR_FLAGS(WindowEdges)

#ifdef Q_OS_WINDOWS
enum class DpiAwareness
{
    Unknown = -1,
    Unaware = 0,
    System = 1,
    PerMonitor = 2,
    PerMonitorVersion2 = 3,
    Unaware_GdiScaled = 4
};
Q_ENUM_NS(DpiAwareness)
#endif // Q_OS_WINDOWS

enum class WindowCornerStyle
{
    Default = 0,
    Square = 1,
    Round = 2
};
Q_ENUM_NS(WindowCornerStyle)

struct VersionInfo
{
    int version = 0;
    const char *version_str = nullptr;
    const char *commit = nullptr;
    const char *compileDateTime = nullptr;
    const char *compiler = nullptr;
    bool isDebug = false;
    bool isStatic = false;
};

struct Dpi
{
    quint32 x = 0;
    quint32 y = 0;
};

} // namespace Global

namespace FramelessHelper::Core
{
FRAMELESSHELPER_CORE_API void initialize();
FRAMELESSHELPER_CORE_API void uninitialize();
[[nodiscard]] FRAMELESSHELPER_CORE_API Global::VersionInfo version();
FRAMELESSHELPER_CORE_API void setApplicationOSThemeAware();
FRAMELESSHELPER_CORE_API void outputLogo();
} // namespace FramelessHelper::Core

FRAMELESSHELPER_END_NAMESPACE

#ifndef QT_NO_DEBUG_STREAM
QT_BEGIN_NAMESPACE
FRAMELESSHELPER_CORE_API QDebug operator<<(QDebug, const FRAMELESSHELPER_PREPEND_NAMESPACE(Global)::VersionInfo &);
FRAMELESSHELPER_CORE_API QDebug operator<<(QDebug, const FRAMELESSHELPER_PREPEND_NAMESPACE(Global)::Dpi &);
QT_END_NAMESPACE
#endif // QT_NO_DEBUG_STREAM
