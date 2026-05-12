#ifndef CLIONGRAPHICSKIT_GOMB_H
#define CLIONGRAPHICSKIT_GOMB_H
#include <functional>

#include "Widget.hpp"
#include "graphics.hpp"
#include "Os_alkalmazas.hpp"

class Gomb: public Widget {
public:
    Gomb(Os_alkalmazas*, int, int, int, int, bool, std::string, std::function<void()>);
    virtual ~Gomb();

    void rajzol() override;
    void handle(genv::event ev) override;

    void action();

protected:
    std::string label;
    std::function<void()> f;
};


#endif //CLIONGRAPHICSKIT_GOMB_H