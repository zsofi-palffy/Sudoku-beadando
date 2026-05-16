#include "Widget.hpp"

#include <iostream>
#include <ostream>

#include "graphics.hpp"
#include "Os_alkalmazas.hpp"

using namespace genv;

Widget::Widget(Os_alkalmazas *szulo, int xx, int yy, int sx, int sy, bool kell):
               x(xx), y(yy), sizex(sx), sizey(sy), kell(kell)
{
    szulo->register_widgets(this, kell);
}

Widget::~Widget() {

}

int Widget::get_mentesint() const {
    return 0;
}
std::string Widget::get_mentesstr() const {
    return "";
}

bool Widget::jelenlegi(int egerx, int egery) {
    return egerx >= x && egery >= y && egerx <= sizex+x && egery <= sizey+y;
}

void Widget::kilep(event ev) {
    if (ev.type == ev_key) {
        if (ev.keycode == key_escape) {
            exit(0);
        }
    }
}

bool Widget::mindig() {
    return false;
}