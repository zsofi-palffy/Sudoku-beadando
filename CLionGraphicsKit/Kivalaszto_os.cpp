#include "Kivalaszto_os.hpp"
#include "graphics.hpp"
#include <iostream>
#include <ostream>
//a kiválasztó widgetek őse

using namespace genv;
using namespace std;

Kivalaszto_os::Kivalaszto_os(int x, int y, int kissizex, int kissizey, int nagysize, std::vector<std::string> opciok):
               Widget(x, y, kissizex, kissizey), nagysize(nagysize), opciok(opciok)
{
}

string Kivalaszto_os::get_mentesstr() const {
    return "";
}

bool Kivalaszto_os::mindig() {
    return false;
}

void Kivalaszto_os::rajzol() {
    gout.load_font("LiberationSans-BoldItalic.ttf", 10, 30);

    elemek(); //a lenyiló menü és a kiválasztott rózsaszínre szinezése
    for (int i = 0; i < nagysize; i++) {
        if (lenyitva) {
            if (i == rozsaszin) {
                gout << color(249, 111, 239); //rózsaszín, kiválasztott
            }
            else {
                gout << color(255,255,255); //fehér
            }
        }
        else {
            gout << color(23,23,23);
        }
        gout << move_to(x, y + teglalapok[i])
             << box(sizex, sizey);
    }

    gout << color(0,0,0)
         << move_to(x + 5, y + 5);
    if (kivalasztva) {
        gout << text(kivalasztott);
        lenyitva = false;
        kivalasztva = false;
        alapallas = false;
    }
    else if (alapallas) {
        gout << text("Válassz egy lehetőséget!");
    }
    else {
        gout << text(kivalasztott);
    }

    if (lenyitva) { //a választási lehetőségek szövegei
        int hely = 0;
        for (int j = ciklus; j < ciklus + nagysize; j++) {
            gout << color(0,0,0)
                 << move_to(x + 5, y + teglalapok[hely] + 5)
                 << text(opciok[j]);
            hely += 1;
        }
    }
}

void Kivalaszto_os::handle(genv::event ev) {
    elemek(); //a rózsaszín kijelölés
    for (int i = 0; i < teglalapok.size(); i++) {
        if (ev.pos_x >= x && ev.pos_x <= x + sizex && ev.pos_y >= y + teglalapok[i] && ev.pos_y <= y + teglalapok[i] + sizey) {
            rozsaszin = i;
        }
        else if (ev.pos_x < x || ev.pos_x > x + sizex) {
            rozsaszin = -1;
        }
    }

    //a fel- és legörgetés
    if (ev.type == ev_mouse && ev.button == btn_wheelup) {
        fel();
    }
    else if (ev.type == ev_mouse && ev.button == btn_wheeldown) {
        le();
    }

    //a kiválasztás

    int hely = 0;
    for (int i = ciklus; i < ciklus + nagysize; i++) {
        if (ev.type == ev_mouse && ev.button == btn_left && ev.pos_x >= x && ev.pos_x <= x + sizex && ev.pos_y >= y + teglalapok[hely] && ev.pos_y <= y + teglalapok[hely] + sizey) {
            kivalasztva = true;
            kivalasztott = opciok[i];
        }
        hely += 1;
    }

}

void Kivalaszto_os::elemek() { //összerakja a teglalapok vektort, amiben a koordináták alapján a választási lehetőségeket kiírja és kezeli
    teglalapok.clear();
    for (int i = 1; i <= opciok.size(); i++) {
        int kezdopont = i*sizey;
        teglalapok.push_back(kezdopont);
    }
}

void Kivalaszto_os::fel() { //felfele görgetés
    if (ciklus > 0) {
        ciklus -= 1;
    }
}

void Kivalaszto_os::le() { //lefele görgetés
    if (ciklus < opciok.size() - nagysize) {
        ciklus += 1;
    }
}
