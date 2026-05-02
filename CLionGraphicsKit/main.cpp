#include <iostream>
#include <fstream>
#include "graphics.hpp"
#include "Os_alkalmazas.hpp"

using namespace std;

class App: public Os_alkalmazas{
public:
    App(int szelesseg, int magassag): Os_alkalmazas(szelesseg, magassag)
    {

    }
};

int main(){

    return 0;
}
