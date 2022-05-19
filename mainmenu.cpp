#include "gamewindow.hpp"
#include "gamemaster.hpp"

Main_menu::Main_menu(Game_master* gm)
{
    master = gm;
    play = new FButton(this, (master->get_xx() - 340)/2, 220, 340, 50, "play", [=](){master->retry(); master->change_active_window(_ewindow::GAME);
    });
    exit = new FButton(this, (master->get_xx() - 340)/2, 400, 340, 50, "exit", [=](){master->close_game();});
    boardoption1 = new FButton(this, (master->get_xx() - 3*100)/2 - 10, 330, 100, 40, "15x15", [=](){master->change_boardsize(15);});
    boardoption2 = new FButton(this, (master->get_xx() - 100)/2, 330, 100, 40, "18x18", [=](){master->change_boardsize(18);});
    boardoption3 = new FButton(this, (master->get_xx() + 100)/2 + 10, 330, 100, 40, "23x23", [=](){master->change_boardsize(23);});
    text = new StaticText(this, (master->get_xx() - 340)/2, 290, 340, 40, "Choose a board size:",20);
    title = new StaticText(this, (master->get_xx() - 340)/2, 150, 340, 50, "FIVE IN A ROW", 50);
}
