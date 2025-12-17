#pragma once
#include "Tile.hpp"
#include <vector>
#include <SDL3/SDL.h>

class Grid {
private:
    Tile* tiles[4][4];

public:
    Grid();
    void addRandomTile();
    void render(SDL_Renderer* renderer) const;
};
