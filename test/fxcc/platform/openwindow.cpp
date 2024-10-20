#include "test_config.h"

int main()
{
    ztclog::setFunction([](const ztclog::Line& l) {
        
        std::cout << l.m_Type << " " << l.m_Text << std::endl;
        });
   
    typename fxcc::platform::common::App::Desc desc;
    desc.m_Pos = glm::ivec2(100, 100);
    desc.m_Size = glm::ivec2(800, 600);
    desc.m_Title = "Test Open window";
    desc.m_ScaleFactor = 1.5f;

    // desc.m_Iconify = true;
    // desc.m_Interval = 0;

    auto app = std::make_shared<PlatformApp>(desc);
    if (!app->Init())
    {
        ztclog::info("failed init window");
        return 1;
    }

    return app->Run();
}
