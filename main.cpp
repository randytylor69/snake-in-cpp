#include "terminal.h"
#include <iostream>
#include <print>

int main(){

    Terminal terminal;

    terminal.setCanonical(0);
    terminal.setCursor(0);

    terminal.clear();
    terminal.print("hi", 4, 13);
    

    terminal.setCanonical(1);
    terminal.setCursor(1);
    return 0;
}
