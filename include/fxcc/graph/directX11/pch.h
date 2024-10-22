#pragma once

#include "fxcc/platform/common/pch.h"

#include <glad/glad.h>

#define FXCC_BUILD_GRAPH_DIRECTX11_FAILED(x) if(!x) return false
#define FXCC_BUILD_GRAPH_DIRECTX11_SUCCESE(x) if(!x) return true
#define FXCC_BUILD_GRAPH_DIRECTX11_BREAK(x) if(!x) return