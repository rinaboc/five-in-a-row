#include "button.hpp"

using namespace genv;

void Button::logic(genv::event& ev)
{
    if(ev.button == btn_left)
        _press = true;
    else if(ev.button == -btn_left)
        _press = false;
}

void Button::draw() const
{
    if(_in_focus)
    {
        gout << color(240,240,255)
             << move_to(_x-_selection_line, _y-_selection_line)
             << box(_sizex+2*_selection_line, _sizey+2*_selection_line);
    }

    if(_press)
    {
        gout << color(140, 140, 255)
             << move_to(_x, _y)
             << box(_sizex, _sizey);
    }

    else
    {
        gout << color(120, 80, 120)
             << move_to(_x, _y)
             << box(_sizex, _sizey);
    }

    gout
        << color(240,240,255)
        << move_to(_x+(_sizex-gout.twidth(_title))/2, _y+(_sizey-(gout.cdescent()+gout.cascent()))/2)
        << text(_title);

}
