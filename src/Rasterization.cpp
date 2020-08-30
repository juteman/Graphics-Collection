// Rasterization.cpp: 定义应用程序的入口点。
//
#define SDL_MAIN_HANDLED
#include "Renderer.h"

using namespace std;

int main()
{
    Renderer renderer;
    renderer.Init();
    renderer.Update();
    return 0;
}
