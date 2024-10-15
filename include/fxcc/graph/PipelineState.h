#pragma once

namespace fxcc
{
    namespace graph
    {
        enum DepthStencilType
        {
        };

        enum BlendType
        {
        };
        enum RasterizerType
        {
        };
        
        struct PipelineState
        {
            RasterizerType m_RasterizerType;
            BlendType m_BlendType;
            DepthStencilType m_DepthStencilType;
        };
    };
};