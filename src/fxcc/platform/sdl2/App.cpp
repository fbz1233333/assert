#include "fxcc/platform/sdl2/App.h"

using namespace fxcc::platform::sdl2;
using namespace fxcc::platform;

sdl2::App::App(const common::App::Desc& desc)
    :common::App(desc), m_SDLwindow(0)
{

};

bool sdl2::App::Init()
{
    // int SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) < 0) {
        ztclog::warn("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);


    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    //SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    Uint32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
    SDL_Window* m_SDLwindow;
    m_SDLwindow = SDL_CreateWindow(m_Desc.m_Title.c_str(),
        m_Desc.m_Pos.x, m_Desc.m_Pos.y, 
        m_Desc.m_Size.x, m_Desc.m_Size.y, window_flags);

    if (!m_SDLwindow) {
        ztclog::warn("Failed to create m_SDLwindow: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    SDL_SetWindowPosition(m_SDLwindow, m_Desc.m_Pos.x, m_Desc.m_Pos.y);
    m_GLcontext = SDL_GL_CreateContext(m_SDLwindow);
    SDL_GL_MakeCurrent(m_SDLwindow, m_GLcontext);
    SDL_GL_SetSwapInterval(m_Desc.m_Interval); // Enable vsync
    SDL_ShowWindow(m_SDLwindow);

    return true;
};

int sdl2::App::Run()
{

    bool running = true;
    SDL_Event ev;

    while (running) {
        while (SDL_PollEvent(&ev) != 0) {

            switch (ev.type)
            {
            case SDL_QUIT:
            {
                running = false;
            }
            break;
       
            case SDL_JOYDEVICEADDED:
            {
                int joystickIndex = ev.jdevice.which;
                SDL_Joystick* joystick = SDL_JoystickOpen(joystickIndex);
                int numButtons = SDL_JoystickNumButtons(joystick);
                ztclog::info("Number of buttons: %d\n", numButtons);

                if (joystick) {
                    m_Joysticks.push_back(joystick);
                    m_Input.JoysticCallback(joystickIndex, 1, SDL_JoystickName(joystick));
                }

 

            }
            break;
            case SDL_JOYDEVICEREMOVED:
            {
                int joystickIndex = ev.jdevice.which;
                ztclog::info("Joystick disconnected: %d", joystickIndex);
                SDL_JoystickClose(m_Joysticks[joystickIndex]);
                m_Joysticks.erase(m_Joysticks.begin() + joystickIndex);
                m_Input.JoysticCallback(joystickIndex, 0, 0);
            }
            break;

            case SDL_JOYHATMOTION:
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

            };
            break;

            case SDL_JOYAXISMOTION:
            {
                int joystickIndex = ev.jaxis.which;
                int axisIndex = ev.jaxis.axis;
                int axisValue = ev.jaxis.value;
                
                m_Input.SetJoystickAxes(joystickIndex, axisIndex, (float)axisValue / (float)32767);
            }
            break;

            case SDL_JOYBUTTONDOWN:
            {
                int joystickIndex = ev.jbutton.which;
                int buttonIndex = ev.jbutton.button;
                std::cout << "Joystick " << joystickIndex << " button " << buttonIndex << " pressed." << std::endl;
                m_Input.SetJoystickButton(joystickIndex, CallBacks::m_JoystickMap[buttonIndex], ActionType::Down);
            }
            break;
            case SDL_JOYBUTTONUP:
            {
                int joystickIndex = ev.jbutton.which;
                int buttonIndex = ev.jbutton.button;
                m_Input.SetJoystickButton(joystickIndex, CallBacks::m_JoystickMap[buttonIndex], ActionType::Up);

            }
            break;

            case SDL_KEYDOWN:
            {
                int scancode = ev.key.keysym.scancode;
                m_Input.KeyCallback(CallBacks::m_KeyMap[scancode], ActionType::Down);
            }
            break;
            case SDL_KEYUP:
            {
                int scancode = ev.key.keysym.scancode;
                m_Input.KeyCallback(CallBacks::m_KeyMap[scancode], ActionType::Up);
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
                m_Input.MouseCallBack(CallBacks::m_MouseMap[ev.button.button], ActionType::Down);
                break;
            case SDL_MOUSEBUTTONUP:
                m_Input.MouseCallBack(CallBacks::m_MouseMap[ev.button.button], ActionType::Up);
                break;
            case SDL_MOUSEMOTION:
            {
                int x, y;
                x = ev.motion.x;
                y = ev.motion.y;
                m_Input.CursorPos(x, y);
            }

            break;
            case SDL_MOUSEWHEEL:
            {
                m_Input.Scroll(ev.wheel.x, ev.wheel.y);
            }
            break;
            default:
                break;

            }
        };

        //int numJoysticks = SDL_NumJoysticks();
        //ztclog::info("num Joysticks %d", numJoysticks);

    };

    DestroyWindow();
    return 0;
}

void sdl2::App::DestroyWindow()
{
    for (auto joystick : m_Joysticks) {
        SDL_JoystickClose(joystick);
    }

    SDL_DestroyWindow(m_SDLwindow);
    SDL_Quit();

}