



#include "fxcc/platform/common/App.h"
using namespace fxcc::platform;
using namespace fxcc::platform::common;

#ifdef FXCC_USE_PLATFORM_GLFW
#include "fxcc/platform/glfw/App.h"
using Platform = glfw::App;
#endif

#ifdef FXCC_USE_PLATFORM_WIN32
#include "fxcc/platform/win32/App.h"
using Platform = win32::App;
#endif

#ifdef FXCC_USE_PLATFORM_SDL2
#include "fxcc/platform/sdl2/App.h"
using Platform = sdl2::App;
#undef main

#endif

#ifdef FXCC_USE_PLATFORM_SDL3
#include "fxcc/platform/sdl3/App.h"
using Platform = sdl3::App;
#endif


int main()
{
    typename fxcc::platform::common::App::Desc desc;
    desc.m_Pos = glm::ivec2(100, 100);
    desc.m_Size = glm::ivec2(800, 600);
    desc.m_Title = "Test Open window";
    desc.m_ScaleFactor = 1.5f;

    // desc.m_Iconify = true;
    // desc.m_Interval = 0;

    auto app = std::make_shared<Platform>(desc);
    if (!app->Init())
    {
        ztclog::info("failed init window");
        return 1;
    }

    return app->Run();
}
