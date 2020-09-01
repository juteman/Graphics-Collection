// Rasterization.cpp: 定义应用程序的入口点。
//
#define SDL_MAIN_HANDLED
#include "Renderer.h"


int main()
{
    Renderer testrender;
    testrender.Init();
    testrender.Update();
    return 0;
}
