#include <iostream>
#include <fstream>
#include "graphics.hpp"
#include "Os_alkalmazas.hpp"
#include "Sudoku_rajz.hpp"
#include "Legordulo.hpp"
#include "Gomb.hpp"

using namespace std;

class App: public Os_alkalmazas{
public:
    App(int szelesseg, int magassag): Os_alkalmazas(szelesseg, magassag)
    {
        menu = true;
        hatter = new Sudoku_rajz(this, 0, 0, szelesseg, magassag, false);
        hatter->rajzol();
        szint = new Legordulo(this, szelesseg/2 - 250, magassag/2, 300, 50, true, 4, szintek);
        gomb = new Gomb(this, szelesseg/2 + 100, magassag/2, 100, 50, true, "Játék", [=](){fajl_valaszto();});

        allapot();
    }

    void allapot() {
        if (menu) {
            szint = new Legordulo(this, szelesseg/2 - 250, magassag/2, 300, 50, true, 4, szintek);
            gomb = new Gomb(this, szelesseg/2 + 100, magassag/2, 100, 50, true, "Játék", [=](){fajl_valaszto();});
        }
        else if (jatekter){
            widgets_.clear();
            hatter->rajzol();
            hatter->racs();
        }
    }

    void fajl_valaszto() {
        if (menu) {
            string feladat = szint->get_mentesstr();
            if (feladat == "1. szint") {
                befajl.open("Elso_szint.txt");
                beolvas();
            }
            else if (feladat == "2. szint") {
                befajl.open("Masodik_szint.txt");
                beolvas();
            }
            else if (feladat == "3. szint") {
                befajl.open("Harmadik_szint.txt");
                beolvas();
            }
            else if (feladat == "4. szint") {
                befajl.open("Negyedik_szint.txt");
                beolvas();
            }
        }
        befajl.close();
    }

    void beolvas() {
        for (int i = 0; i < 9; i++) {
            vector<int> sor = {};
            for (int j = 0; j < 9; j++) {
                int szam;
                befajl >> szam;
                sor.push_back(szam);
            }
            megoldas.push_back(sor);
        }
        menu = false;
        jatekter = true;
        allapot();
        cout << "Beolvasva " << megoldas[0][0] << endl;
    }


protected:
    bool menu, jatekter;
    Sudoku_rajz* hatter = nullptr;
    Legordulo* szint = nullptr;
    Gomb* gomb = nullptr;
    vector<string> szintek = {"1. szint", "2. szint", "3. szint", "4. szint"};
    vector<vector<int>> megoldas;
    ifstream befajl;
};

int main(){

    App app(800, 800);

    app.event_loop();

    return 0;
}
