#pragma once

#include <SDL.h>

#include <constants.hpp>

namespace sdl_tutorial {

class Game {
public:
  Game() = default;

  bool init();
  bool load();
  void update();
  void handle_events();

  ~Game();

  bool is_running = false;

private:
  bool load_image(SDL_Surface** surface, const char* path);

  SDL_Window* window_ = nullptr;
  SDL_Surface* screen_surface_ = nullptr;
  SDL_Surface* screen_content_ = nullptr;
  SDL_Event event_handler_;

  SDL_Surface* key_press_surfaces_[KeyPressConstants::TOTAL];
};

}
