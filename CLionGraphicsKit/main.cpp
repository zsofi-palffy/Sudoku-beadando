#include <iostream>
#include <fstream>
#include "graphics.hpp"
#include "Os_alkalmazas.hpp"
#include "Sudoku_rajz.hpp"

using namespace std;

class App: public Os_alkalmazas{
public:
    App(int szelesseg, int magassag): Os_alkalmazas(szelesseg, magassag)
    {
        menu = true;
        jatekter = false;
        hatter = new Sudoku_rajz(this, 0, 0, szelesseg, magassag, false);
        hatter->rajzol();

    }

protected:
    bool menu, jatekter;
    Sudoku_rajz* hatter;
};

int main(){

    App app(800, 800);

    app.event_loop();

    return 0;
}
