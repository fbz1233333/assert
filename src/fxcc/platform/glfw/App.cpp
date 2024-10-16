#include "fxcc/platform/glfw/App.h"

using namespace fxcc::platform;


void App<fxcc::platform::glfw::Impl>::Init()
{
	if (!glfwInit())
	{

	}
}