#ifndef CLIONGRAPHICSKIT_SUDOKU_H
#define CLIONGRAPHICSKIT_SUDOKU_H
#include "Widget.hpp"

class Sudoku_rajz {
public:
    Sudoku_rajz(int, int);

    virtual void draw() const;
    virtual void handle(genv::event);

    void racs() const;

protected:
    int szelesseg, magassag; //az ablak nagysága
};

#endif //CLIONGRAPHICSKIT_SUDOKU_H