#include "Szamlalo_os.hpp"

#include <iostream>
#include <ostream>

#include "graphics.hpp"
//a számlálós widgetek őse

using namespace genv;

Szamlalo_os::Szamlalo_os(Os_alkalmazas *szulo, int x, int y, int sizex, int sizey, bool kell, int mn, int mx, int szamol):
             Widget(szulo, x, y, sizex, sizey, kell), minimum(mn), maximum(mx), szam(szamol)
{
}

int Szamlalo_os::get_mentesint() const{
    return 0;
}

void Szamlalo_os::novel() {
    szam += 1;
}

void Szamlalo_os::csokkent() {
    szam -= 1;
}

void Szamlalo_os::maxi() {
    if (szam > maximum) {
        szam = maximum;
    }
}
void Szamlalo_os::mini() {
    if (szam < minimum) {
        szam = minimum;
    }
}

void Szamlalo_os::rajzol() {
    gout << color(0,0,0) //az egész nagy alapterület fekete kerete
         << move_to(x - 1, y - 1)
         << box(sizex + 2, sizey + 2)
         << color(103,224,253) //az egész nagy alapterület szürke kerete
         << move_to(x, y)
         << box(sizex,sizey)
         << color(0,0,0) //fekete kontúr a szürke keret és az alapterület között
         << move_to(x + 4, y + 4)
         << box(sizex - 8, sizey - 8)
         << color(255,255,255) //az egész nagy alapterület
         << move_to(x + 5, y + 5)
         << box(sizex - 10,sizey - 10);
}
void Szamlalo_os::handle(genv::event ev) {
    if (ev.type == ev_key) {
        if (ev.keycode == 97 || ev.keycode == key_up) { //a key_pgup kóddal nem működött, az értéke +-97, ezzel igen
            novel(); //ha nyomva tartjuk folyamatosan léptet
        }
        else if (ev.keycode == 91 || ev.keycode == key_down) { //a key_pgdn kóddal nem működött, az értéke +-91, ezzel igen
            csokkent(); //ha nyomva tartjuk folyamatosan léptet
        }
    }
}