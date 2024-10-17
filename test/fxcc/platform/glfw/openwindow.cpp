#include "fxcc/platform/glfw/App.h"

using namespace fxcc::platform;

using TestImpl = glfw::Impl;
using AppImpl = App<TestImpl>;
using FactoryImpl = fxcc::platform::Factory<TestImpl>;

int main()
{
    std::shared_ptr<FactoryImpl> factory = std::make_shared<FactoryImpl>();
    core::AppDesc desc;
    desc.m_Pos = glm::ivec2(100, 100);
    desc.m_Size=glm::ivec2(800,600);
    desc.m_Title = "Test Open window ";

    auto app = factory->CreateApp(desc);
    if(!app->Init())
    {
        ztclog::info("failed init window");
        return 1;
    }

    return app->Run();

}