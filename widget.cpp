#include "widget.hpp"
#include "window.hpp"


Widget::Widget(Window* w, int x, int y, int sizex, int sizey, std::string title) : _w(w), _x(x), _y(y), _sizex(sizex), _sizey(sizey), _title(title)
{
    _in_focus = false;
    _w->add_widget(this);
}

bool Widget::is_over(int ex, int ey) const
{
    return(ex > _x && ey > _y && ex < _x+_sizex && ey < _y+_sizey);
}

void Widget::title_draw() const
{
    genv::gout << genv::color(140, 140, 255)
         << genv::move_to(_x, _y-genv::gout.cascent()-genv::gout.cdescent()*2-_selection_line)
         << genv::text(_title);
}
