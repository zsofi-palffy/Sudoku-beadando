#include "Os_alkalmazas.hpp"
#include "graphics.hpp"
#include "Widget.hpp"

using namespace std;
using namespace genv;

Os_alkalmazas::Os_alkalmazas(int szelesseg, int magassag):
                             szelesseg(szelesseg), magassag(magassag)
{
}

void Os_alkalmazas::register_widgets(Widget* w, bool kell) {
    widgets_.push_back(w);
}

void Os_alkalmazas::event_loop() {
    event ev;
    int fokusz = -1;
    while (gin >> ev) {
        if (ev.type == ev_mouse && ev.button == btn_left) {
            for (int i = 0; i < widgets_.size(); i++) {
                if (widgets_[i]->jelenlegi(ev.pos_x, ev.pos_y)) {
                    fokusz = i;
                }
            }
        }

        if (fokusz != -1) {
            widgets_[fokusz]->handle(ev);
        }

        for (Widget *w: widgets_) {
            w->rajzol();
        }
    }
}
