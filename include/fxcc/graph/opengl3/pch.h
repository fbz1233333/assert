#pragma once

#include "fxcc/platform/common/pch.h"

#ifdef WIN32
#include <glad/glad.h>
#endif

#if __linux__
#include <GLES3/gl3.h>
#endif

#define FXCC_BUILD_GRAPH_OPENGL3_FAILED(x) if(!x) return false
#define FXCC_BUILD_GRAPH_OPENGL3_SUCCESE(x) if(!x) return true
#define FXCC_BUILD_GRAPH_OPENGL3_BREAK(x) if(!x) return