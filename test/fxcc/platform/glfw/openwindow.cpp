



//#include "fxcc/platform/glfw/App.h"
//using namespace fxcc::platform::glfw;
//using PlatformApp = glfw::App;

#include "fxcc/platform/win32/App.h"
using namespace fxcc::platform;
using namespace fxcc::platform::common;

using PlatformApp = win32::App;
using namespace fxcc::platform::win32;

int main()
{
    fxcc::platform::common::App::Desc desc;
    desc.m_Pos = glm::ivec2(100, 100);
    desc.m_Size=glm::ivec2(800, 600);
    desc.m_Title = "Test Open window ";
    //desc.m_Iconify = true;
    //desc.m_Interval = 0;

    auto app = std::make_shared<win32::App>(desc);
    if(!app->Init())
    {
        ztclog::info("failed init window");
        return 1;
    }

    return app->Run();

}