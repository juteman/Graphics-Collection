#include "Renderer.h"

/// @brief Bresenham line: see https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html
/// @param start  The start point of line
/// @param end  The end point of line
template <>
void Renderer::Line<Bresenham_s>(Vertex &start, Vertex &end)
{
    int    delta_x = abs(end.pos.x - start.pos.x);
    int    delta_y = abs(end.pos.y - start.pos.y);
    bool   steep = delta_y > delta_x;
    int    step = ((end.pos.x - start.pos.x) * (end.pos.y - start.pos.y) > 0) ? 1 : -1;
    int    eps = 0;
    Vertex temp{};
    // if steep true,
    if (steep)
    {
        temp = (end.pos.y - start.pos.y > 0) ? start : end;
        int endpoint = temp.pos.y + delta_y;
        while (temp.pos.y <= endpoint)
        {
            Pixel(temp);
            eps += delta_x;
            if ((eps << 1) >= delta_y)
            {
                temp.pos.x += step;
                eps -= delta_y;
            }
            temp.pos.y++;
        }
    }
    else
    {
        temp = (end.pos.x - start.pos.x > 0) ? start : end;
        int endpoint = temp.pos.x + delta_x;
        while (temp.pos.x <= endpoint)
        {
            Pixel(temp);
            eps += delta_y;
            if ((eps << 1) >= delta_x)
            {
                temp.pos.y += step;
                eps -= delta_x;
            }
            temp.pos.x++;
        }
    }
}
