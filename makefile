CXX = g++
FLAGS = -std=c++23

main.exe: terminal.o main.o snake.o
	${CXX} ${FLAGS} $^ -o $@

terminal.o: terminal.cpp
	${CXX} ${FLAGS} -c $^ -o $@

snake.o: snake.cpp
	${CXX} ${FLAGS} -c $^ -o $@

main.o: main.cpp
	${CXX} ${FLAGS} -c $^ -o $@

