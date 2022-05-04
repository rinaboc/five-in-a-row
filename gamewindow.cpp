#include "gamewindow.hpp"
#include "gamemaster.hpp"

using namespace genv;

void Game_window::setup()
{
    for(Widget* w: _widgets)
    {
        w->draw();
    }
    gout << refresh;

}

void Game_window::event_loop()
{
    event ev;
    while(gin >> ev)
    {
        if(ev.keycode == key_escape)
        {
            master->close_game();
            return;
        }

        // torles
        gout << color(30,0,50)
             << move_to(0,0)
             << box(900, 700);

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

        for(Widget* w: _widgets)
            w->draw();

        gout << refresh;
    }
    obj_in_focus->logic(ev);
}
