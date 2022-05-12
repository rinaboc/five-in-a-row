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
    virtual ~Gameboard()
    {
        for(std::vector<Game_tile*>& gtvec : _tiles)
        {
            for(Game_tile*& gt : gtvec)
            {
                _w->delete_widget(gt);
                gt = 0;
            }
        }
        _tiles.clear();
    }

    void draw() override;

    void logic(genv::event&) override{};

    char get_player_char();

    int get_dim(){return _game_dimensions;}

    void clear()
    {
        for(int i = 0; i < _game_dimensions; i++)
        {
            for(int j = 0; j < _game_dimensions; j++)
            {
                _w->delete_widget(_tiles[i][j]);
                _tiles[i][j] = 0;
                _tiles[i][j] = new Game_tile(_w, _x+_grid_line+j*(_grid_size+_grid_line), _y+_grid_line+i*(_grid_size+_grid_line), _grid_size, _grid_size, this);
            }
        }
    }

    void action(Game_tile*);
};



#endif // GAMEBOARD_HPP
