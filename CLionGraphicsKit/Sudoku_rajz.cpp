#include "Sudoku_rajz.hpp"
#include <iostream>

using namespace std;
using namespace genv;

Sudoku_rajz::Sudoku_rajz(int szelesseg, int magassag):
               szelesseg(szelesseg), magassag(magassag)
{
    menu = true;
    jatek = false;
}

void Sudoku_rajz::draw() const {
    gout.open(szelesseg, magassag);
    gout << color(200, 200, 200)
         << move_to(0,0)
         << box(szelesseg,magassag);
    if (menu) {
        gout.load_font("LiberationSerif-BoldItalic.ttf", 45);
        gout << color(0,0,0)
             << move_to(szelesseg/2 - 100,100)
             << text("Sudoku");
    }

}
