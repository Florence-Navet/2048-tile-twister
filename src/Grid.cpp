#include "Grid.hpp"
#include <cstdlib>
#include <ctime>

Grid::Grid() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tiles[i][j] = nullptr;
}

void Grid::addRandomTile() {
    std::vector<std::pair<int,int>> emptyCells;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tiles[i][j] == nullptr) {
                emptyCells.push_back({i,j});
            }
        }
    }

    if (!emptyCells.empty()) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        auto [i,j] = emptyCells[std::rand() % emptyCells.size()];
        int val = (std::rand() % 2 == 0) ? 2 : 4;
        tiles[i][j] = new Tile(val, i, j);
    }
}

void Grid::render(SDL_Renderer* renderer) const {
    int cellSize = 100;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            SDL_FRect rect;
            rect.x = j * cellSize + 20;
            rect.y = i * cellSize + 20;
            rect.w = cellSize - 10;
            rect.h = cellSize - 10;

            if (tiles[i][j] != nullptr) {
                SDL_SetRenderDrawColor(renderer, 255, 200, 0, 255); // jaune
            } else {
                SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // gris
            }
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}
