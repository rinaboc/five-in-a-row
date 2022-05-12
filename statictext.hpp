#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"

class StaticText : public Widget
{
protected:

public:
    StaticText(Window * w, int x, int y, int sizex, int sizey, std::string text) : Widget(w, x, y, sizex, sizey, text){}

    void draw() override;
    void logic(genv::event&) override {return;};
    void change_text(std::string s){_title = s;}
};


#endif // STATICTEXT_HPP
