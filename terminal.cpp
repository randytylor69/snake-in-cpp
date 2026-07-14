#include "terminal.h"
#include <string>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <print>


void Terminal::setCanonical(const int &cmd)
{
    tcgetattr(STDIN_FILENO, &tio); // get current terminal setting
    if (cmd == 0) {tio.c_lflag &= (~ICANON & ~ECHO);} // disable canonical mode
    else if (cmd == 1) {tio.c_lflag |= (ICANON | ECHO);} // enable canonical mode
    tcsetattr(STDIN_FILENO,TCSANOW, &tio); // apply changes
}

void Terminal::print(const std::string &str, const int &x, const int &y)
{
    std::print("\033[{};{}H", y, x); // first move cursor to the print position
    std::print("{}", str); // then print
}

void Terminal::setCursor(const int &cmd)
{
    cmd == 1 ? std::print("\033[?25h") : std::print("\033[?25l");
}

void Terminal::clear()
{
    std::print("\033[2J");
}
