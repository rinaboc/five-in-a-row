#include "gameboard.hpp"
#include "gamemaster.hpp"
#include <vector>

using namespace genv;

Gameboard::Gameboard(Window * w, int x, int y, int dimensions, int grid_size, int grid_line, Game_master* gm) : Widget(w, x, y, dimensions*grid_size+(dimensions+1)*grid_line, dimensions*grid_size+(dimensions+1)*grid_line, "Five in a row"), _game_dimensions(dimensions), _grid_size(grid_size), _grid_line(grid_line)
{
    for(int i = 0; i < _game_dimensions; i++)
    {
        std::vector<Game_tile*> t;
        for(int j = 0; j < _game_dimensions; j++)
        {
            t.push_back(new Game_tile(w, _x+_grid_line+j*(_grid_size+_grid_line), _y+_grid_line+i*(_grid_size+_grid_line), _grid_size, _grid_size, this));
        }
        _tiles.push_back(t);
    }

    _gm = gm;
    gm->fill_slots(_game_dimensions);
}

void Gameboard::action(Game_tile* gt)
{
    for(int i = 0; i < _game_dimensions; i++)
    {
        for(int j = 0; j < _game_dimensions; j++)
        {
            if(_tiles[i][j] == gt) {
                _gm->log_turn(i, j, gt->get_char());
                return;
            }
        }
    }
}

char Gameboard::get_player_char()
{
    return _gm->player_in_turn()->get_mark();
}

void Gameboard::draw()
{
    title_draw();
    gout << color(200,200,200)
         << move_to(_x, _y)
         << box(_sizex, _sizey);
}
