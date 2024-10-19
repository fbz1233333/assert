#include "fxcc/platform/win32/App.h"

using namespace fxcc::platform;
using namespace fxcc::platform::win32;

win32::App::App(const common::App::Desc& desc)
	:common::App(desc)
{

}

bool win32::App::Init()
{

	return true;
}