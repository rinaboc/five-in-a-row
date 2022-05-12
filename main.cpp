#include "graphics.hpp"
#include "gamemaster.hpp"

using namespace genv;

void Setup(int XX, int YY)
{
    gout.open(XX,YY);
    gout << color(30,0,50)
         << move_to(0,0)
         << box(XX, YY)
         << refresh;

    gout << font("LiberationSans-Regular.ttf", 20);
}

int main()
{
    Setup(900,700);
    Game_master gm;
    gm.game_start();

    return 0;
}
