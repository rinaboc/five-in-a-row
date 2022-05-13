#include "window.hpp"
#include "gamemaster.hpp"

using namespace genv;

void Window::select_widget(Widget *&w)
{
    if(obj_in_focus != nullptr)
        obj_in_focus->toggle_focus();
    w->toggle_focus();
    obj_in_focus = w;
}

void Window::event_loop()
{
    gout << color(30,0,50)
         << move_to(0,0)
         << box(master->get_xx(), master->get_yy());

    for(Widget* w: _widgets)
        w->draw();

    gout << refresh;

    event ev;
    gin >> ev;

    if(ev.keycode == key_escape)
    {
        master->close_game();
        return;
    }

    // kijeloles
    if(ev.button == btn_left)
    {
        bool found = false;
        for(Widget* w: _widgets)
        {
            if(w->is_over(ev.pos_x, ev.pos_y))
            {
                select_widget(w);
                found = true;
            }
        }

        // nem widgetre kattintas
        if(!found && obj_in_focus != nullptr)
        {
            obj_in_focus->toggle_focus();
            obj_in_focus = nullptr;
        }
    }

    // egyeb esemenyek
    if(obj_in_focus != nullptr && (ev.keycode > 0 || ev.type == ev_mouse))
    {
        obj_in_focus->logic(ev);
    }
}

void Window::delete_widget(Widget* w)
{
    std::vector<Widget*> _new_widgets;
    for(Widget* &widget: _widgets)
    {
        if(widget != w) _new_widgets.push_back(widget);
    }
    if(obj_in_focus == w) obj_in_focus = nullptr;

    _widgets = _new_widgets;
}
