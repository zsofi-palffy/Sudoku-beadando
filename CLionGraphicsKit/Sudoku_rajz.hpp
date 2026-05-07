#ifndef CLIONGRAPHICSKIT_SUDOKU_H
#define CLIONGRAPHICSKIT_SUDOKU_H
#include "Widget.hpp"

class App;

class Sudoku_rajz:public Widget {
public:
    Sudoku_rajz(Os_alkalmazas*, int, int, int, int, bool);

    virtual void rajzol() override;
    virtual void handle(genv::event);

    void racs() const;
};

#endif //CLIONGRAPHICSKIT_SUDOKU_H