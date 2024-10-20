#pragma once

#include "fxcc/platform/common/App.h"
using namespace fxcc::platform;
using namespace fxcc::platform::common;

#ifdef FXCC_USE_PLATFORM_GLFW
#include "fxcc/platform/glfw/App.h"
using PlatformApp = glfw::App;
#endif

#ifdef FXCC_USE_PLATFORM_WIN32
#include "fxcc/platform/win32/App.h"
using PlatformApp = win32::App;
#endif

#ifdef FXCC_USE_PLATFORM_SDL2
#include "fxcc/platform/sdl2/App.h"
using PlatformApp = sdl2::App;
#undef main

#endif

#ifdef FXCC_USE_PLATFORM_SDL3
#include "fxcc/platform/sdl3/App.h"
using PlatformApp = sdl3::App;
#endif

