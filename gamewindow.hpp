#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP


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

public:
    Game_window(Game_master * m)
    {
        master = m;
        gb = new Gameboard(this, 50, 50, 18, 30, 2, master);
        retry = new Button(this, 680, 60, 150, 50, "retry");
        settings = new Button(this, 680, 130, 150, 50, "settings");
        exit = new Button(this, 680, 200, 150, 50, "exit");
    }

    void event_loop() override;
    void setup();
//    void output_data() override{};
};

#endif // GAMEWINDOW_HPP
