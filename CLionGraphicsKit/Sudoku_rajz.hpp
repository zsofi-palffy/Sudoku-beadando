#ifndef CLIONGRAPHICSKIT_SUDOKU_H
#define CLIONGRAPHICSKIT_SUDOKU_H
#include "Widget.hpp"

class Sudoku_rajz:public Widget {
public:
    Sudoku_rajz(Os_alkalmazas*, int, int, int, int);

    virtual void draw() const;
    virtual void handle(genv::event);

    void racs() const;
};

#endif //CLIONGRAPHICSKIT_SUDOKU_H