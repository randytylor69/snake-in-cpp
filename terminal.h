#ifndef TERMINAL_H
#define TERMINAL_H

#include <termios.h>
#include <string>
#include <vector>

class Terminal
{
    private:
	termios tio;
    public:
	/* public members */
	std::vector<std::vector<int>> borderPoints {};

	/* public methods */
	void setCanonicalAndCursor(const int &cmd);  // set terminal's canonical mode ON or OFF
	void delay(const int &time); // timeout for x seconds
	/* print to screen functions */
	void print(const std::string &str, const int &x, const int &y);
	void printBorder(const int &width, const int &height, const int &mode); // mode decides print border or not
	std::vector<std::vector<int>> mapBorderPoints(const int &width, const int &height);
	void clear(); // clear screen
	void printGameOver(const int &score);
};

#endif
