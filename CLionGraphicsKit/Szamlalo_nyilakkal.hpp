#ifndef CLIONGRAPHICSKIT_SZAMLALO_NYILAKKAL_H
#define CLIONGRAPHICSKIT_SZAMLALO_NYILAKKAL_H
#include "Szamlalo_os.hpp"
//Az a számláló widget, amelyen a fel és le nyilas gombokkal lehet állítani a szám értékét

class Szamlalo_nyilakkal: public Szamlalo_os {
public:
    Szamlalo_nyilakkal(Os_alkalmazas*, int, int, int, int, bool, int, int, bool);

    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
    virtual int get_mentesint() const override;

    void update(int);

protected:
    bool fix;
};


#endif //CLIONGRAPHICSKIT_SZAMLALO_NYILAKKAL_H