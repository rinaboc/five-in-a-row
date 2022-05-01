#include "button.hpp"
#include <string>

using namespace genv;

void Game_tile::draw()
{
    if(_press)
    {
        gout << color(140, 140, 255)
             << move_to(_x, _y)
             << box(_sizex, _sizey);
    }

    else
    {
        gout << color(80, 80, 120)
             << move_to(_x, _y)
             << box(_sizex, _sizey);
    }
}
