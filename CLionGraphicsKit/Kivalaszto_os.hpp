#ifndef CLIONGRAPHICSKIT_KIVALASZTO_OS_H
#define CLIONGRAPHICSKIT_KIVALASZTO_OS_H
#include "graphics.hpp"
#include "Widget.hpp"
//a kiválasztó widgetek őse

class Kivalaszto_os: public Widget {
public:
    Kivalaszto_os(int, int, int, int, int, std::vector<std::string>);

    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
    virtual bool mindig() override;
    virtual std::string get_mentesstr() const override;

    void elemek(); //teglalapok vektor feltoltese

    void fel(); //felfele görgetés
    void le(); //lefele görgetés

protected:
    int nagysize, rozsaszin = -1, ciklus = 0; //rendre: hány lehetőség látszik, a kijelölt opció, melyik opciókat kell kiírni
    std::vector<std::string> opciok; //a választási lehetőségek vektora
    std::vector<int> teglalapok; //a választási lehetőségek pozíciói
    bool felette = false, lenyitva = false, kivalasztva = false; //rendre: lenyitáshoz szükséges bool, levan-e már nyitva, van-e már választott
    std::string kivalasztott; //tárolja az éppen kiválasztott elemet
    bool alapallas = true; //ez az alap állapot, ezt írja ki az elején, de csak az első kiválasztásig kell
};

#endif //CLIONGRAPHICSKIT_KIVALASZTO_OS_H