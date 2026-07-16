#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <vector>

struct Snake
{
	std::list<std::vector<int>> body; 
	char direction {'a'}; //WASD for control

	/* methods */
	Snake(const std::list<std::vector<int>> &body_input);
	void changeDirection(const char &dir);
	void grow();

};

#endif
