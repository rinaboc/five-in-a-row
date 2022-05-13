#include "gamewindow.hpp"
#include "gamemaster.hpp"

Main_menu::Main_menu(Game_master* gm)
{
    master = gm;
    play = new FButton(this, 250, 200, 340, 50, "play", [=](){master->retry(); master->change_active_window(_ewindow::GAME);
    });
    exit = new FButton(this, 250, 400, 340, 50, "exit", [=](){master->close_game();});
    boardoption1 = new FButton(this, 250, 300, 100, 50, "15x15", [=](){master->change_boardsize(15);});
    boardoption2 = new FButton(this, 370, 300, 100, 50, "18x18", [=](){master->change_boardsize(18);});
    boardoption3 = new FButton(this, 490, 300, 100, 50, "23x23", [=](){master->change_boardsize(23);});
    text = new StaticText(this, 250, 260, 340, 40, "Choose a board size:");

}
