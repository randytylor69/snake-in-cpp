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
	void print(const std::string &str, const int &x, const int &y);
	void clear(); // clear screen
};

#endif
