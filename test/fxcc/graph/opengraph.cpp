#include "fxcc/graph/opengl3/App.h"

int main()
{
	ztclog::setFunction([](const ztclog::Line& line) {
		if (line.m_Type != ztclog::Line::Type::_line_debug_)
		{
			std::cout << line.m_Text << std::endl;
		}
		});

	using _App = fxcc::graph::opengl3::App;
	using _Desc = fxcc::platform::common::App::Desc;

	_Desc desc;
	desc.m_Pos = glm::ivec2(100, 100);
	desc.m_Size = glm::ivec2(800, 600);
	desc.m_ScaleFactor = 1.5f;

	desc.m_Title = "test graph";
	std::shared_ptr<_App> _app = std::make_shared<_App>(desc);

	if (!_app->Init())
	{
		ztclog::info("failed init graph app");
		return 1;
	}

	return _app->Run();

}