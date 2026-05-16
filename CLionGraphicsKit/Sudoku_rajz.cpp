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
     int tox1 = sizex/2 + sizex*0.45 + 4;

     gout << color(0,0,0); //egy egység 70 széles, minden harmadik vonal háromszor szélesebb
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx1 - i, fromy1)
               << line_to(fromx1 - i, tox1);
     }
     gout << move_to(fromx1 + 71, fromy1)
          << line_to(fromx1 + 71, tox1)
          << move_to(fromx1 + 142, fromy1)
          << line_to(fromx1 + 142, tox1);
    for (int i = 1; i < 4; i++) {
        gout << move_to(fromx1 + 212 + i, fromy1)
             << line_to(fromx1 + 212 + i, tox1);
    }
    gout << move_to(fromx1 + 286, fromy1)
         << line_to(fromx1 + 286, tox1)
         << move_to(fromx1 + 357, fromy1)
         << line_to(fromx1 + 357, tox1);
    for (int i= 0; i < 3; i++) {
        gout << move_to(fromx1 + 427 + i, fromy1)
             << line_to(fromx1 + 427 + i, tox1);
    }
    gout << move_to(fromx1 + 501, fromy1)
         << line_to(fromx1 + 501, tox1)
         << move_to(fromx1 + 572, fromy1)
         << line_to(fromx1 + 572, tox1);
    for (int i= 0; i < 3; i++) {
          gout << move_to(fromx1 + 642 + i, fromy1)
               << line_to(fromx1 + 642 + i, tox1);
    }
    //vízszintes vonalak
     int fromx = sizex/2 - sizex*0.4 - 2;
     int tox = sizex/2 + sizex*0.4 + 4;
     int fromy = sizey/2 - sizey*0.35;

     gout << color(0,0,0); //egy egység 70 széles, minden harmadik vonal háromszor szélesebb
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx, fromy - i)
               << line_to(tox, fromy - i);
     }
     gout << move_to(fromx, fromy + 71)
          << line_to(tox, fromy + 71)
          << move_to(fromx, fromy + 142)
          << line_to(tox, fromy + 142);
     for (int i= 1; i < 4; i++) {
          gout << move_to(fromx, fromy + 212 + i)
               << line_to(tox, fromy + 212 + i);
     }
     gout << move_to(fromx, fromy + 286)
          << line_to(tox, fromy + 286)
          << move_to(fromx, fromy + 357)
          << line_to(tox, fromy + 357);
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx, fromy + 428 + i)
               << line_to(tox, fromy + 428 + i);
     }
     gout << move_to(fromx, fromy + 500)
          << line_to(tox, fromy + 500)
          << move_to(fromx, fromy + 571)
          << line_to(tox, fromy + 571);
     for (int i= 0; i < 3; i++) {
          gout << move_to(fromx, fromy + 642 + i)
               << line_to(tox, fromy + 642 + i);
     }
     gout << refresh;
}

void Sudoku_rajz::gameover() {
     gout.load_font("LiberationSerif-BoldItalic.ttf", 20);
     gout << color(200, 200, 200)
          << move_to(578, 78)
          << box(gout.twidth("Jó megoldás! :)") + 4, 24)
          << color(14, 190, 39)
          << move_to(580, 80)
          << text("Jó megoldás! :)")
          << color(200, 200, 200)
          << move_to(78, 78)
          << box(gout.twidth("Gratulálok!") + 4, 24)
          << color(14, 190, 39)
          << move_to(80, 80)
          << text("Gratulálok!");
}

void Sudoku_rajz::handle(genv::event) {

}
