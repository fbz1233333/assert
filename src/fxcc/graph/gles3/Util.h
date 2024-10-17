#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct Util {

            static std::string getExtension(const std::string &filename);

            static std::string readFile(const std::string &filename);

            static void Write(const std::string &path, const std::string &code);
            
        };
    };
};