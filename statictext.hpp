#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"

class StaticText : public Widget
{
protected:
    std::string _text;
public:
    StaticText(Window * w, int x, int y, int sizex, int sizey, std::string text) : Widget(w, x, y, sizex, sizey, ""), _text(text){}

    void draw() const override;
    void logic(genv::event&) override {return;};
    void change_text(std::string s){_text = s;}
};


#endif // STATICTEXT_HPP
