A very simple terminal based snake game done in pure C++, with a custom console game engine (~120 lines with `.h` & `.cpp` files).

One interesting thing is that the game is multi-threadded, meaning the game can loop with `while(1)` on one thread, while we run another `while(1)` loop on the main thread to check for user input. This way, although user input is obtained with the thread-blocking `std::getchar()`, the game loop won't be blocked.

<div align="center">

| ![Screenshot of the game](https://github.com/randytylor69/snake-in-cpp/blob/main/screenshots/newscreenshot_012.jpg) |
| :--: |
| Screenshot of the snake `ooooO` in its infancy, chasing for [@](https://en.wikipedia.org/wiki/Forbidden_fruit) |

</div>

The game is designed to run on Unix OS.

## How to run
The program uses `makefile` to compile, so simply:

```bash
make && ./main.exe
```
