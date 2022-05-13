#include "gamewindow.hpp"
#include "gamemaster.hpp"

Victory_screen::Victory_screen(Game_master* gm)
{
    master = gm;
    winner = new StaticText(this, 250, 260, 340, 40, "");
    mainmenu = new FButton(this, 250, 340, 340, 50, "main menu", [=](){master->retry(); master->change_active_window(_ewindow::MAIN);});
    exit = new FButton(this, 250, 400, 340, 50, "exit", [=](){master->close_game();});

}

void Victory_screen :: update_winner()
{
    winner->change_text(master->player_in_turn()->get_name() + " WON");
};

