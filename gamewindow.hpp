#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include "window.hpp"
#include "gameboard.hpp"

class Game_window : public Window
{
protected:
    Gameboard* gb;
public:
    Game_window()
    {
        gb = new Gameboard(this, 50, 50, 18, 30, 2);
    }

//    void output_data() override{};
};

#endif // GAMEWINDOW_HPP
