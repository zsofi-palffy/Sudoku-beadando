#ifndef CLIONGRAPHICSKIT_OS_ALKALMAZAS_H
#define CLIONGRAPHICSKIT_OS_ALKALMAZAS_H
#include "graphics.hpp"
#include "Widget.hpp"

class Os_alkalmazas {
public:
    Os_alkalmazas(int, int);

    virtual void register_widgets(Widget* w);
    virtual void event_loop();

protected:
    int szelesseg, magassag;
    std::vector<Widget*> widgets_;
};


#endif //CLIONGRAPHICSKIT_OS_ALKALMAZAS_H