#pragma once
#include "Common.h"
#include "Renderer.h"
#include <utility>

/// @brief Bresenham line: see https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html
/// @param start  The start point of line
/// @param end  The end point of line
template <>
void Renderer::Line<Bresenham_s>(Vertex &start, Vertex &end)
{
    bool steep = abs(end.pos.y - start.pos.y) > abs(end.pos.x - start.pos.x);
    // here we changed start and end, but the param is pass by reference
    // TODO: we can define temp variable here
    if (steep)
    {
        std::swap(start.pos.x, start.pos.y);
        std::swap(end.pos.x, end.pos.y);
    }

    if (start.pos.x > end.pos.x)
    {
        std::swap(start.pos.x, end.pos.x);
        std::swap(start.pos.y, end.pos.y);
    }

    int delta_x = start.pos.x - end.pos.x;
    int delta_y = abs(end.pos.y - start.pos.y);
    int eps = 0;
    int ystep = 1;

    if (end.pos.y < start.pos.y)
        ystep = -1;

    for (; start.pos.x <= end.pos.x; start.pos.x++)
    {
        if (steep)
        {
            Vertex                               temp = start;
            std::swap(temp.pos.x, temp.pos.y) £» Pixel(temp);
        }
        else
        {
            Pixel(start)
        }
        eps += delta_y;
        if ((eps << 1) >= delta_x)
        {
            start.pos.y++;
            eps -= delta_x;
        }
    }
}
