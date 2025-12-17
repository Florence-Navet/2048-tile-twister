#pragma once
#include <SDL3/SDL.h>

class GameObject {
 protected:
  int x, y, width, height;

 public:
  GameObject(int x, int y, int width, int height)
      : x(x), y(y), width(width), height(height) {}
  virtual ~GameObject() = default;
  virtual void render(SDL_Renderer* renderer) = 0;
  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
};
