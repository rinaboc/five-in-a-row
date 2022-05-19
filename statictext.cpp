#include "statictext.hpp"
#include "window.hpp"

using namespace genv;

void StaticText::draw() const
{
    gout << font("LiberationSans-Regular.ttf", _fontsize);

    gout << color(240,240,255)
         << move_to(_x+(_sizex-gout.twidth(_text))/2, _y+(_sizey-(gout.cdescent()+gout.cascent()))/2)
         << text(_text);

    gout << font("LiberationSans-Regular.ttf", _w->get_f_size());
}
