#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widget.hpp"
#include "window.hpp"
#include <functional>

using namespace genv;

class Gameboard;

class Button : public Widget
{
protected:
    bool _press;
public:
    Button(Window * w, int x, int y, int sizex, int sizey, std::string title) : Widget(w, x, y, sizex, sizey, title), _press(false){}

    void toggle_press(){_press = !_press;}
    int press_logic()const {return _press;};
    void draw() const override;
    void logic(genv::event&) override;
};

class Game_tile : public Button
{
protected:
    char _display;
    Gameboard * _parent;
public:
    Game_tile(Window * w, int x, int y, int sizex, int sizey, Gameboard * parent) : Button(w, x, y, sizex, sizey, ""), _display(' '), _parent(parent) {}

    void draw() const override;
    void logic(genv::event&) override;
    char get_char()const {return _display;}
    void toggle_action();
};

class FButton : public Button
{
protected:
    std::function<void()> _f;
public:
    FButton(Window * w, int x, int y, int sizex, int sizey, std::string s, std::function<void()> f) : Button(w, x, y, sizex, sizey, s), _f(f) {}

    void logic(genv::event& ev) override
    {
        if(ev.button == btn_left)
            _press = true;
        else if(ev.button == -btn_left && _press == true)
        {
            _press = false;
            action();
        }
    }
    virtual void action(){_f();}
};

#endif // BUTTON_HPP
