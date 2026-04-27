#ifndef CLIONGRAPHICSKIT_WIDGET_H
#define CLIONGRAPHICSKIT_WIDGET_H
#include "graphics.hpp"


class Widget {
public:
    Widget(int, int, int, int);
    bool jelenlegi(int, int);

    virtual void rajzol() = 0;
    virtual void handle(genv::event ev) = 0;

    virtual void kilep(genv::event ev);
    virtual bool mindig();
    virtual std::string get_mentesstr() const;
    virtual int get_mentesint() const;

protected:
    int x, y, sizex, sizey;

};

#endif //CLIONGRAPHICSKIT_WIDGET_H