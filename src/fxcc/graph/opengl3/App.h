#pragma once

#include "fxcc/graph/opengl3/pch.h"
#include "fxcc/platform/glfw/App.h"

namespace fxcc
{
	namespace graph
	{

		namespace opengl3
		{
			struct App :public fxcc::platform::glfw::App
			{
				App(const fxcc::platform::common::App::Desc& desc);

				virtual bool Init() override;

				void OnSwapBuffer() override;
		
			public:
			
				void OnFrameRender() override;
			};
		}
	}
}