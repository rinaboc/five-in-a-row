#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widget.hpp"
#include "window.hpp"

class Gameboard;

class Button : public Widget
{
protected:
    bool _press;
public:
    Button(Window * w, int x, int y, int sizex, int sizey, std::string title) : Widget(w, x, y, sizex, sizey, title), _press(false){}

    void toggle_press(){_press = !_press;}
    int press_logic(){return _press;};
    void draw() override;
    void logic(genv::event&) override;
};

class Game_tile : public Button
{
protected:
    char _display;
    Gameboard * _parent;
public:
    Game_tile(Window * w, int x, int y, int sizex, int sizey, Gameboard * parent) : Button(w, x, y, sizex, sizey, ""), _display(' '), _parent(parent) {}

    void draw() override;
    void logic(genv::event&) override;
    char get_char(){return _display;}
};

class Spinbox;

class Arrowbutton : public Button
{
protected:
    int _state;
    Spinbox * _parent;
public:
    Arrowbutton(Window * w, int x, int y, int sizex, int sizey, Spinbox * parent) : Button(w, x, y, sizex, sizey, ""), _state(0), _parent(parent){}

    void draw() override;
    bool is_over(int, int) override;
    void logic(genv::event&) override;
};

class Listbox;

class Mixbutton : public Button
{
protected:
    Listbox * _parent;
    Listbox * _destination;
public:
    Mixbutton(Window * w, int x, int y, int sizex, int sizey, std::string arrow , Listbox * parent, Listbox * destination) : Button(w, x, y, sizex, sizey, arrow), _parent(parent), _destination(destination){}

    void logic(genv::event&) override;
};

class Scrollbutton : public Button
{
protected:
    int _gy;
    Listbox * _parent;
    int _toplimit;
    int _bottomlimit;
public:
    Scrollbutton(Window * w, int x, int y, int sizex, int sizey, Listbox * parent) : Button(w, x, y, sizex, sizey, ""), _gy(0), _parent(parent), _toplimit(0), _bottomlimit(0)
    {
        set_limits();
    }
    virtual ~Scrollbutton(){
        _w->delete_widget(this);
    };

    void set_limits();
    void draw() override;
    bool is_over(int, int) override;
    void logic(genv::event&) override;
};

#endif // BUTTON_HPP
