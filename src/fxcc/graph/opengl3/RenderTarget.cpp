#include "fxcc/graph/opengl3/RenderTarget.h"

using namespace fxcc::graph;

bool RenderTarget<opengl3::Impl>::Create()
{

	return true;
}

void RenderTarget<opengl3::Impl>::Begin()
{

};

void RenderTarget<opengl3::Impl>::End()
{

}

void RenderTarget<opengl3::Impl>::Release()
{

}
fxcc::graph::RenderTarget<opengl3::Impl>::~RenderTarget()
{
	Release();
}
;


