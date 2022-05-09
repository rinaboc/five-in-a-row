#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP


#include "player.hpp"
#include "window.hpp"
#include "gameboard.hpp"

class Game_master;

class Game_window : public Window
{
protected:
    int dim;
    Game_master * master;
    Gameboard* gb;
    FButton* retry;
    FButton* mainmenu;
    FButton* exit;
    Player* _in_turn;
    
public:
    Game_window(Game_master *, Player *);

    void event_loop() override;
    void set_in_turn_player(Player* p){_in_turn = p;}
    int get_dim(){return gb->get_dim();}
    void setup();
    void set_dim(int);

    void clear_board(){gb->clear();};

//    void output_data() override{};
};

class Main_menu : public Window
{
protected:
    bool _start;
    Game_master * master;
    FButton* play;
    FButton* exit;
    FButton* boardoption1;
    FButton* boardoption2;
    FButton* boardoption3;
public:
    Main_menu(Game_master*);

    void event_loop() override;
    void start_game(){_start = true;};
};

#endif // GAMEWINDOW_HPP
