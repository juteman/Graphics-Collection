#pragma once
#include <cstdint>
#include "eigen3/Eigen/Dense"



const int WIDTH = 1920;
const int HIGHT = 1080;

typedef int8_t int8;

struct Pos
{
    int8 x;
    int8 y;
};

struct Color
{
    int8 r;
    int8 g;
    int8 b;
    int8 a;
};


struct Vertex
{
    Pos   pos;
    Color color;
};