#include <iostream>

#include "libsuraimuengine/libsuraimuengine.h"

namespace suraimu {

Game::Game(const char *title, int width, int height, bool fullscreen)
    : game_window_title_(title), game_window_width_(width),
      game_window_height_(height), game_window_fullscreen_(fullscreen) {}

Game::~Game() {
  if (game_renderer_) {
    SDL_DestroyRenderer(game_renderer_);
  }

  if (game_window_) {
    SDL_DestroyWindow(game_window_);
  }

  SDL_Quit();
}

int Game::Init() {
  int flags = 0;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "SDL Initialized" << std::endl;
  } else {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    is_initialized_ = false;
    return 1;
  }

  if (game_window_fullscreen_) {
    flags = SDL_WINDOW_FULLSCREEN;
  } else {
    flags = SDL_WINDOW_SHOWN;
  }

  game_window_ = SDL_CreateWindow(game_window_title_, SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, game_window_width_,
                                  game_window_height_, flags);

  if (game_window_ == nullptr) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  game_renderer_ = SDL_CreateRenderer(
      game_window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (game_renderer_ == nullptr) {
    SDL_DestroyWindow(game_window_);
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  is_initialized_ = true;
  return 0;
}

SDL_Renderer *Game::GetRenderer() { return game_renderer_; }

} // namespace suraimu