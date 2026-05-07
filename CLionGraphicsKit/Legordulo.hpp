#ifndef CLIONGRAPHICSKIT_LEGORDOLO_H
#define CLIONGRAPHICSKIT_LEGORDOLO_H
#include "graphics.hpp"
#include "Kivalaszto_os.hpp"
//szimpla legördülő menü

class Legordulo: public Kivalaszto_os{
public:
    Legordulo(Os_alkalmazas*, int, int, int, int, bool, int, std::vector<std::string>);

    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
    virtual std::string get_mentesstr() const override;
};

#endif //CLIONGRAPHICSKIT_LEGORDOLO_H