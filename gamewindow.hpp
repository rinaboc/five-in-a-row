#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include "window.hpp"
#include "gameboard.hpp"

class Game_window : public Window
{
protected:
    Gameboard* gb;
    Button* retry;
    Button* settings;
    Button* exit;
public:
    Game_window()
    {
        gb = new Gameboard(this, 50, 50, 18, 30, 2);
        retry = new Button(this, 680, 60, 150, 50, "retry");
        settings = new Button(this, 680, 130, 150, 50, "settings");
        exit = new Button(this, 680, 200, 150, 50, "exit");
    }

//    void output_data() override{};
};

#endif // GAMEWINDOW_HPP
