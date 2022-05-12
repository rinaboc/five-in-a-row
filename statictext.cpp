#include "statictext.hpp"

using namespace genv;

void StaticText::draw()
{
//    gout << color(80, 80, 120)
//         << move_to(_x, _y)
//         << box(_sizex, _sizey);

    gout << color(240,240,255)
         << move_to(_x+(_sizex-gout.twidth(_title))/2, _y+(_sizey-(gout.cdescent()+gout.cascent()))/2)
         << text(_title);
}
