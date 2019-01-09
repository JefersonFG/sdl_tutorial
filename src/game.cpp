#include <game.hpp>

#include <iostream>

#include <constants.hpp>

namespace sdl_tutorial {

bool Game::init() {  
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Error initializing SDL: " << SDL_GetError() << "\n";
    return false;
  }

  window_ = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                             SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window_ == nullptr) {
    std::cerr << "Error creating sdl window: " << SDL_GetError() << "\n";
    return false;
  }

  screen_surface_ = SDL_GetWindowSurface(window_);
  is_running = true;
  return true;
}

bool Game::load() {
  // Loads test image
  screen_content_ = SDL_LoadBMP(X_OUT);

  if (screen_content_ == nullptr) {
    std::cerr << "Error loading screen content:" << SDL_GetError() << "\n";
    is_running = false;
    return false;
  }

  return true;
}

Game::~Game() {
  is_running = false;
  SDL_FreeSurface(screen_content_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

void Game::update() {
  // Draws the test image and updates the window
  SDL_BlitSurface(screen_content_, nullptr, screen_surface_, nullptr);
  SDL_UpdateWindowSurface(window_);
}

void Game::handle_events() {
  while (SDL_PollEvent(&event_handler_) != 0) {
    // Listens for the quit event
    if (event_handler_.type == SDL_QUIT)
      is_running = false;
  }
}

}
