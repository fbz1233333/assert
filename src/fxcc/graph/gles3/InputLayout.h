#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct VertexAttr {

            unsigned int index;
            int size;
            int type;
            bool normalized;
            int stride;
            const void* pointer;

            void Use() const
            {

                if (type == GL_FLOAT ) {
                    glVertexAttribPointer(
                        index,
                        size,
                        type,
                        normalized ? GL_TRUE : GL_FALSE,
                        stride,
                        pointer
                    );
                }
                else if (type == GL_INT || type == GL_UNSIGNED_INT || type == GL_SHORT || type == GL_UNSIGNED_SHORT) {
                    glVertexAttribIPointer(
                        index,
                        size,
                        type,
                        stride,
                        pointer
                    );
                }
                glEnableVertexAttribArray(index);

            }
        };
        struct InputLayout
        {

            std::vector<VertexAttr> m_VertexAttrs;
            InputLayout() = default;
            InputLayout(const std::vector<VertexAttr>& va) :m_VertexAttrs(va)
            {

            }
            void Use() const
            {
                for (const auto& it : m_VertexAttrs)
                {
                    it.Use();
                }
            }
        };
    };
};

