#include "terminal.h"
#include <string>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <print>
#include <cstdio>
#include <chrono> // for delay
#include <thread> // for delay


void Terminal::setCanonicalAndCursor(const int &cmd)
{
    /* canonical changes */
    tcgetattr(STDIN_FILENO, &tio); // get current terminal setting
    if (cmd == 0) {tio.c_lflag &= (~ICANON & ~ECHO);} // disable canonical mode
    else if (cmd == 1) {tio.c_lflag |= (ICANON | ECHO);} // enable canonical mode
    tcsetattr(STDIN_FILENO,TCSANOW, &tio); // apply changes
    
    /* cursor changes */
    cmd == 1 ? std::print("\033[?25h") : std::print("\033[?25l");
}

void Terminal::delay(const int &time)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

/* =============== PRINT FUNCTIONS =================== */

void Terminal::print(const std::string &str, const int &x, const int &y)
{
    std::print("\033[{};{}H", y, x); // first move cursor to the print position
    std::print("{}", str); // then print
    std::fflush(stdout);
}

void Terminal::printBorder(const int &width, const int &height, const int &mode)
{
    /* print top border */
    std::print("\033[1;1H");

    for (int i=1;i<=height;i++)
    {
	/* print top & bottom borders */
	if (i==1 || i==height)
	{
	    for (int j=1;j<=width;j++) mode==1?printf("—"):printf(" ");
	} else 
	{
	    /* print left & right borders */
	    for (int j=1;j<=width;j++){
		if (j==1 || j==width)
		{
		    std::print("\033[{};{}H", i, j);
		    mode==1?printf("|"):printf(" ");
		}
	    }
	} printf("\n");
    }
}

void Terminal::clear()
{
    printf("\033[2J");  // clear screen
    std::fflush(stdout);
    printf("\033[1;1H"); // move cursor to top left
    std::fflush(stdout);
}

void Terminal::printGameOver()
{
    clear();
    printf("Le game is Le over\n");
}
