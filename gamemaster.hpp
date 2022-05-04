#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "gamewindow.hpp"
#include "window.hpp"
#include "gameboard.hpp"


class Game_master
{
protected:
    bool _game_over;
    bool _exit;
    Game_window * gw;
    std::vector<std::vector<char>> _board_slots;

public:
    Game_master()
    {
        _game_over = false;
        _exit = false;
        gw = new Game_window(this);
    }

    void game_start()
    {
        gw->setup();
        while(!_game_over && !_exit && genv::gin)
        {
            gw->event_loop();
        }

    }

    void log_turn(int r, int c, char ch)
    {
        _board_slots[r][c] = ch;
//        for(std::vector<char>& ch : _board_slots)
//        {
//            for(char& cha : ch)
//            {
//                cout << cha << " ";
//            }
//            cout << endl;
//        }
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

};


#endif // GAMEMASTER_HPP
