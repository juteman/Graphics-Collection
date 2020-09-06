#pragma once
#include "Common.h"
#include "Eigen/Dense"
#include "SDL2/SDL.h"
class Renderer
{

  public:
    void Init();
    ~Renderer();
    virtual void Draw();

    /// @brief To draw a pixel on screen
    /// @param vertex  positions and color to draw
    void Pixel(Point2 &vertex);

    /// @brief draw line
    /// @tparam LineType the algorithm to used
    /// @param start  point of line
    /// @param end point of line
    template <LineAlgorithm LineType>
    void Line(Point2 &start, Point2 &end);

    /// @brief draw triangle
    /// @param vertex1 point one
    /// @param vertex2 point two
    /// @param vertex3 point three
    void Triangles(Point2 &vertex1, Point2 &vertex2, Point2 &vertex3);

    void Update();

  private:
    SDL_Event     event;
    SDL_Renderer *renderer = nullptr;
    SDL_Window *  window = nullptr;
};
