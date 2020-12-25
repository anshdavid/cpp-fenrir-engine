#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>

class Display
{
public:
    Display(int width, int height, const std::string &title);
    virtual ~Display();

    bool IsClosed();

    void Clear(float r, float g, float b, float a);

    void Update();

protected:
private:
    Display(const Display &other) {}
    void operator=(const Display &other) {}

    SDL_Window *m_window;
    SDL_GLContext m_glContext;

    bool m_isClosed = true;
};

#endif // __DISPLAY_H__