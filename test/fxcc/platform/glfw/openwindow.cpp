
#define FXCC_TEST_PLATFORM

#include "fxcc/platform/glfw/App.h"

using namespace fxcc::platform::glfw;
using namespace fxcc::platform::common;

int main()
{
    AppDesc desc;
    desc.m_Pos = glm::ivec2(100, 100);
    desc.m_Size=glm::ivec2(800, 600);
    desc.m_Title = "Test Open window ";

    auto app = std::make_shared<App>(desc);
    if(!app->Init())
    {
        ztclog::info("failed init window");
        return 1;
    }

    return app->Run();

}