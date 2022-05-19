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

Gameboard :: ~Gameboard()
{
    for(std::vector<Game_tile*>& gtvec : _tiles)
        for(Game_tile*& gt : gtvec)
        {
            _w->delete_widget(gt);
            gt = 0;
        }
    _tiles.clear();
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

char Gameboard::get_player_char() const
    {return _gm->player_in_turn()->get_mark();}


void Gameboard :: clear()
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

void Gameboard::toggle_tile(int i, int j)
{
    _tiles[i][j]->toggle_action();
}

void Gameboard::draw() const
{
    title_draw();
    gout << color(200,200,200)
         << move_to(_x, _y)
         << box(_sizex, _sizey);
}
