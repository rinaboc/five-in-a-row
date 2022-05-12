#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "widget.hpp"
#include <vector>

class Window
{
protected:
    std::vector<Widget*> _widgets;
    Widget * obj_in_focus = nullptr;
public:
    void add_widget(Widget * w)
    {
        _widgets.push_back(w);
    }
    void delete_widget(Widget*);

    virtual void event_loop();
    void select_widget(Widget * &);

//    virtual void output_data() = 0;
};

#endif // WINDOW_HPP
