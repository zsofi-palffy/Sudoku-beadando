#ifndef CLIONGRAPHICSKIT_OS_ALKALMAZAS_H
#define CLIONGRAPHICSKIT_OS_ALKALMAZAS_H
#include "graphics.hpp"

class Os_alkalmazas {
public:
    Os_alkalmazas(int, int);

    virtual void draw();
    virtual void handle(genv::event);

protected:
    int szelesseg, magassag;
};


#endif //CLIONGRAPHICSKIT_OS_ALKALMAZAS_H