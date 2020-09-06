// Rasterization.cpp: 定义应用程序的入口点。
//
#define SDL_MAIN_HANDLED
#include "Renderer.h"


class Triangle : public Renderer
{
    void Draw() override
    {
        Point2 x1 =  {{200, 200}, {static_cast<int8>(200), 0, 150, static_cast<int8>(255)}};
        Point2 x2 =  {{1000, 200}, {static_cast<int8>(100), 50, 200, static_cast<int8>(255)}};
        Point2 x3 =  {{200, 1000}, {static_cast<int8>(10), 200, 70, static_cast<int8>(255)}};
        Point2 x4 = {{1000, 1000}, {static_cast<int8>(250), 250, 250, static_cast<int8>(255)}};
        Renderer::Triangles(x1, x2, x3);
        Renderer::Triangles(x2, x3, x4);
    }
};


int main()
{
    Triangle test;
    test.Init();
    test.Update();
    return 0;
}
