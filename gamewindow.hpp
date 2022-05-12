#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP


#include "player.hpp"
#include "statictext.hpp"
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
    StaticText* info1;
    StaticText* info2;
    
public:
    Game_window(Game_master *, Player *);

    void event_loop() override;
    void set_in_turn_player(Player* p){_in_turn = p;}
    int get_dim(){return gb->get_dim();}
    void set_dim(int);

    void clear_board(){gb->clear();};

//    void output_data() override{};
};

class Main_menu : public Window
{
protected:
    Game_master * master;
    FButton* play;
    FButton* exit;
    FButton* boardoption1;
    FButton* boardoption2;
    FButton* boardoption3;
    StaticText* text;
public:
    Main_menu(Game_master*);

    void event_loop() override;
//    void start_game(){_start = true;};
};

class Victory_screen : public Window
{
protected:
    Game_master * master;
    StaticText * winner;
    FButton * mainmenu;
    FButton * exit;
public:
    Victory_screen(Game_master*);

    void event_loop() override;
    void update_winner();
};

#endif // GAMEWINDOW_HPP
