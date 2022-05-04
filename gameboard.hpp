#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "button.hpp"
#include "window.hpp"
#include <vector>

class Game_master;

class Gameboard : public Widget
{
protected:
    int _game_dimensions;
    int _grid_size;
    const int _grid_line;
    std::vector<std::vector<Game_tile*>> _tiles;
    Game_master * _gm;

public:
    Gameboard(Window*, int, int, int, int, int, Game_master*);

    void draw() override;

    void logic(genv::event&) override{};

    void action(Game_tile*);
};



#endif // GAMEBOARD_HPP
