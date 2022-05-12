#include "gamewindow.hpp"
#include "gamemaster.hpp"

using namespace genv;

Main_menu::Main_menu(Game_master* gm)
{
    _start = false;
    master = gm;
    play = new FButton(this, 250, 200, 340, 50, "play", [=](){master->retry(); this->start_game();});
    exit = new FButton(this, 250, 400, 150, 50, "exit", [=](){master->close_game(); _start = true;});
    boardoption1 = new FButton(this, 250, 300, 100, 50, "15x15", [=](){master->change_boardsize(15);});
    boardoption2 = new FButton(this, 370, 300, 100, 50, "18x18", [=](){master->change_boardsize(18);});
    boardoption3 = new FButton(this, 490, 300, 100, 50, "25x25", [=](){master->change_boardsize(25);});

}

void Main_menu::event_loop()
{
    for(Widget* w: _widgets)
    {
        w->draw();
    }
    gout << refresh;

    event ev;
    while(gin >> ev && !_start)
    {
        gout << color(30,0,50)
             << move_to(0,0)
             << box(900, 700);

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

        for(Widget* w: _widgets)
            w->draw();

        gout << refresh;
    }
    _start = false;
}