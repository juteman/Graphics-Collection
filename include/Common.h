#pragma once
#include <cstdint>

const int WIDTH = 1920;
const int HIGHT = 1080;

typedef int8_t int8;

struct Pos
{
    int x;
    int y;
};

struct Color
{
    int8 r;
    int8 g;
    int8 b;
    int8 a;
};

struct Point2
{
    Pos   pos;
    Color color;
};

enum LineAlgorithm
{
    Bresenham_s,
    WuXiaolin_s
};