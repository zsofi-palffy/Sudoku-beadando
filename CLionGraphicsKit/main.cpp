#include <iostream>
#include <fstream>
#include "graphics.hpp"
#include "Os_alkalmazas.hpp"
#include "Sudoku_rajz.hpp"
#include "Legordulo.hpp"
#include "Gomb.hpp"
#include "Szamlalo_nyilakkal.hpp"

using namespace std;

class Jatek_mester: public Os_alkalmazas{
public:
    Jatek_mester(int szelesseg, int magassag): Os_alkalmazas(szelesseg, magassag)
    {
        menu = true;
        hatter = new Sudoku_rajz(this, 0, 0, szelesseg, magassag, false);
        hatter->rajzol();
        szint = new Legordulo(this, szelesseg/2 - 250, magassag/2, 300, 50, true, 4, szintek);
        gomb = new Gomb(this, szelesseg/2 + 100, magassag/2, 100, 50, true, "Játék", [=](){fajl_valaszto();});

        allapot();
        megjelenitettek = {};
    }

    void allapot() { //menünek vagy játéktérnek megfelelő funkciók
        if (menu) {
            szint = new Legordulo(this, szelesseg/2 - 250, magassag/2, 300, 50, true, 4, szintek);
            gomb = new Gomb(this, szelesseg/2 + 100, magassag/2, 100, 50, true, "Játék", [=](){fajl_valaszto();});
        }
        else if (jatekter){
            widgets_.clear();
            hatter->rajzol();
            hatter->racs();

            feltolt();
        }
    }

    void feltolt() {
        int fromx1 = szelesseg/2 - szelesseg*0.4 + 1;
        int fromy1 = magassag/2 - magassag*0.35 + 1;

        int egysegx = 0;
        int egysegy = 0;
        int vonalx = 0;
        int vonaly = 0;

        int sor = 0;
        int oszlop = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (fix(sor, oszlop)) {
                            szam = new Szamlalo_nyilakkal(this, fromx1 + egysegx + vonalx, fromy1 + egysegy + vonaly, 68, 68, true, megoldas[sor][oszlop], megoldas[sor][oszlop], true);
                            widgets_.push_back(szam);
                            szam->update(megoldas[sor][oszlop]);
                        }
                        else {
                            szam = new Szamlalo_nyilakkal(this, fromx1 + egysegx + vonalx, fromy1 + egysegy + vonaly, 68, 68, true, 0, 9, false);
                            widgets_.push_back(szam);
                        }
                        egysegx += 70;
                        vonalx += 1;
                        if (l == 2) {
                            vonalx += 2;
                        }
                        oszlop += 1;
                    }
                }
                egysegx = 0;
                vonalx = 0;

                egysegy += 70;
                vonaly += 1;
                if (j == 2) {
                    vonaly += 2;
                }
                oszlop = 0;
                sor += 1;
            }
        }
    }

    void fajl_valaszto() { //megadja, hogy melyik fájlt kell beolvasni
        if (menu) {
            string feladat = szint->get_mentesstr();
            if (feladat == "1. szint") {
                befajl.open("Elso_szint.txt");
                megjelenitettek = {{0, 0}, {0, 4}, {0, 6}, {0, 8},
                                      {1, 1}, {1, 3}, {1, 8},
                                      {2, 2}, {2, 4}, {2, 8},
                                      {3, 0}, {3, 4}, {3, 7},
                                      {4, 1}, {4, 5}, {4, 8},
                                      {5, 0}, {5, 3}, {5, 6},
                                      {6, 1}, {6, 4}, {6, 6},
                                      {7, 0}, {7, 6}, {7, 8},
                                      {8, 2}, {8, 5}, {8, 7}};
                beolvas();
            }
            else if (feladat == "2. szint") {
                befajl.open("Masodik_szint.txt");
                megjelenitettek = {{0, 0}, {0, 1}, {0, 4},
                                      {1, 0}, {1, 3}, {1, 4}, {1, 5},
                                      {2, 1}, {2, 2}, {2, 7},
                                      {3, 0}, {3, 4}, {3, 8},
                                      {4, 0}, {4, 3}, {4, 5}, {4, 8},
                                      {5, 0}, {5, 4}, {5, 8},
                                      {6, 1}, {6, 6}, {6, 7},
                                      {7, 3}, {7, 4}, {7, 5}, {7, 8},
                                      {8, 4}, {8, 7}, {8, 8}};
                beolvas();
            }
            else if (feladat == "3. szint") {
                befajl.open("Harmadik_szint.txt");
                megjelenitettek = {{0, 0}, {0, 3}, {0, 6},
                                      {1, 1}, {1, 4}, {1, 5}, {1, 8},
                                      {2, 2}, {2, 4}, {2, 7},
                                      {3, 0}, {3, 3}, {3, 7},
                                      {4, 1}, {4, 4}, {4, 8},
                                      {5, 2}, {5, 5},
                                      {6, 0}, {6, 5}, {6, 6},
                                      {7, 2}, {7, 3}, {7, 8},
                                      {8, 1}, {8, 4}, {8, 7}};
                beolvas();
            }
            else if (feladat == "4. szint") {
                befajl.open("Negyedik_szint.txt");
                megjelenitettek = {{0, 2}, {0, 4}, {0, 7},
                                      {1, 1}, {1, 3}, {1, 8},
                                      {2, 0}, {2, 4}, {2, 6},
                                      {3, 2}, {3, 5}, {3, 7},
                                      {4, 0}, {4, 4}, {4, 8},
                                      {5, 1}, {5, 3}, {5, 6},
                                      {6, 2}, {6, 5}, {6, 7},
                                      {7, 0}, {7, 4}, {7, 8},
                                      {8, 1}, {8, 4}};
                beolvas();
            }
        }
        befajl.close();
    }

    void beolvas() { //a fájl beolvasása
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
    }

    bool fix(int sor, int oszlop) {
        for (int t = 0; t < megjelenitettek.size(); t++) {
            if (megjelenitettek[t][0] == sor && megjelenitettek[t][1] == oszlop) {
                return true;
            }
        }
        return false;
    }

    void hiba() {
        for (int i = 0; i < 9; i++) {
            vector<int> sor = {};
            for (int j = 0; j < 9; j++) {
                int aktualis = widgets_[i*9 + j]->get_mentesint();
                sor.push_back(aktualis);
            }
            beallitott.push_back(sor);
        }


    }

protected:
    bool menu, jatekter; //állapotok
    Sudoku_rajz* hatter = nullptr; //a háttér
    Legordulo* szint = nullptr; //szintválasztó
    Gomb* gomb = nullptr; //játék indítása
    Szamlalo_nyilakkal* szam = nullptr; //a számok
    std::vector<std::string> szintek = {"1. szint", "2. szint", "3. szint", "4. szint"};
    std::vector<std::vector<int>> megoldas, megjelenitettek, beallitott; //a megoldás, a fix számok és az éppen aktuálisan megjelenített számok vektorai
    std::ifstream befajl;
};

int main(){

    Jatek_mester app(800, 800);

    app.event_loop();

    return 0;
}
