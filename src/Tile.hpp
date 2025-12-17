#pragma once

class Tile {
private:
    int value;
    int x;
    int y;

public:
    Tile(int v, int posX, int posY);

    int getValue() const { return value; }
    int getX() const { return x; }
    int getY() const { return y; }
};
