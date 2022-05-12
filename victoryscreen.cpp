#include "gamewindow.hpp"
#include "gamemaster.hpp"

Victory_screen::Victory_screen(Game_master* gm)
{
    master = gm;
    winner = new StaticText(this, 250, 260, 340, 40, "");
    mainmenu = new FButton(this, 250, 340, 340, 50, "main menu", [=](){master->retry(); master->change_active_window(_ewindow::MAIN);});
    exit = new FButton(this, 250, 400, 340, 50, "exit", [=](){master->close_game();});

}

void Victory_screen::event_loop()
{
    gout << color(30,0,50)
         << move_to(0,0)
         << box(900, 700);

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

void Victory_screen :: update_winner()
{
    winner->change_text(master->player_in_turn()->get_name() + " WON");
};

