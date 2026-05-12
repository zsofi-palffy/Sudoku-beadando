#include "Sudoku_rajz.hpp"
#include <iostream>

using namespace std;
using namespace genv;

Sudoku_rajz::Sudoku_rajz(Os_alkalmazas* szulo, int x, int y, int szelesseg, int magassag, bool kell):
Widget(szulo, x, y, szelesseg, magassag, kell)
{
}

void Sudoku_rajz::rajzol() {
    gout << color(200, 200, 200)
         << move_to(0,0)
         << box(sizex,sizey);
    gout.load_font("LiberationSerif-BoldItalic.ttf", 85);
    gout << color(0,0,0)
         << move_to(sizex/2 - 150,10)
         << text("Sudoku");
    gout << refresh;
}

void Sudoku_rajz::racs() const{
     //függőleges vonalak
     int fromx1 = sizex/2 - sizex*0.4;
     int fromy1 = sizey/2 - sizey*0.35;
     int tox1 = sizex/2 + sizex*0.45 - 4;

     gout << color(0,0,0); //egy egység 70 széles, minden harmadik vonal háromszor szélesebb
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx1 - i, fromy1)
               << line_to(fromx1 - i, tox1);
     }
     gout << move_to(fromx1 + 70, fromy1)
          << line_to(fromx1 + 70, tox1)
          << move_to(fromx1 + 140, fromy1)
          << line_to(fromx1 + 140, tox1);
    for (int i= 0; i < 3; i++) {
        gout << move_to(fromx1 + 210 + i, fromy1)
             << line_to(fromx1 + 210 + i, tox1);
    }
    gout << move_to(fromx1 + 282, fromy1)
         << line_to(fromx1 + 282, tox1)
         << move_to(fromx1 + 352, fromy1)
         << line_to(fromx1 + 352, tox1);
    for (int i= 0; i < 3; i++) {
        gout << move_to(fromx1 + 422 + i, fromy1)
             << line_to(fromx1 + 422 + i, tox1);
    }
    gout << move_to(fromx1 + 494, fromy1)
         << line_to(fromx1 + 494, tox1)
         << move_to(fromx1 + 564, fromy1)
         << line_to(fromx1 + 564, tox1);
    for (int i= 0; i < 3; i++) {
          gout << move_to(fromx1 + 634 + i, fromy1)
               << line_to(fromx1 + 634 + i, tox1);
    }
    //vízszintes vonalak
     int fromx = sizex/2 - sizex*0.4 - 2;
     int tox = sizex/2 + sizex*0.4 - 4;
     int fromy = sizey/2 - sizey*0.35;

     gout << color(0,0,0); //egy egység 70 széles, minden harmadik vonal háromszor szélesebb
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx, fromy - i)
               << line_to(tox, fromy - i);
     }
     gout << move_to(fromx, fromy + 70)
          << line_to(tox, fromy + 70)
          << move_to(fromx, fromy + 140)
          << line_to(tox, fromy + 140);
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx, fromy + 210 + i)
               << line_to(tox, fromy + 210 + i);
     }
     gout << move_to(fromx, fromy + 282)
          << line_to(tox, fromy + 282)
          << move_to(fromx, fromy + 352)
          << line_to(tox, fromy + 352);
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx, fromy + 422 + i)
               << line_to(tox, fromy + 422 + i);
     }
     gout << move_to(fromx, fromy + 494)
          << line_to(tox, fromy + 494)
          << move_to(fromx, fromy + 564)
          << line_to(tox, fromy + 564);
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx, fromy + 634 + i)
               << line_to(tox, fromy + 634 + i);
     }
     gout << refresh;
}

void Sudoku_rajz::handle(genv::event) {

}
