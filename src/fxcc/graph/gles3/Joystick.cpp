#include "fxcc/graph/Joystick.h"

bool Ogl::Gut::Joystick::KeyStates(int k, int t)
{
    if (btns == 0)
    {
        return false;
    }
    if (numAxes > t)
    {
        return btns[k] == t;
    }
    return false;
}

bool Ogl::Gut::Joystick::KeyPressing(int k)
{
    return KeyStates(k, GLFW_PRESS);
}
bool Ogl::Gut::Joystick::KeyRelease_(int k)
{
    return KeyStates(k, GLFW_RELEASE);
}

void Ogl::Gut::Joystick::OnJoystick(int joy, int event)
{
}

void Ogl::Gut::Joystick::OnAxis(const float* a, int count)
{
    this->axes = new float[count];

    memcpy(this->axes, a, sizeof(float) * count);
    this->numAxes = count;

}


void Ogl::Gut::Joystick::OnButton(const unsigned char* btn, int count)
{
    this->numBtns = count;

    if (this->btns != 0 && btn != 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (this->btns[i] != btn[i])
            {
                Event e;
                e.type = btn[i];
                e.btn = i;
                this->evs.push_back(e);
            }
        }
    }

    this->btns = new unsigned char[count];
    memcpy(this->btns, btn, sizeof(unsigned char) * count);

}

void Ogl::Gut::Joystick::OnClearEvent()
{
    evs.clear();
}

bool Ogl::Gut::Joystick::KeyEvent_(int key, int e)
{
    for (const auto& s : evs)
    {
        if ((key == s.btn) && (e = s.type))
        {
            return true;
        }
    }
    return false;
}
