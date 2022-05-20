#include "gamewindow.hpp"
#include "gamemaster.hpp"

Victory_screen::Victory_screen(Game_master* gm)
{
    master = gm;
    winner = new StaticText(this, (master->get_xx() - 340)/2, 260, 340, 40, "", 30);
    mainmenu = new FButton(this, (master->get_xx() - 340)/2, 340, 340, 50, "main menu", [=](){master->retry(); master->change_active_window(_ewindow::MAIN);});
    exit = new FButton(this, (master->get_xx() - 340)/2, 400, 340, 50, "exit", [=](){master->close_game();});

}

void Victory_screen :: update_winner()
{
    if(master->get_counter()+1 == (master->get_board_dim()*master->get_board_dim()))
        winner->change_text("NO WINNER");
    else
        winner->change_text(master->player_in_turn()->get_name() + " WON");
};

