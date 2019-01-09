#include <game.hpp>

using namespace sdl_tutorial;

int main(int, char**)
{
  Game game;

  if (!game.init())
    return -1;
  
  if (!game.load())
    return -1;

  while (game.is_running) {
    game.handle_events();
    game.update();
  }

  return 0;
}
