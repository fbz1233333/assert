#pragma once

#include "fxcc/graph/common/RenderStateType.h"
#include "fxcc/graph/common/Mesh.h"

struct Effect3d
{
	RenderStateDesc m_RenderStateDesc;

	struct PassData
	{
		glm::mat4 proj, view;
		glm::vec3 camPos;
		float pos;
	};
	struct ObjData
	{
		glm::mat4 world, worldInv, worldInvTranpose;
		glm::vec3 pos;
		float pad;
	};
	virtual void Begin() {
	
		ztclog::warn("begin effect3d has no impl");
	};
	
	virtual void SetPassData(const PassData& passData) = 0;

	virtual void InstMesh(const fxcc::graph::common::Mesh* mesh, const ObjData& objData) = 0;

	virtual void End()
	{
		ztclog::warn("end effect has no impl");
	};

};