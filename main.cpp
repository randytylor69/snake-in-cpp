#include "terminal.h"
#include <stdio.h>
#include <thread>

static bool s_isFinished {false};
void gameLoop(Terminal &t)
{
    int count {0};

    while(!s_isFinished)
    {
	t.print("hi", count+=3, 13);
	t.delay(500);
    }

}

int main(){

    Terminal terminal;
    terminal.setCanonicalAndCursor(0);

    /* set up the canva */
    terminal.clear();
    terminal.printBorder(40, 20, 1);
    
    /* threading */
    std::thread worker(gameLoop, std::ref(terminal));

    /* loop to capture user input */
    char ch;
    while (ch!='q'){
	ch = std::getchar();
	switch(ch)
	{
	    case 'q':
		s_isFinished = true;
		terminal.printGameOver();
		break;
	}
    }
    worker.join();

    terminal.setCanonicalAndCursor(1);
    return 0;
}
