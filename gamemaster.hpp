#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "gamewindow.hpp"
#include "player.hpp"
#include "window.hpp"
#include "gameboard.hpp"
#include <iostream>

using namespace std;

class Game_master
{
protected:
    bool _game_over;
    bool _winner;
    bool _exit;
    Player* _p1;
    Player* _pc;
    Player* _in_turn;
    Game_window * gw;
    std::vector<std::vector<char>> _board_slots;

public:
    Game_master()
    {
        _game_over = false;
        _winner = false;
        _exit = false;
        _p1 = new Player('o', "Player");
        _pc = new Player('x', "PC");
        _in_turn = _p1;
        gw = new Game_window(this, _in_turn);
    }

    void game_start()
    {
        gw->setup();
        while(!_game_over && !_winner && !_exit && genv::gin)
        {
            gw->event_loop();
        }
        cout << "winner " << _in_turn->get_name() << endl;

    }

    bool check_for_winner()
    {
        short mark_count_row = 0;
        short mark_count_col = 0;
        short mark_count_leftacross = 0;
        short mark_count_rightacross = 0;
        for(int i = 2; i < gw->get_dim()-2; i++)
        {
            for(int j = 2; j < gw->get_dim()-2; j++)
            {
                if(_board_slots[i][j] == _in_turn->get_mark())
                {
                    for(int k = -2; k <= 2; k++)
                    {
                        std::vector<char> colvec;
                        for(int l = -2; l <= 2; l++)
                        {
                            if(_board_slots[i+k][j+l] == _in_turn->get_mark()) mark_count_row++;
                            if(_board_slots[i+l][j+k] == _in_turn->get_mark()) mark_count_col++;
                            if(_board_slots[i+l][j+l] == _in_turn->get_mark()) mark_count_leftacross++;
                            if(_board_slots[i-l][j+l] == _in_turn->get_mark()) mark_count_rightacross++;
                        }
                        if(mark_count_row == 5 || mark_count_col == 5 || mark_count_leftacross == 5 || mark_count_rightacross == 5) return true;
                        else
                        {
                            mark_count_row = 0;
                            mark_count_col = 0;
                            mark_count_leftacross = 0;
                            mark_count_rightacross = 0;
                        }
                    }
                }
            }
        }
        return false;
    }

    void next_turn(){
        if(_in_turn == _p1) _in_turn = _pc;
        else if(_in_turn == _pc) _in_turn = _p1;
    }
    void log_turn(int r, int c, char v)
    {
        _board_slots[r][c] = v;
        if(!check_for_winner()) next_turn();
        else _winner = true;
        gw->set_in_turn_player(_in_turn);
    }

    void close_game() {_exit = true;}
    void fill_slots(int dim)
    {
        _board_slots.clear();
        for(int i = 0; i < dim; i++)
        {
            std::vector<char> _cvec(dim, ' ');
            _board_slots.push_back(_cvec);
        }
    }

    Player* player_in_turn(){return _in_turn;}

};


#endif // GAMEMASTER_HPP
