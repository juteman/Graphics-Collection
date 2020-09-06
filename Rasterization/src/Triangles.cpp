#include "Renderer.h"
#include <algorithm>

namespace
{
inline float QuadraticEquation(Pos &start, Pos &end, Pos &point)
{
    return (start.y - end.y) * point.x + (end.x - start.x) * point.y + start.x * end.y -
           end.x * start.y;
}

} // namespace

void Renderer::Triangles(Point2 &vertex1, Point2 &vertex2, Point2 &vertex3)
{
    int   xMin = std::min(std::min(vertex1.pos.x, vertex2.pos.x), vertex3.pos.x);
    int   xMax = std::max(std::max(vertex1.pos.x, vertex2.pos.x), vertex3.pos.x);
    int   yMin = std::min(std::min(vertex1.pos.y, vertex2.pos.y), vertex3.pos.y);
    int   yMax = std::max(std::min(vertex1.pos.y, vertex2.pos.y), vertex3.pos.y);
    Pos   outside{-1, -1};
    float alphaDenominator = QuadraticEquation(vertex2.pos, vertex3.pos, vertex1.pos);
    float alphaDirection = alphaDenominator * QuadraticEquation(vertex2.pos, vertex3.pos, outside);
    float betaDenominator = QuadraticEquation(vertex3.pos, vertex1.pos, vertex2.pos);
    float betaDirection = betaDenominator * QuadraticEquation(vertex3.pos, vertex1.pos, outside);
    float gamaDemonimator = QuadraticEquation(vertex1.pos, vertex2.pos, vertex3.pos);
    float gamaDirection = gamaDemonimator * QuadraticEquation(vertex1.pos, vertex2.pos, outside);
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
            if (alpha >= 0 && beta >= 0 && gama > 0)
            {
                if ((alpha > 0 || alphaDirection > 0) && (beta > 0 || betaDirection > 0) &&
                    (gama > 0 || gamaDirection > 0))
                {
                    float sample = 0.0f;
                    for (int i = 0; i < 2; i++)
                    {
                        for (int j = 0; j < 2; j++)
                        {

                            Pos   samplePoint = {x + 0.25 + i * 0.5f, y + 0.25 + j * 0.5f};
                            float tempA =
                                float(QuadraticEquation(vertex2.pos, vertex3.pos, samplePoint)) /
                                float(alphaDenominator);
                            float tempB =
                                float(QuadraticEquation(vertex3.pos, vertex1.pos, samplePoint)) /
                                float(betaDenominator);
                            float tempC = 1 - tempA - tempB;
                            if (alpha >= 0.0 && beta >= 0.0 && gama >= 0.0f)
                            {
                                sample += 0.25f;
                            }
                        }
                    }
                    temp.color.r = (vertex1.color.r * alpha + vertex2.color.r * beta +
                                    vertex3.color.r * gama) *
                                   sample;
                    temp.color.g = (vertex1.color.g * alpha + vertex2.color.g * beta +
                                    vertex3.color.g * gama) *
                                   sample;
                    temp.color.b = (vertex1.color.b * alpha + vertex2.color.b * beta +
                                    vertex3.color.b * gama) *
                                   sample;
                    temp.color.a = (vertex1.color.a * alpha + vertex2.color.a * beta +
                                    vertex3.color.a * gama) *
                                   sample;
                    Pixel(temp);
                }
            }
        }
}
