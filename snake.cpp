#include "snake.h";

Snake::Snake(const std::list<std::vector<int>> &body_input)
    :body(body_input){}

void Snake::changeDirection(const char &dir)
{
    direction = dir;
}

void Snake::grow()
{
    std::vector<int> tempBack = body.back();
    switch(direction)
    {
	case 'w':
	    body.push_back({tempBack[0], tempBack[1]+1});break;
	case 'a':
	    body.push_back({tempBack[0]+1, tempBack[1]});break;
	case 's':
	    body.push_back({tempBack[0], tempBack[1]-1});break;
	case 'd':
	    body.push_back({tempBack[0]-1, tempBack[1]});break;
    }
}
