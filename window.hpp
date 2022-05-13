#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "widget.hpp"

class Game_master;

class Window
{
protected:
    std::vector<Widget*> _widgets;
    Widget * obj_in_focus = nullptr;
    Game_master * master;
public:
    void add_widget(Widget * w){_widgets.push_back(w);}
    void delete_widget(Widget*);

    void event_loop();
    void select_widget(Widget * &);

};

#endif // WINDOW_HPP
