#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "button.hpp"
#include "window.hpp"
#include <vector>

using namespace genv;

class Gameboard : public Widget
{
protected:
    int _game_dimensions;
    int _grid_size;
    const int _grid_line;
    std::vector<std::vector<char>> _slots;
    std::vector<std::vector<Game_tile*>> _tiles;

public:
    Gameboard(Window*, int, int, int, int, int);

    void draw() override;

    void logic(event&) override{};
};



#endif // GAMEBOARD_HPP
