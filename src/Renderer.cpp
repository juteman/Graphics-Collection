#include "Renderer.h"

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WIDTH, HIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer);
    if (window == nullptr)
    {
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}

void Renderer::Update()
{
    while (true)
    {
        Draw();
        SDL_RenderPresent(renderer);
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        {
            break;
        }
    }
}

void Renderer::Pixel(Vertex &vertex)
{
    SDL_SetRenderDrawColor(
        renderer, vertex.color.r, vertex.color.g, vertex.color.b, vertex.color.a);
    SDL_RenderDrawPoint(renderer, vertex.pos.x, vertex.pos.y);
}

void Renderer::Draw()
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    Vertex start = {{100, 0}, {static_cast<int8>(255), 0, 0, static_cast<int8>(255)}};
    Vertex end = {{100, 900}, {static_cast<int8>(255), 0, 0, static_cast<int8>(255)}};
    Line(start, end);
}

