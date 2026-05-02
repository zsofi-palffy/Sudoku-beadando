#include "Szamlalo_nyilakkal.hpp"

#include <iostream>

#include "graphics.hpp"
//az a számláló widget, amelyen a fel és le nyilas gombokkal lehet állítani a szám értékét

using namespace genv;

Szamlalo_nyilakkal::Szamlalo_nyilakkal(Os_alkalmazas* szulo, int x, int y, int sizex, int sizey, int minimum, int maximum):
                    Szamlalo_os(szulo, x, y, sizex, sizey, minimum, maximum, 0)
{
}

int Szamlalo_nyilakkal::get_mentesint() const {
     return szam;
}

void Szamlalo_nyilakkal::rajzol() {
    Szamlalo_os::rajzol();
    gout.load_font("LiberationSans-BoldItalic.ttf", 60, 30);

    gout << color(200,200,200) //a nyomógombok területe
         << move_to(x + (3*sizex/4), y)
         << box(sizex/4,sizey)
         << move_to(x + (3*sizex/4), y)
         << color(0,0,0) // határoló vonalak
         << line_to(x + (3*sizex/4), y + sizey)
         << move_to(x + (3*sizex/4), y + sizey/2)
         << line_to(x + sizex, y + sizey/2);
    gout << color(0,0,0) //felfele háromszög
         << move_to(x + (3*sizex/4) + (sizex/4)/3, y + 2*(sizey/2)/3)
         << line_to(x + (3*sizex/4) + 2*(sizex/4)/3, y + 2*(sizey/2)/3)
         << line_to(x + (3*sizex/4) + (sizex/4)/3 + ((sizex/4)/3)/2, y + (sizey/2)/3)
         << move_to(x + (3*sizex/4) + (sizex/4)/3, y + 2*(sizey/2)/3)
         << line_to(x + (3*sizex/4) + (sizex/4)/3 + ((sizex/4)/3)/2, y + (sizey/2)/3);
    gout << color(0,0,0) //lefele háromszög
         << move_to(x + (3*sizex/4) + (sizex/4)/3, y + sizey/2 + (sizey/2)/3)
         << line_to(x + (3*sizex/4) + 2*(sizex/4)/3, y + sizey/2 + (sizey/2)/3)
         << line_to(x + (3*sizex/4) + (sizex/4)/3 + ((sizex/4)/3)/2, y + sizey/2 + 2*(sizey/2)/3)
         << move_to(x + (3*sizex/4) + (sizex/4)/3, y + sizey/2 + (sizey/2)/3)
         << line_to(x + (3*sizex/4) + (sizex/4)/3 + ((sizex/4)/3)/2, y + sizey/2 + 2*(sizey/2)/3);
    gout << color(0,0,0)
         << move_to(x + 12, y + 15)
         << text(std::to_string(szam));
}

void Szamlalo_nyilakkal::handle(genv::event ev) {
     Szamlalo_os::handle(ev);

     if (ev.type == ev_mouse) {
          if (ev.button == btn_left && ev.pos_x >= x + 3*sizex/4 && ev.pos_x <= x + sizex && ev.pos_y >= y && ev.pos_y <= y + sizey/2) {
               novel(); //egyesével léptet
          }
          else if (ev.button == btn_left && ev.pos_x >= x + 3*sizex/4 && ev.pos_x <= x + sizex && ev.pos_y >= y + sizey/2 && ev.pos_y <= y + sizey) {
               csokkent(); //egyesével léptet
          }
     }

     mini();
     maxi();
}