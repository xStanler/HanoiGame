output: main.o Button.o Pole.o
	g++ main.o Button.o Pole.o -o HanoiGame -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system


main.o: main.cpp 
	g++ -Isrc/include -c main.cpp 

Button.o: Button.cpp Button.hpp
	g++ -Isrc/include -c Button.cpp

Pole.o: Pole.cpp Pole.hpp
	g++ -Isrc/include -c Pole.cpp

clean:
	del *.o main