#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace ztclog
{
    struct Line
    {
        enum Type
        {
            _line_none_ = 0,
            _line_error_,
            _line_warn_,
            _line_info_,
            _line_debug_,
        } m_Type;
        std::string m_Text;
        Line() : m_Type(_line_info_)
        {
        }
    };

    struct Cache
    {
        std::vector<Line> m_Lines;

        template <typename... Args>
        std::string Format(const char *format, Args &&...args)
        {
            char buffer[512];
            int num = std::sprintf(buffer, format, std::forward<Args>(args)...);
            return buffer;
        }

        template <typename... Args>
        void Row(const ztclog::Line::Type &type, const char *format, Args &&...args)
        {
            Row(type, Format(format, std::forward<Args>(args)...));
        };

        template <typename... Args>
        void Info(const char *format, Args &&...args)
        {
            Row(ztclog::Line::Type::_line_info_, Format(format, std::forward<Args>(args)...));
        };
        template <typename... Args>
        void Debug(const char *format, Args &&...args)
        {
            Row(ztclog::Line::Type::_line_debug_, Format(format, std::forward<Args>(args)...));
        };
        template <typename... Args>
        void Error(const char *format, Args &&...args)
        {
            Row(ztclog::Line::Type::_line_error_, Format(format, std::forward<Args>(args)...));
        };

        template <typename... Args>
        void Warn(const char *format, Args &&...args)
        {
            Row(ztclog::Line::Type::_line_warn_, Format(format, std::forward<Args>(args)...));
        };

        void Row(const Line &row)
        {
            this->m_Lines.push_back(row);
        }

        void Row(const ztclog::Line::Type &type, const std::string &text)
        {
            Line line;
            line.m_Type = type;
            line.m_Text = text;
            Row(line);
        }

        static Cache &Inst()
        {
            static Cache res;
            return res;
        }
    };

    template <typename... Args>
    inline void debug(const char *format, Args &&...args)
    {
        ztclog::Cache::Inst().Debug(format, std::forward<Args>(args)...);
    };

    template <typename... Args>
    inline void info(const char *format, Args &&...args)
    {
        ztclog::Cache::Inst().Info(format, std::forward<Args>(args)...);
    };

    template <typename... Args>
    inline void warn(const char *format, Args &&...args)
    {
        ztclog::Cache::Inst().Warn(format, std::forward<Args>(args)...);
    };

    template <typename... Args>
    inline void error(const char *format, Args &&...args)
    {
        ztclog::Cache::Inst().Error(format, std::forward<Args>(args)...);
    };
}