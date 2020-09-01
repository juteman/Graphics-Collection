#pragma once
#include "Common.h"
#include "SDL2/SDL.h"

class Renderer
{
  public:
    void Init();
    ~Renderer();
    virtual void Draw();

    /// @brief To draw a pixel on screen
    /// @param vertex  positions and color to draw
    void Pixel(Vertex &vertex);

    //template <LineAlgorithm>
    void Line(Vertex &start, Vertex &end);

    void Update();

  private:
    SDL_Event     event;
    SDL_Renderer *renderer = nullptr;
    SDL_Window *  window = nullptr;
};
