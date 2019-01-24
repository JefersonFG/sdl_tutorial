#include <game.hpp>

#include <iostream>

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
  // Loads key press surfaces
  if (!load_image(&key_press_surfaces_[KeyPressConstants::DEFAULT], DEFAULT_PRESS_IMAGE_PATH)) {
    is_running = false;
    return false;
  }

  if (!load_image(&key_press_surfaces_[KeyPressConstants::UP], UP_PRESS_IMAGE_PATH)) {
    is_running = false;
    return false;
  }

  if (!load_image(&key_press_surfaces_[KeyPressConstants::DOWN], DOWN_PRESS_IMAGE_PATH)) {
    is_running = false;
    return false;
  }

  if (!load_image(&key_press_surfaces_[KeyPressConstants::LEFT], LEFT_PRESS_IMAGE_PATH)) {
    is_running = false;
    return false;
  }

  if (!load_image(&key_press_surfaces_[KeyPressConstants::RIGHT], RIGHT_PRESS_IMAGE_PATH)) {
    is_running = false;
    return false;
  }

  // Sets the screen content to the default surface
  screen_content_ = key_press_surfaces_[KeyPressConstants::DEFAULT];
  return true;
}

bool Game::load_image(SDL_Surface** surface, const char* path)
{
  *surface = SDL_LoadBMP(path);

  if (surface == nullptr)
    std::cerr << "Error loading image \"" << path << "\", sdl error: " << SDL_GetError();

  return true;
}

Game::~Game() {
  is_running = false;
  
  for (int i = 0; i < KeyPressConstants::TOTAL; i++)
    SDL_FreeSurface(key_press_surfaces_[i]);

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
    if (event_handler_.type == SDL_QUIT) {
      is_running = false;
    } else if (event_handler_.type == SDL_KEYDOWN) {
      switch (event_handler_.key.keysym.sym) {
        case SDLK_UP:
          screen_content_ = key_press_surfaces_[KeyPressConstants::UP];
          break;
        case SDLK_DOWN:
          screen_content_ = key_press_surfaces_[KeyPressConstants::DOWN];
          break;
        case SDLK_LEFT:
          screen_content_ = key_press_surfaces_[KeyPressConstants::LEFT];
          break;
        case SDLK_RIGHT:
          screen_content_ = key_press_surfaces_[KeyPressConstants::RIGHT];
          break;
        default:
          screen_content_ = key_press_surfaces_[KeyPressConstants::DEFAULT];
          break;
      }
    }
  }
}

}
