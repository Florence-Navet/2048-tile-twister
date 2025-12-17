#include "gridView.hpp"

#include <SDL3/SDL.h>

void GridView::render(SDL_Renderer* renderer) {
  // Draw grid background
  SDL_FRect rect = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height)};
  SDL_SetRenderDrawColor(renderer, 180, 170, 160, 255);
  SDL_RenderFillRect(renderer, &rect);
  // Draw all tiles
  for (auto& tile : tiles) {
    tile.render(renderer);
  }
}
