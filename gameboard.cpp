#include "gameboard.hpp"
#include <vector>

Gameboard::Gameboard(Window * w, int x, int y, int dimensions, int grid_size, int grid_line) : Widget(w, x, y, dimensions*grid_size+(dimensions+1)*grid_line, dimensions*grid_size+(dimensions+1)*grid_line, "Five in a row"), _game_dimensions(dimensions), _grid_size(grid_size), _grid_line(grid_line)
{
    for(int i = 0; i < _game_dimensions; i++)
    {
        std::vector<char> s;
        std::vector<Game_tile*> t;
        for(int j = 0; j < _game_dimensions; j++)
        {
            s.push_back(' ');
            t.push_back(new Game_tile(w, _x+_grid_line+j*(_grid_size+_grid_line), _y+_grid_line+i*(_grid_size+_grid_line), _grid_size, _grid_size));
        }
        _slots.push_back(s);
        _tiles.push_back(t);
    }
}

void Gameboard::draw()
{
    title_draw();
    gout << color(200,200,200)
         << move_to(_x, _y)
         << box(_sizex, _sizey);
}
