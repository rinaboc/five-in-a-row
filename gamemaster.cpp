#include "gamemaster.hpp"
#include <ctime>
#include <cstdlib>
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
    _last_move = {0, 0};

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
    if(_in_turn == _p1)
    {
        _in_turn = _pc;
        PC_player_logic();
    }
    else if(_in_turn == _pc) _in_turn = _p1;
}

void Game_master :: log_turn(int r, int c, char v)
{
    _board_slots[r][c] = v;
    _last_move = {r, c};
    if(!check_for_winner()) next_turn();
    else
    {
        vs->update_winner();
        change_active_window(_ewindow::END);
    }
    gw->set_in_turn_player(_in_turn);
}

void Game_master :: PC_player_logic()
{
    vector<int> counts (8,0);
    char mark = _p1->get_mark();
    int y = _last_move[0];
    int x = _last_move[1];
    for(int i = 1; i < 3; i++)
    {
        // row
        if(_board_slots[y][x+i] == mark) counts[2]++;
        if(_board_slots[y][x-i] == mark) counts[6]++;

        // col
        if(_board_slots[y+i][x] == mark) counts[4]++;
        if(_board_slots[y-i][x] == mark) counts[0]++;

        // across
        if(_board_slots[y+i][x+i] == mark) counts[3]++;
        if(_board_slots[y-i][x-i] == mark) counts[7]++;

        if(_board_slots[y+i][x-i] == mark) counts[5]++;
        if(_board_slots[y-i][x+i] == mark) counts[1]++;
    }
    bool found = false;
    for(int i = 0; i < int(counts.size()); i++)
    {
        if(counts[i] == 2)
        {
            if(i == 0 && _board_slots[y-3][x] == ' ')
            {
                gw->toggle_gametile(y-3, x);
                found = true;
            }
            if(i == 1 && _board_slots[y-3][x+3] == ' ')
            {
                gw->toggle_gametile(y-3, x+3);
                found = true;
            }
            if(i == 2 && _board_slots[y][x+3] == ' ')
            {
                gw->toggle_gametile(y, x+3);
                found = true;
            }
            if(i == 3 && _board_slots[y+3][x+3] == ' ')
            {
                gw->toggle_gametile(y+3, x+3);
                found = true;
            }
            if(i == 4 && _board_slots[y+3][x] == ' ')
            {
                gw->toggle_gametile(y+3, x);
                found = true;
            }
            if(i == 5 && _board_slots[y+3][x-3] == ' ')
            {
                gw->toggle_gametile(y+3, x-3);
                found = true;
            }
            if(i == 6 && _board_slots[y][x-3] == ' ')
            {
                gw->toggle_gametile(y, x-3);
                found = true;
            }
            if(i == 7 && _board_slots[y-3][x-3] == ' ')
            {
                gw->toggle_gametile(y-3, x-3);
                found = true;
            }
        }
    }
    if(found) return;

//    vector<int> counts (4,0);

//    bool found_place = false;
//    for(int i = 2; i < gw->get_dim()-2; i++)
//        for(int j = 2; j < gw->get_dim()-2; j++)
//            if(_board_slots[i][j] == _p1->get_mark() && !found_place)
//            {
//                for(int k = -2; k <= 2; k++)
//                {
//                    for(int l = -2; l <= 2; l++)
//                    {
//                        if(_board_slots[i+k][j+l] == _p1->get_mark())
//                        {
//                            // rows
//                            counts[0]++;
//                            if(counts[0] == 3)
//                            {
//                                if(l == 0 && _board_slots[i+k][j+l+1] == ' ')
//                                {
//                                    gw->toggle_gametile(i+k, j+l+1);
//                                    found_place = true;
//                                }
//                                else if(l == 0 && _board_slots[i+k][j+l-3] == ' ')
//                                {
//                                    gw->toggle_gametile(i+k, j+l-3);
//                                    found_place = true;
//                                }
//                            }
//                        }
//                        if(_board_slots[i+l][j+k] == _p1->get_mark())
//                        {
//                            // cols
//                            counts[1]++;
//                            if(counts[1] == 3)
//                            {
//                                if(l == 0 && _board_slots[i+l+1][j+k] != ' ')
//                                {
//                                    gw->toggle_gametile(i+l+1, j+k);
//                                    found_place = true;
//                                }
//                                if(l == 0 && _board_slots[i+l-3][j+k] != ' ')
//                                {
//                                    gw->toggle_gametile(i+l-3, j+k);
//                                    found_place = true;
//                                }
//                            }
//                        }
//                        if(_board_slots[i+l][j+l] == _p1->get_mark()) counts[2]++;
//                        if(_board_slots[i-l][j+l] == _p1->get_mark()) counts[3]++;
//                        if(found_place) return;
//                    }

//                    fill(counts.begin(), counts.end(), 0);
//                }
//            }



    while(!found)
    {
        srand(time(0));
        int randi = rand() % 5 - 2;
        int randj = rand() % 5 - 2;
        if(_board_slots[y+randi][x+randj] == ' ')
        {
            gw->toggle_gametile(y+randi, x+randj);
            found = true;
        }
    }
//    for(int i = -2; i <= 2; i++)
//    {
//        for(int j = -2; j <= 2; j++)
//        if(_board_slots[y+i][x+j] == ' ')
//        {
//            gw->toggle_gametile(y+i, x+j);
//            return;
//        }
//    }

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
