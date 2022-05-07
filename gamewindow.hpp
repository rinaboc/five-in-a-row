#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP


#include "player.hpp"
#include "window.hpp"
#include "gameboard.hpp"

class Game_master;

class Game_window : public Window
{
protected:
    Game_master * master;
    Gameboard* gb;
    Button* retry;
    Button* settings;
    Button* exit;
    Player* _in_turn;

public:
    Game_window(Game_master * m, Player * p)
    {
        master = m;
        gb = new Gameboard(this, 50, 50, 18, 30, 2, master);
        retry = new Button(this, 680, 60, 150, 50, "retry");
        settings = new Button(this, 680, 130, 150, 50, "settings");
        exit = new Button(this, 680, 200, 150, 50, "exit");
        _in_turn = p;
    }

    void event_loop() override;
    void set_in_turn_player(Player* p){_in_turn = p;}
    int get_dim(){return gb->get_dim();}
    void setup();
//    void output_data() override{};
};

#endif // GAMEWINDOW_HPP
