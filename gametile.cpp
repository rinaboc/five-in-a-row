#include "button.hpp"
#include "gameboard.hpp"
#include <string>
#include <iostream>

using namespace genv;

void Game_tile::draw()
{
    if(_press)
    {
        gout << color(100, 40, 100)
             << move_to(_x, _y)
             << box(_sizex, _sizey);
    }

    else
    {
        gout << color(120, 80, 120)
             << move_to(_x, _y)
             << box(_sizex, _sizey);
    }

    if(_display == 'o')
    {
        gout << color(50,10,150);
        for(int i = -_sizex; i < _sizex; i++)
        {
            for(int j = -_sizey; j < _sizey; j++)
            {
                if(i*i+j*j > _sizex*2 && i*i+j*j < _sizex*5) gout << move_to(_x+_sizex/2+i, _y+_sizey/2+j) << dot;
            }
        }
    }

    if(_display == 'x')
    {
        int border = 3;
        gout << color(130,10,80);
        for(int i = -border; i < border; i++)
        {
            gout << move_to(_x+border, _y+border+i) << line(_sizex-2*border, _sizey-2*border);
            gout << move_to(_x+border, _y+_sizey-border+i) << line(_sizex-2*border, -_sizey+2*border);
        }
    }
}

void Game_tile::logic(genv::event& ev)
{
    if(ev.button == btn_left && _display == ' ')
    {
        _press = true;
        _display = _parent->get_player_char();
        _title = std::string(1,_display);
        _parent->action(this);
    }

    else if(ev.button == -btn_left)
        _press = false;
}
