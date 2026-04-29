#ifndef CLIONGRAPHICSKIT_SUDOKU_H
#define CLIONGRAPHICSKIT_SUDOKU_H
#include "Widget.hpp"

class Sudoku_rajz {
public:
    Sudoku_rajz(int, int);

    virtual void draw() const;
    virtual void handle(genv::event);

protected:
    bool menu, jatek; //még nem biztos, hogy ezeket ide akarom
    int szelesseg, magassag; //az ablak nagysága
};

#endif //CLIONGRAPHICSKIT_SUDOKU_H