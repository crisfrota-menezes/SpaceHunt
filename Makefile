all: compile link clean

compile:
	g++ -c src/*.cpp -I"SFML/include"

link:
	g++ *.o -Wall -o main -L"SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system

clean:
	del *.o