#include "fxcc/graph/Property.h"

using namespace Ogl::Gut;

Property::Property(aiMaterialProperty *property)
{
    Load(property->mKey, m_Key);
    m_Semantic = property->mSemantic;
    m_Index = property->mIndex;
    m_DataLength = property->mDataLength;

    m_Data.resize(m_DataLength);

    memcpy(&m_Type, &property->mType, sizeof(m_Type));
    memcpy(&m_Data[0], property->mData, m_DataLength);

}