#ifndef TERMINAL_H
#define TERMINAL_H

#include <termios.h>
#include <string>

class Terminal
{
    private:
	termios tio;
    public:

	void setCanonicalAndCursor(const int &cmd);  // set terminal's canonical mode ON or OFF
	void delay(const int &time); // timeout for x seconds
	/* print to screen functions */
	void print(const std::string &str, const int &x, const int &y);
	void printBorder(const int &width, const int &height, const int &mode); // mode decides print border or not
	void clear(); // clear screen
	void printGameOver();
};

#endif
