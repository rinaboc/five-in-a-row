#include "gamemaster.hpp"
#include <vector>

using namespace std;

Game_master::Game_master()
{
    _game_over = false;
    _exit = false;
    _p1 = new Player('o', "P1");
    _pc = new Player('x', "P2");
    _in_turn = _p1;
    gw = new Game_window(this, _in_turn);
    mm = new Main_menu(this);
    vs = new Victory_screen(this);

    ew = _ewindow::MAIN;
    _active_window = mm;

}

void Game_master :: game_start()
{
    Setup();
    while(!_exit && genv::gin)
        _active_window->event_loop();
}

void Game_master :: Setup() const
{
    gout.open(XX,YY);
    gout << color(30,0,50)
         << move_to(0,0)
         << box(XX, YY)
         << refresh;

    gout << font("LiberationSans-Regular.ttf", 20);
}

void Game_master :: change_active_window(_ewindow ewin)
{
    ew = ewin;
    if(ew == _ewindow::MAIN) _active_window = mm;
    if(ew == _ewindow::GAME) _active_window = gw;
    if(ew == _ewindow::END) _active_window = vs;
}

void Game_master :: retry()
{
    fill_slots(gw->get_dim());
    gw->clear_board();
}

bool Game_master :: check_for_winner() const
{
    vector<int> counts (4,0);

    for(int i = 2; i < gw->get_dim()-2; i++)
        for(int j = 2; j < gw->get_dim()-2; j++)
            if(_board_slots[i][j] == _in_turn->get_mark())
                for(int k = -2; k <= 2; k++)
                {
                    for(int l = -2; l <= 2; l++)
                    {
                        if(_board_slots[i+k][j+l] == _in_turn->get_mark()) counts[0]++;
                        if(_board_slots[i+l][j+k] == _in_turn->get_mark()) counts[1]++;
                        if(_board_slots[i+l][j+l] == _in_turn->get_mark()) counts[2]++;
                        if(_board_slots[i-l][j+l] == _in_turn->get_mark()) counts[3]++;
                    }

                    for(int& count: counts) if(count == 5) return true;

                    fill(counts.begin(), counts.end(), 0);
                }
    return false;
}

void Game_master :: next_turn(){
    if(_in_turn == _p1) _in_turn = _pc;
    else if(_in_turn == _pc) _in_turn = _p1;
}

void Game_master :: log_turn(int r, int c, char v)
{
    _board_slots[r][c] = v;
    if(!check_for_winner()) next_turn();
    else
    {
        vs->update_winner();
        change_active_window(_ewindow::END);
    }
    gw->set_in_turn_player(_in_turn);
}

void Game_master :: fill_slots(int dim)
{
    _board_slots.clear();
    for(int i = 0; i < dim; i++)
    {
        std::vector<char> _cvec(dim, ' ');
        _board_slots.push_back(_cvec);
    }
}
