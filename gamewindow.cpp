#include "gamewindow.hpp"
#include "gamemaster.hpp"

Game_window::Game_window(Game_master * m, Player * p)
{
    dim = 18;
    master = m;
    gb = new Gameboard(this, 50, 50, dim, 30, 2, master);
    retry = new FButton(this, 680, 60, 150, 50, "retry", [this](){master->retry();});
    mainmenu = new FButton(this, 680, 130, 150, 50, "main menu", [this](){master->change_active_window(_ewindow::MAIN);});
    exit = new FButton(this, 680, 200, 150, 50, "exit", [this](){master->close_game();});
    _in_turn = p;
    info1 = new StaticText(this, 680, 500, 150, 40, "P1 - circle");
    info2 = new StaticText(this, 680, 540, 150, 40, "P2 - cross");
}

void Game_window::set_dim(int a)
{
    dim = a;
    delete_widget(gb);
    delete gb;
    gb = 0;
    gb = new Gameboard(this, 50, 50, dim, 30 * 18/dim, 2 * 18/dim, master);
}
