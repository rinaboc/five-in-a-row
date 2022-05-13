#include "statictext.hpp"

using namespace genv;

void StaticText::draw() const
{
    gout << color(240,240,255)
         << move_to(_x+(_sizex-gout.twidth(_text))/2, _y+(_sizey-(gout.cdescent()+gout.cascent()))/2)
         << text(_text);
}
