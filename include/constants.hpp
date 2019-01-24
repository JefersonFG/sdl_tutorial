#pragma once

namespace sdl_tutorial {

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Surface image paths
const char* X_OUT = "res/x.bmp";
const char* DEFAULT_PRESS_IMAGE_PATH = "res/press.bmp";
const char* UP_PRESS_IMAGE_PATH = "res/up.bmp";
const char* DOWN_PRESS_IMAGE_PATH= "res/down.bmp";
const char* LEFT_PRESS_IMAGE_PATH= "res/left.bmp";
const char* RIGHT_PRESS_IMAGE_PATH = "res/right.bmp";

// Key press surface constants
enum KeyPressConstants
{
  DEFAULT,
  UP,
  DOWN,
  LEFT,
  RIGHT,
  TOTAL
};

}
