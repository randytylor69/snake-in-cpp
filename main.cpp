#include "terminal.h"
#include "snake.h"
#include <stdio.h>
#include <thread>
#include <list>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

static bool s_isFinished {false};
static int s_wWidth {40};
static int s_wHeight {20};
static int s_score {0};
void gameLoop(Terminal &t, Snake &snake, std::vector<int> &fruit)
{
    while(!s_isFinished)
    {
	/* update head */
	switch (snake.direction)
	{
	    case 'w':
		snake.body.push_front({snake.body.front()[0], snake.body.front()[1]-1});break;
	    case 'a':
		snake.body.push_front({snake.body.front()[0]-1, snake.body.front()[1]});break;
	    case 's':
		snake.body.push_front({snake.body.front()[0], snake.body.front()[1]+1});break;
	    case 'd':
		snake.body.push_front({snake.body.front()[0]+1, snake.body.front()[1]});break;
	}
	/* cut tail */
	snake.body.pop_back();

	/* set up the canva */
	t.clear();
	t.printBorder(s_wWidth, s_wHeight, 1);
	t.print("@", fruit[0], fruit[1]);

	int randomWidth = fruit[0];
	int randomHeight = fruit[1];
	/* draw snake */
	for (auto &s : snake.body)
	{
	    /* collision detection */
	    if (s==snake.body.front())
	    { 
		if(s[0]==fruit[0] && s[1]==fruit[1]) 
		{ // snake eats fruit
		    snake.grow();
		    s_score++;
		    /* randomize fruit spawn */
		    randomWidth = rand()%(s_wWidth-1)+2;
		    randomHeight = rand()%(s_wHeight-1)+2;
		}
		/* collision against walls */
		for (auto &bp : t.borderPoints)
		{
		    if (bp[0]==s[0]&&bp[1]==s[1])
		    {
			s_isFinished = true;
			t.printGameOver(s_score);
			break;
		    }
		}
		/* collision against body */
		auto headlessBody = snake.body;
		headlessBody.pop_front();

		for (auto &bp : headlessBody)
		{
		    if (bp[0]==s[0]&&bp[1]==s[1])
		    {
			s_isFinished = true;
			t.printGameOver(s_score);
			break;
		    }
		}
		
	    } 
	    if (s_isFinished) break;
	    t.print(s==snake.body.front()?"O":"o", s[0], s[1]);
	}

	fruit={randomWidth, randomHeight};
	t.delay(200);
    }

}

int main(){
    
    Snake snake({{15, 10}, {16, 10}, {17,10}});
    std::vector<int> fruit{3, 8}; 
    Terminal terminal;
    terminal.setCanonicalAndCursor(0);
    terminal.mapBorderPoints(s_wWidth, s_wHeight);

    
    /* threading */
    std::thread worker(gameLoop, std::ref(terminal), std::ref(snake), std::ref(fruit));

    /* loop to capture user input */
    char ch;
    while (ch!='q'){
	if (s_isFinished) break;
	ch = std::getchar();
	switch(ch)
	{
	    case 'q':
		s_isFinished = true;
		terminal.printGameOver(s_score);
		break;
	    case 'w':
		if (snake.direction!='s')snake.changeDirection('w');
		break;
	    case 'a':
		if (snake.direction!='d')snake.changeDirection('a');
		break;
	    case 's':
		if (snake.direction!='w')snake.changeDirection('s');
		break;
	    case 'd':
		if (snake.direction!='a')snake.changeDirection('d');
		break;
	}
    }
    worker.join();

    terminal.setCanonicalAndCursor(1);
    
    return 0;
}
