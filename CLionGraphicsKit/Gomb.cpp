#include "Gomb.hpp"
#include "Widget.hpp"


using namespace std;
using namespace genv;

Gomb::Gomb(Os_alkalmazas* szulo, int x, int y, int sizex, int sizey, bool kell, string label, std::function<void()> f):
      Widget(szulo, x, y, sizex, sizey, kell), label(label), f(f)
{
}

Gomb::~Gomb() {

}


void Gomb::rajzol() {
      gout << color(0,0,0)
           << move_to(x, y)
           << box(sizex, sizey)
           << color(255,255,255)
           << move_to(x + 3, y + 3)
           << box(sizex - 6, sizey - 6);
      gout.load_font("LiberationSans-Regular.ttf", 20);
      gout << color(0,0,0)
           << move_to(x + 22, y + 12)
           << text(label);
}

void Gomb::handle(genv::event ev) {
    if (ev.type == ev_mouse) {
        if (ev.button == btn_left) {
            if (ev.pos_x >= x && ev.pos_x <= x + sizex && ev.pos_y >= y && ev.pos_y <= y + sizey) {
                if (f) {
                    f();
                }
            }
        }
    }
}

void Gomb::action() {

}
