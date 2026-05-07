#include <iostream>
#include <fstream>
#include "graphics.hpp"
#include "Os_alkalmazas.hpp"
#include "Sudoku_rajz.hpp"
#include "Legordulo.hpp"

using namespace std;

class App: public Os_alkalmazas{
public:
    App(int szelesseg, int magassag): Os_alkalmazas(szelesseg, magassag)
    {
        menu = true;
        jatekter = false;
        hatter = new Sudoku_rajz(this, 0, 0, szelesseg, magassag, false);
        hatter->rajzol();
        szint = new Legordulo(this, szelesseg/2 - 150, magassag/2, 300, 50, true, 4, szintek);
    }

protected:
    bool menu, jatekter;
    Sudoku_rajz* hatter;
    Legordulo* szint;
    vector<string> szintek = {"1. szint", "2. szint", "3. szint", "4. szint"};
};

int main(){

    App app(800, 800);

    app.event_loop();

    return 0;
}
