#pragma once

#include "fxcc/platform/common/pch.h"

#include <GLFW/glfw3.h>

#define FXCC_BUILD_PLATFORM_GFLW_FAILED(x) if(!x) return false
#define FXCC_BUILD_PLATFORM_GLFW_SUCCESE(x) if(!x) return true
#define FXCC_BUILD_PLATFORM_GLFW_BREAK(x) if(!x) return