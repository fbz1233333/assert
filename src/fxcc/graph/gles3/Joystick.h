#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {


        struct Joystick
        {

            enum Btn
            {
                A = 0,
                B = 1,
                X = 2,
                Y = 3,
                LB = 4,
                RB = 5,
                BACK = 6,
                START = 7,
                LP = 8,
                RP = 9,
                UP = 10,
                RIGHT = 11,
                DOWN = 12,
                LEFT = 13,
            };


            struct Event
            {
                int btn;
                int type;
            };

            int numAxes = 0;
            int numBtns = 0;


            float* axes;
            unsigned char* btns;

            Joystick()
            {
                axes = new float[20];
                btns = new unsigned char[20];
            }
            ~Joystick()
            {
                delete[] axes;
                delete[] btns;
            }
            std::vector<Event> evs;

            bool KeyStates(int k, int t);

            bool KeyPressing(int k);

            bool KeyRelease_(int k);

            void OnJoystick(int joy, int e);

            void OnAxis(const float* a, int count);

            void OnButton(const unsigned char* btn, int count);
            

            void OnClearEvent();


            bool KeyEvent_(int key, int e);

        };

    }
};