#include "Renderer.h"
#include <algorithm>

namespace
{
inline int QuadraticEquation(Pos &start, Pos &end, Pos &point)
{
    return (start.y - end.y) * point.x + (end.x - start.x) * point.y + start.x * end.y -
           end.x * start.y;
}
} // namespace

void Renderer::Triangles(Point2 &vertex1, Point2 &vertex2, Point2 &vertex3)
{
    int xMin = std::min(std::min(vertex1.pos.x, vertex2.pos.x), vertex3.pos.x);
    int xMax = std::max(std::max(vertex1.pos.x, vertex2.pos.x), vertex3.pos.x);
    int yMin = std::min(std::min(vertex1.pos.y, vertex2.pos.y), vertex3.pos.y);
    int yMax = std::max(std::min(vertex1.pos.y, vertex2.pos.y), vertex3.pos.y);
    Pos outside{-1, -1};
    int alphaDenominator = QuadraticEquation(vertex2.pos, vertex3.pos, vertex1.pos);
    int alphaDirection = alphaDenominator * QuadraticEquation(vertex2.pos, vertex3.pos, outside);
    int betaDenominator = QuadraticEquation(vertex3.pos, vertex1.pos, vertex2.pos);
    int betaDirection = betaDenominator * QuadraticEquation(vertex3.pos, vertex1.pos, outside);
    int gamaDemonimator = QuadraticEquation(vertex1.pos, vertex2.pos, vertex3.pos);
    int gamaDirection = gamaDemonimator * QuadraticEquation(vertex1.pos, vertex2.pos, outside);
    for (int x = xMin; x <= xMax; x++)
        for (int y = yMin; y <= yMax; y++)
        {
            Point2 temp{};
            temp.pos.x = x;
            temp.pos.y = y;
            float alpha = float(QuadraticEquation(vertex2.pos, vertex3.pos, temp.pos)) /
                          float(alphaDenominator);
            float beta = float(QuadraticEquation(vertex3.pos, vertex1.pos, temp.pos)) /
                         float(betaDenominator);
            float gama = 1.0f - alpha - beta;
            if (alpha >= 0 && beta >= 0 && gama >= 0)
            {
                if ((alpha > 0 || alphaDirection > 0) && (beta > 0 || betaDirection > 0) &&
                    (gama > 0 || gamaDirection > 0))
                {
                    temp.color.r =
                        vertex1.color.r * alpha + vertex2.color.r * beta + vertex3.color.r * gama;
                    temp.color.g =
                        vertex1.color.g * alpha + vertex2.color.g * beta + vertex3.color.g * gama;
                    temp.color.b =
                        vertex1.color.b * alpha + vertex2.color.b * beta + vertex3.color.b * gama;
                    temp.color.a =
                        vertex1.color.a * alpha + vertex2.color.a * beta + vertex3.color.a * gama;
                    Pixel(temp);
                }

            }
        }
}
