#include "terminal.h"
#include <iostream>
#include <print>

int main(){

    Terminal terminal;

    terminal.setCanonicalAndCursor(0);

    terminal.clear();
    terminal.print("hi", 4, 13);
    

    terminal.setCanonicalAndCursor(1);
    return 0;
}
