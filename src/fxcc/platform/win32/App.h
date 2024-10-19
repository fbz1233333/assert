#pragma once

#include "fxcc/platform/common/App.h"
#include "fxcc/platform/win32/pch.h"


namespace fxcc
{
	namespace platform
	{
		namespace win32
		{
			struct App :public fxcc::platform::common::App
			{
				App(const common::App::Desc& desc);

				bool Init();

				int Run() { return 0; };
			};
		}
	}
}