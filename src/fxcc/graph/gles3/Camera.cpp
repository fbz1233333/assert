#include "fxcc/graph/Camera.h"

Ogl::Gut::Camera::Camera(aiCamera *camera)
{
    Load(camera->mName, m_Name);
    Load(camera->mPosition, m_Position);
    Load(camera->mUp, m_Up);
    Load(camera->mLookAt, m_LookAt);

    m_HorizontalFOV = camera->mHorizontalFOV;
    m_ClipPlaneFar = camera->mClipPlaneFar;
    m_ClipPlaneNear = camera->mClipPlaneNear;
    m_Aspect = camera->mAspect;
};