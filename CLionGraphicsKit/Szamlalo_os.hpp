#ifndef CLIONGRAPHICSKIT_SZAMLALO_OS_H
#define CLIONGRAPHICSKIT_SZAMLALO_OS_H
#include "Widget.hpp"
//a számlálós widgetek őse

class Szamlalo_os: public Widget {
public:
    Szamlalo_os(Os_alkalmazas*, int, int, int, int, int, int, int);

    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
    virtual int get_mentesint() const override;

    void novel();
    void csokkent();

    void mini();
    void maxi();

protected:
    int minimum, maximum;
    int szam;
};


#endif //CLIONGRAPHICSKIT_SZAMLALO_OS_H