#pragma once

#include "fxcc/graph/pch.h"

namespace fxcc
{
    namespace graph
    {
        struct Image 
        {
            struct HD
            {
                
                int m_Width;
                int m_Height;
                int m_NrComponent;
                int m_Hdr;
                HD() :m_Width(0), m_Height(0), m_NrComponent(0), m_Hdr(false)
                {

                }

                int DataSize() const
                {
                    return m_NrComponent * m_Width * m_Height;
                }
                
            }m_HD;

            void InitHD(int w, int h, int nr, int hdr)
            {
                m_HD.m_Width = w;
                m_HD.m_Height = h;
                m_HD.m_NrComponent = nr;
                m_HD.m_Hdr = hdr;
            };

            void *m_Data = 0;

            void AllocData()
            {
                Free();
                m_Data = new unsigned char[m_HD.DataSize()];
            }

            struct Desc
            {
                std::string m_Path;
                int m_hdr;
                int m_ReqComponent;
                Desc() :m_hdr(false), m_ReqComponent(0)
                {

                }
            } m_Desc;

            void Write(const std::string& path) const;
            
            void Write(std::ofstream& ofs) const;

            void Read(const std::string& path) ;
            
            void Read(std::ifstream& ifs);

            void WriteBMP(const std::string& path) const;

            // int GetDataType() const;

            // int GetFormat() const;

            // int GetInternalFormat() const;

            void *GetData() const;

            void Free();

            void Resize(int w, int h);

            Image() = default;

            Image(const Desc &desc);

            bool m_Avail = false;

            bool Init();
        };
    };
};