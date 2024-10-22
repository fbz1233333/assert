#pragma once

#include "fxcc/platform/common/Input.h"
#include "fxcc/platform/sdl3/pch.h"

struct CallBacks
{
    static std::unordered_map<int, KeyCode> m_KeyMap;

    static std::unordered_map<int, MouseButton> m_MouseMap;

    static std::unordered_map<int, JoystickButton> m_JoystickMap;


};