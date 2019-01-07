#include <SDL.h>
#include <iostream>

#include "../include/constants.hpp"

int main(int argc, char* args[])
{
  // Declares the main window and its surface
  SDL_Window* window = nullptr;
  SDL_Surface* screen_surface = nullptr;

  // Initializes SDL and the main window
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    std::cerr << "Error initializing SDL: " << SDL_GetError() << "\n";

  window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window == nullptr)
    std::cerr << "Error creating sdl window: " << SDL_GetError() << "\n";

  // Draws a white rectangle to the main window's surface and updates the window
  screen_surface = SDL_GetWindowSurface(window);
  SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(window);

  // Waits for 2s
  SDL_Delay(2000);

  // Destroys the main window and closes SDL
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
