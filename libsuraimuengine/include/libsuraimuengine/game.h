#ifndef LIBSURAIMUENGINE_GAME_H_INCLUDED
#define LIBSURAIMUENGINE_GAME_H_INCLUDED

#include <SDL.h>
#include <string>

namespace suraimu {

class Game {
public:
  // Constructor
  Game(const char *title = "Game Window", int width = 640, int height = 480,
       bool fullscreen = false);
  
  // Destructor
  ~Game();

  // Initializes SDL
  int Init();

  // Returns a pointer to the SDL renderer
  SDL_Renderer *GetRenderer();

protected:
  const char *game_window_title_;
  const int game_window_width_;
  const int game_window_height_;
  const bool game_window_fullscreen_;

  SDL_Window *game_window_ = nullptr;
  SDL_Renderer *game_renderer_ = nullptr;
  bool is_initialized_ = false;
};

} // namespace suraimu

#endif // LIBSURAIMUENGINE_GAME_H_INCLUDED