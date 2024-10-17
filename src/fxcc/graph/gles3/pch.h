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
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/common.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <filesystem>

#include "wtclog/Logger.h"

    namespace fs = std::filesystem;


#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>


#define COLOR_NONE         "\033[m"
#define COLOR_RED          "\033[0;32;31m"
#define COLOR_LIGHT_RED    "\033[1;31m"
#define COLOR_GREEN        "\033[0;32;32m"
#define COLOR_LIGHT_GREEN  "\033[1;32m"
#define COLOR_BLUE         "\033[0;32;34m"
#define COLOR_LIGHT_BLUE   "\033[1;34m"
#define COLOR_DARY_GRAY    "\033[1;30m"
#define COLOR_CYAN         "\033[0;36m"
#define COLOR_LIGHT_CYAN   "\033[1;36m"
#define COLOR_PURPLE       "\033[0;35m"
#define COLOR_LIGHT_PURPLE "\033[1;35m"
#define COLOR_BROWN        "\033[0;33m"
#define COLOR_YELLOW       "\033[1;33m"
#define COLOR_LIGHT_GRAY   "\033[0;37m"
#define COLOR_WHITE        "\033[1;37m"


#ifdef _WIN32

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif

#ifdef __linux__

#define GLAD_GL_IMPLEMENTATION 
#include <GLES3/gl3.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <unistd.h>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifdef __ANDROID__
#include <android/GUT_LOG.h>
#include <android_native_app_glue.h>
#include <android/asset_manager.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#define GUT_LOGI(fmt, ...) __android_GUT_LOG_print(ANDROID_GUT_LOG_INFO,"info", fmt  , ##__VA_ARGS__)
#define GUT_LOGE(fmt, ...) __android_GUT_LOG_print(ANDROID_GUT_LOG_INFO,"error", fmt  , ##__VA_ARGS__)
#define GUT_LOGD(fmt, ...) __android_GUT_LOG_print(ANDROID_GUT_LOG_INFO,"debug",  fmt , ##__VA_ARGS__)
#define GUT_LOGW(fmt, ...) __android_GUT_LOG_print(ANDROID_GUT_LOG_INFO,"warning",  fmt , ##__VA_ARGS__)

#else

#endif
#endif

#pragma warning(disable: 4305)
#pragma warning(disable: 4005)
#pragma warning(disable: 4244)


namespace Ogl
{
	namespace Gut
	{
        inline void Load(const aiColor3D& source, glm::vec3& target)
        {
            target.x = source.r;
            target.y = source.g;
            target.z = source.b;
        };

        inline void Load(const aiColor4D& source, glm::vec4& target)
        {
            target.x = source.r;
            target.y = source.g;
            target.z = source.b;
            target.w = source.a;
        };

        inline void Load(const aiVector3D& source, glm::vec3& target)
        {
            target.x = source.x;
            target.y = source.y;
            target.z = source.z;
        };
        inline void Load(const aiVector2D& source, glm::vec2& target)
        {
            target.x = source.x;
            target.y = source.y;
        };

        inline void Load(const aiQuaternion& source, glm::quat& target)
        {
            target.x = source.x;
            target.y = source.y;
            target.z = source.z;
            target.w = source.w;
        };
        inline void Load(const aiMatrix4x4& source, glm::mat4& target)
        {
            memcpy(&target, &source, sizeof(glm::mat4));
            target = glm::transpose(target);

        }
        inline void Load(const aiString& source, std::string& target)
        {
            target = source.C_Str();
        }
	}
}

#ifdef _WIN32

#pragma comment(lib, "legacy_stdio_definitions.lib")

#endif // 

