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
    gout.load_font("LiberationSerif-BoldItalic.ttf", 45);
    gout << color(0,0,0)
         << move_to(sizex/2 - 100,100)
         << text("Sudoku");
}

void Sudoku_rajz::racs() const{
    //függőleges vonalak
     gout << color(0,0,0); //egy egység 70 széles, minden harmadik vonal háromszor szélesebb
     for (int i= 0; i < 3; i++) {
          gout << move_to(sizex/2 - sizex*0.4 - i, sizey/2 - sizey*0.4)
               << line_to(sizex/2 - sizex*0.4 - i, sizey/2 + sizey*0.4);
     }
     gout << move_to(sizex/2 - sizex*0.4 + 70, sizey/2 - sizey*0.4)
          << line_to(sizex/2 - sizex*0.4 + 70, sizey/2 + sizey*0.4)
          << move_to(sizex/2 - sizex*0.4 + 140, sizey/2 - sizey*0.4)
          << line_to(sizex/2 - sizex*0.4 + 140, sizey/2 + sizey*0.4);
    for (int i= 0; i < 3; i++) {
        gout << move_to(sizex/2 - sizex*0.4 + 210 + i, sizey/2 - sizey*0.4)
             << line_to(sizex/2 - sizex*0.4 + 210 + i, sizey/2 + sizey*0.4);
    }
    gout << move_to(sizex/2 - sizex*0.4 + 282, sizey/2 - sizey*0.4)
         << line_to(sizex/2 - sizex*0.4 + 282, sizey/2 + sizey*0.4)
         << move_to(sizex/2 - sizex*0.4 + 352, sizey/2 - sizey*0.4)
         << line_to(sizex/2 - sizex*0.4 + 352, sizey/2 + sizey*0.4);
    for (int i= 0; i < 3; i++) {
        gout << move_to(sizex/2 - sizex*0.4 + 422 + i, sizey/2 - sizey*0.4)
             << line_to(sizex/2 - sizex*0.4 + 422 + i, sizey/2 + sizey*0.4);
    }
    gout << move_to(sizex/2 - sizex*0.4 + 494, sizey/2 - sizey*0.4)
         << line_to(sizex/2 - sizex*0.4 + 494, sizey/2 + sizey*0.4)
         << move_to(sizex/2 - sizex*0.4 + 564, sizey/2 - sizey*0.4)
         << line_to(sizex/2 - sizex*0.4 + 564, sizey/2 + sizey*0.4);
    for (int i= 0; i < 3; i++) {
          gout << move_to(sizex/2 - sizex*0.4 + 634 + i, sizey/2 - sizey*0.4)
               << line_to(sizex/2 - sizex*0.4 + 634 + i, sizey/2 + sizey*0.4);
    }
    //vízszintes vonalak
     gout << color(0,0,0); //egy egység 70 széles, minden harmadik vonal háromszor szélesebb
     for (int i= 0; i < 3; i++) {
          gout << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 - i)
               << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 - i);
     }
     gout << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 70)
          << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 + 70)
          << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 140)
          << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 + 140);
     for (int i= 0; i < 3; i++) {
          gout << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 210 + i)
               << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 + 210 + i);
     }
     gout << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 282)
          << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 + 282)
          << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 352)
          << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 + 352);
     for (int i= 0; i < 3; i++) {
          gout << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 422 + i)
               << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 + 422 + i);
     }
     gout << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 494)
          << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 + 494)
          << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 564)
          << line_to(sizex/2 + sizex*0.4, sizey/2 - sizey*0.4 + 564);
     for (int i= 0; i < 3; i++) {
          gout << move_to(sizex/2 - sizex*0.4, sizey/2 - sizey*0.4 + 634 + i)
               << line_to(sizex/2 + sizex*0.4, sizey/2 + sizey*0.4 + 634 + i);
     }
}