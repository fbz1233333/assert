#include "fxcc/graph/AABB.h"

Ogl::Gut::AABB::AABB(const aiAABB& aabb)
{
    Load(aabb.mMax, m_Max);
    Load(aabb.mMin, m_Min);
    CalCenterHalfExt();
}

Ogl::Gut::AABB::AABB(const glm::vec3& minVal, const glm::vec3& maxVal)
    :m_Min(minVal), m_Max(maxVal)
{

}

void Ogl::Gut::AABB::CalCenterHalfExt()
{
    m_Center = (m_Min + m_Max) / 2.0f;
    m_HalfExtends = (m_Max - m_Min) / 2.0f;
}
