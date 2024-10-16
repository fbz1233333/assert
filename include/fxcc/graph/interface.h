#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <ostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <filesystem>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace fs = std::filesystem;

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "assimp/scene.h"
#include "assimp/Importer.hpp"
#include "assimp/types.h"

#include "ztclog/ztclog.h"


namespace fxcc
{
	namespace graph
	{
		template<typename T>
		struct Mesh;


		template<typename T>
		struct Texture2D;

		template<typename T>
		struct TextureCube;

		template<typename T>
		struct Texture2DArray;

		template<typename T>
		struct Shader;

		template<typename T>
		struct RenderTarget;

		template<typename T>
		struct Effect2d;
		
		template<typename T>
		struct Effect3d;

		template<typename T>
		struct RenderStates;

		template<typename T>
		struct PipelineState;

		template<typename T>
		struct ImEditor;


	}
}