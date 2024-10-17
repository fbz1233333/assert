#include "fxcc/graph/EffectBase.h"

void Ogl::Gut::EffectBase::Clear()
{

	m_DepthStencilDesc.Clear();
	m_BlendDesc.Clear();
	m_RasterizerDesc.Clear();
}

void Ogl::Gut::EffectBase::Begin()
{
	Clear();
}

void Ogl::Gut::EffectBase::End()
{

}

