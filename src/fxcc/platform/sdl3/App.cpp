#include "fxcc/platform/sdl3/App.h"

using namespace fxcc::platform::sdl3;
using namespace fxcc::platform;

sdl3::App::App(const common::App::Desc& desc)
	:common::App(desc), m_SDLwindow(0)
{

}

bool sdl3::App::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        printf("Error: SDL_Init(): %s\n", SDL_GetError());
        return false;
    }

    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // Create m_SDLwindow with graphics context
    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    //SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);


    glm::ivec2 wndPos = m_Desc.GetGflwPos();
    glm::ivec2 wndSize = m_Desc.GetGflwSize();

    Uint32 m_SDLwindow_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
    m_SDLwindow = SDL_CreateWindow(m_Desc.m_Title.c_str(),  wndSize.x, wndSize.y, m_SDLwindow_flags);

    if (m_SDLwindow == nullptr)
    {
        ztclog::warn("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return false;
    }


    SDL_SetWindowPosition(m_SDLwindow, wndPos.x, wndPos.y);
    m_GLcontext= SDL_GL_CreateContext(m_SDLwindow);
    SDL_GL_MakeCurrent(m_SDLwindow, m_GLcontext);
    SDL_GL_SetSwapInterval(m_Desc.m_Interval); // Enable vsync
    SDL_ShowWindow(m_SDLwindow);

	return true;
}

int sdl3::App::Run()
{

    bool running = true;
    SDL_Event ev;
    while (running) {
        while (SDL_PollEvent(&ev) != 0) {

            switch (ev.type)
            {
            case SDL_EVENT_QUIT:
            {
                running = false;
            }
            break;

            case SDL_EVENT_JOYSTICK_ADDED: {
                int joystickIndex = ev.jdevice.which;
                SDL_Joystick* joystick = SDL_OpenJoystick(joystickIndex);
                if (joystick) {
                    int numButtons = SDL_GetNumJoystickButtons(joystick);
                    std::cout << "Joystick connected: " << SDL_GetJoystickName(joystick)
                        << " with " << numButtons << " buttons." << std::endl;
                    m_Joysticks.push_back(joystick);
                    m_Input.JoysticCallback(joystickIndex, 1, SDL_GetJoystickName(joystick));

                }

            }; break;

            case SDL_EVENT_JOYSTICK_REMOVED: {
                int joystickIndex = ev.jdevice.which;
                std::cout << "Joystick disconnected: " << joystickIndex << std::endl;
                if (joystickIndex >= 0 && joystickIndex < m_Joysticks.size()) {
                    SDL_CloseJoystick(m_Joysticks[joystickIndex]);
                    m_Joysticks.erase(m_Joysticks.begin() + joystickIndex);
                    m_Input.JoysticCallback(joystickIndex, 0, 0);

                };
            }; break;

            case SDL_EVENT_JOYSTICK_HAT_MOTION:
            {
                int joystickIndex = ev.jhat.which; 
                int hatIndex = ev.jhat.hat;
                Uint8 hatValue = ev.jhat.value; 

                glm::ivec2 direction(0);

                switch (hatValue) {
                case SDL_HAT_CENTERED:
                    direction = glm::ivec2(0, 0);
                    break;
                case SDL_HAT_UP:
                    direction = glm::ivec2(0, 1);
                    break;
                case SDL_HAT_DOWN:
                    direction = glm::ivec2(0, -1);
                    break;
                case SDL_HAT_LEFT:
                    direction = glm::ivec2(-1, 0);
                    break;
                case SDL_HAT_RIGHT:
                    direction = glm::ivec2(1, 0);
                    break;
                case SDL_HAT_RIGHTUP:
                    direction = glm::ivec2(1, 1);
                    break;
                case SDL_HAT_RIGHTDOWN:
                    direction = glm::ivec2(1, -1);
                    break;
                case SDL_HAT_LEFTUP:
                    direction = glm::ivec2(-1, 1);
                    break;
                case SDL_HAT_LEFTDOWN:
                    direction = glm::ivec2(-1, -1);
                    break;
                default:
                    break;
                }

                m_Input.SetJoystickHat(joystickIndex, direction.x, direction.y);

            }
                break;
            case SDL_EVENT_JOYSTICK_AXIS_MOTION:
            {
                int joystickIndex = ev.jaxis.which;
                int axisIndex = ev.jaxis.axis;
                int axisValue = ev.jaxis.value;

                m_Input.SetJoystickAxes(joystickIndex, axisIndex, (float)axisValue / (float)32767);
            }
            break;

            case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
            {
                int joystickIndex = ev.jbutton.which;
                int buttonIndex = ev.jbutton.button;
                //std::cout << "Joystick " << joystickIndex << " button " << buttonIndex << " pressed." << std::endl;
                m_Input.SetJoystickButton(joystickIndex, CallBacks::m_JoystickMap[buttonIndex], ActionType::Down);
            }
            break;
            case SDL_EVENT_JOYSTICK_BUTTON_UP:
            {
                int joystickIndex = ev.jbutton.which;
                int buttonIndex = ev.jbutton.button;
                //std::cout << "Joystick " << joystickIndex << " button " << buttonIndex << " released." << std::endl;
                m_Input.SetJoystickButton(joystickIndex, CallBacks::m_JoystickMap[buttonIndex], ActionType::Up);

            }
            break;
            case SDL_EVENT_KEY_DOWN:
            {
                int scancode = ev.key.scancode;
                KeyCode keyCode = CallBacks::m_KeyMap[scancode];
                if (ev.key.key == SDLK_RSHIFT)
                {
                    keyCode == KeyCode::RIGHTSHIFT;
                }
                m_Input.KeyCallback(keyCode, ActionType::Down);
            }
            break;
            case SDL_EVENT_KEY_UP:
            {
                int scancode = ev.key.scancode;
                KeyCode keyCode = CallBacks::m_KeyMap[scancode];
                if (ev.key.key == SDLK_RSHIFT)
                {
                    keyCode == KeyCode::RIGHTSHIFT;
                }
                m_Input.KeyCallback(keyCode, ActionType::Up);
            }
            break;
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                m_Input.MouseCallBack(CallBacks::m_MouseMap[ev.button.button], ActionType::Down);
                break;
            case SDL_EVENT_MOUSE_BUTTON_UP:
                m_Input.MouseCallBack(CallBacks::m_MouseMap[ev.button.button], ActionType::Up);
                break;
            case SDL_EVENT_MOUSE_MOTION:
            {
                int x, y;
                x = ev.motion.x;
                y = ev.motion.y;
                m_Input.CursorPos(x, y);
            }

            break;
            case SDL_EVENT_MOUSE_WHEEL:
            {
                m_Input.Scroll(ev.wheel.x, ev.wheel.y);
            }
            break;

            default:
                break;

            }
        }
    };

    OnDestory();
	return 0;
}

void sdl3::App::OnDestory()
{
    SDL_DestroyWindow(m_SDLwindow);
    SDL_Quit();

}
