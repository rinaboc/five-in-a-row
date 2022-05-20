#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "gamewindow.hpp"
#include "player.hpp"
#include "gameboard.hpp"

enum class _ewindow {MAIN, GAME, END};

class Game_master
{
protected:
    const int XX = 900;
    const int YY = 700;
    const int default_font_size = 20;
    bool _game_over;
    bool _exit;
    int _counter;

    Player* _p1;
    Player* _pc;
    Player* _in_turn;

    Game_window * gw;
    Main_menu * mm;
    Victory_screen * vs;

    _ewindow ew;
    Window* _active_window;

    std::vector<std::vector<char>> _board_slots;

public:
    Game_master();

    void game_start();
    void Setup() const;
    void retry();
    void fill_slots(int);
    bool check_for_winner() const;
    void next_turn();
    void log_turn(int, int, char);

    void close_game() {_exit = true;}
    void change_active_window(_ewindow);
    void change_boardsize(int a) {gw->set_dim(a);}
    Player* player_in_turn() const {return _in_turn;}
    int get_xx()const {return XX;}
    int get_yy()const {return YY;}
    int get_f_size()const {return default_font_size;}
    int get_board_dim()const;
    int get_counter() const {return _counter;}

};


#endif // GAMEMASTER_HPP
