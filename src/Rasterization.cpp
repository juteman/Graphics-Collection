// Rasterization.cpp: 定义应用程序的入口点。
//
#define SDL_MAIN_HANDLED
#include "Renderer.h"


class Triangle : public Renderer
{
    void Draw() override
    {
        Point2 x =  {{540, 100}, {static_cast<int8>(200), 0, 150, static_cast<int8>(255)}};
        Point2 y =  {{100, 500}, {static_cast<int8>(100), 50, 200, static_cast<int8>(255)}};
        Point2 z =  {{1000, 500}, {static_cast<int8>(20), 200, 70, static_cast<int8>(255)}};
        Renderer::Triangles(x, y, z);
    }
};


int main()
{
    Triangle test;
    test.Init();
    test.Update();
    return 0;
}
