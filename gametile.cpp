#include "button.hpp"
#include <string>
#include <iostream>

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

    if(_display == 'o')
    {
        gout << color(20,10,150);
        for(int i = -_sizex; i < _sizex; i++)
        {
            for(int j = -_sizey; j < _sizey; j++)
            {
                if(i*i+j*j > _sizex*2 && i*i+j*j < _sizex*5) gout << move_to(_x+_sizex/2+i, _y+_sizey/2+j) << dot;
            }
        }

//        gout << color(20,10,150)
//             << move_to(_x+(_sizex-gout.twidth(_title))/2, _y+(_sizey-gout.cascent()-gout.cdescent())/2)
//             << text(_display);
    }
}

void Game_tile::logic(genv::event& ev)
{
    if(ev.button == btn_left && _display == ' ')
    {
        _press = true;
        _display = 'o';
        _title = std::string(1,_display);
    }

    else if(ev.button == -btn_left)
        _press = false;
}
