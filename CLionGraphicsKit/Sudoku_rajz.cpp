#include "Sudoku_rajz.hpp"
#include <iostream>

using namespace std;
using namespace genv;

Sudoku_rajz::Sudoku_rajz(int szelesseg, int magassag):
               szelesseg(szelesseg), magassag(magassag)
{
}

void Sudoku_rajz::draw() const {
    gout.open(szelesseg, magassag);
    gout << color(200, 200, 200)
         << move_to(0,0)
         << box(szelesseg,magassag);
    gout.load_font("LiberationSerif-BoldItalic.ttf", 45);
    gout << color(0,0,0)
         << move_to(szelesseg/2 - 100,100)
         << text("Sudoku");
}

void Sudoku_rajz::racs() const{
    //függőleges vonalak
     gout << color(0,0,0); //egy egység 70 széles, minden harmadik vonal háromszor szélesebb
     for (int i= 0; i < 3; i++) {
          gout << move_to(szelesseg/2 - szelesseg*0.4 - i, magassag/2 - magassag*0.4)
               << line_to(szelesseg/2 - szelesseg*0.4 - i, magassag/2 + magassag*0.4);
     }
     gout << move_to(szelesseg/2 - szelesseg*0.4 + 70, magassag/2 - magassag*0.4)
          << line_to(szelesseg/2 - szelesseg*0.4 + 70, magassag/2 + magassag*0.4)
          << move_to(szelesseg/2 - szelesseg*0.4 + 140, magassag/2 - magassag*0.4)
          << line_to(szelesseg/2 - szelesseg*0.4 + 140, magassag/2 + magassag*0.4);
    for (int i= 0; i < 3; i++) {
        gout << move_to(szelesseg/2 - szelesseg*0.4 + 210 + i, magassag/2 - magassag*0.4)
             << line_to(szelesseg/2 - szelesseg*0.4 + 210 + i, magassag/2 + magassag*0.4);
    }
    gout << move_to(szelesseg/2 - szelesseg*0.4 + 282, magassag/2 - magassag*0.4)
         << line_to(szelesseg/2 - szelesseg*0.4 + 282, magassag/2 + magassag*0.4)
         << move_to(szelesseg/2 - szelesseg*0.4 + 352, magassag/2 - magassag*0.4)
         << line_to(szelesseg/2 - szelesseg*0.4 + 352, magassag/2 + magassag*0.4);
    for (int i= 0; i < 3; i++) {
        gout << move_to(szelesseg/2 - szelesseg*0.4 + 422 + i, magassag/2 - magassag*0.4)
             << line_to(szelesseg/2 - szelesseg*0.4 + 422 + i, magassag/2 + magassag*0.4);
    }
    gout << move_to(szelesseg/2 - szelesseg*0.4 + 494, magassag/2 - magassag*0.4)
         << line_to(szelesseg/2 - szelesseg*0.4 + 494, magassag/2 + magassag*0.4)
         << move_to(szelesseg/2 - szelesseg*0.4 + 564, magassag/2 - magassag*0.4)
         << line_to(szelesseg/2 - szelesseg*0.4 + 564, magassag/2 + magassag*0.4);
    for (int i= 0; i < 3; i++) {
          gout << move_to(szelesseg/2 - szelesseg*0.4 + 634 + i, magassag/2 - magassag*0.4)
               << line_to(szelesseg/2 - szelesseg*0.4 + 634 + i, magassag/2 + magassag*0.4);
    }
    //vízszintes vonalak
     gout << color(0,0,0); //egy egység 70 széles, minden harmadik vonal háromszor szélesebb
     for (int i= 0; i < 3; i++) {
          gout << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 - i)
               << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 - i);
     }
     gout << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 70)
          << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 + 70)
          << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 140)
          << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 + 140);
     for (int i= 0; i < 3; i++) {
          gout << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 210 + i)
               << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 + 210 + i);
     }
     gout << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 282)
          << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 + 282)
          << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 352)
          << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 + 352);
     for (int i= 0; i < 3; i++) {
          gout << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 422 + i)
               << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 + 422 + i);
     }
     gout << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 494)
          << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 + 494)
          << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 564)
          << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 - magassag*0.4 + 564);
     for (int i= 0; i < 3; i++) {
          gout << move_to(szelesseg/2 - szelesseg*0.4, magassag/2 - magassag*0.4 + 634 + i)
               << line_to(szelesseg/2 + szelesseg*0.4, magassag/2 + magassag*0.4 + 634 + i);
     }
}