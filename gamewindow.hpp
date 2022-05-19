#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include "player.hpp"
#include "statictext.hpp"
#include "window.hpp"
#include "gameboard.hpp"

class Game_window : public Window
{
protected:
    int dim;
    Gameboard* gb;
    FButton* retry;
    FButton* mainmenu;
    FButton* exit;
    Player* _in_turn;
    StaticText* info1;
    StaticText* info2;
    
public:
    Game_window(Game_master *, Player *);

    void set_in_turn_player(Player* p){_in_turn = p;}
    int get_dim()const {return gb->get_dim();}
    void set_dim(int);
    void toggle_gametile(int i, int j){gb->toggle_tile(i, j);}

    void clear_board() {gb->clear();};
};

class Main_menu : public Window
{
protected:
    FButton* play;
    FButton* exit;
    FButton* boardoption1;
    FButton* boardoption2;
    FButton* boardoption3;
    StaticText* text;
public:
    Main_menu(Game_master*);

};

class Victory_screen : public Window
{
protected:
    StaticText * winner;
    FButton * mainmenu;
    FButton * exit;
public:
    Victory_screen(Game_master*);

    void update_winner();
};

#endif // GAMEWINDOW_HPP
