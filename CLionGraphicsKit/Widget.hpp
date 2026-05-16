#ifndef CLIONGRAPHICSKIT_WIDGET_H
#define CLIONGRAPHICSKIT_WIDGET_H
#include "graphics.hpp"

class Os_alkalmazas;

class Widget {
public:
    Widget(Os_alkalmazas*, int, int, int, int, bool);
    ~Widget();
    bool jelenlegi(int, int);

    virtual void rajzol() = 0;
    virtual void handle(genv::event ev) = 0;

    virtual void kilep(genv::event ev);
    virtual bool mindig();
    virtual std::string get_mentesstr() const;
    virtual int get_mentesint() const;

protected:
    int x, y, sizex, sizey;
    Os_alkalmazas *szulo;
    bool kell = true;
};

#endif //CLIONGRAPHICSKIT_WIDGET_H