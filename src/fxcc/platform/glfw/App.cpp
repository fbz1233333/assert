#include "fxcc/platform/glfw/App.h"

using namespace fxcc::platform;

bool App<fxcc::platform::glfw::Impl>::Init()
{
	if (!glfwInit())
	{
		return false;
	}
	return true;
}