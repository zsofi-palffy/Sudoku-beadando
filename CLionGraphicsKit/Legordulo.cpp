#include "Legordulo.hpp"
#include "graphics.hpp"
#include <iostream>
#include <ostream>
//szimpla legördülő menü

using namespace genv;
using namespace std;

Legordulo::Legordulo(Os_alkalmazas* szulo, int x, int y, int kissizex, int kissizey, bool kell, int nagysize, std::vector<std::string> opciok):
           Kivalaszto_os(szulo, x, y, kissizex, kissizey, kell, nagysize, opciok)
{
}

Legordulo::~Legordulo() {

}


std::string Legordulo::get_mentesstr() const{
    return kivalasztott;
}


void Legordulo::rajzol() {
    gout << color(123,123,123) //alapterület szürke kerete
         << move_to(x, y)
         << box(sizex, sizey)
         << color(255,255,255) //alapterület
         << move_to(x + 3, y + 3)
         << box(sizex - 6, sizey - 6);
    gout << color(0,0,0) // lefele nyíl a lenyithatóság jelzésére
         << move_to(x + 22*sizex/25, y + sizey/3)
         << line_to(x + 23*sizex/25, y + 2*sizey/3)
         << line_to(x + 24*sizex/25, y + sizey/3);

    Kivalaszto_os::rajzol();
}

void Legordulo::handle(genv::event ev) {
    felette = ev.pos_x >= x && ev.pos_x <= x + sizex && ev.pos_y >= y && ev.pos_y <= y + sizey;

    if (ev.type == ev_mouse && ev.button == btn_left) {
        if (felette) {
            lenyitva = !lenyitva;
        }
        else if (ev.pos_x >= x && ev.pos_x <= x + sizex && ev.pos_y >= y && ev.pos_y <= y + sizey + nagysize*sizey) {
            lenyitva = lenyitva;
        }
        else {
            lenyitva = false;
        }
    }

    if (lenyitva) {
        Kivalaszto_os::handle(ev);
    }
}