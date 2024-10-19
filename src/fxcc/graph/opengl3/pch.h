#pragma once

#include "fxcc/platform/common/pch.h"

#include <glad/glad.h>

#define FXCC_BUILD_GRAPH_OPENGL3_FAILED(x) if(!x) return false
#define FXCC_BUILD_GRAPH_OPENGL3_SUCCESE(x) if(!x) return true
#define FXCC_BUILD_GRAPH_OPENGL3_BREAK(x) if(!x) return