a.out: tree.o Room.o Girl.o main.o
	g++ tree.o Room.o Girl.o main.o
main.o: main.cpp Room.o Girl.o tree.o
	g++ -c main.cpp Room.o Girl.o tree.o
Girl.o: Girl.cpp Girl.h tree.cpp Room.cpp
	g++ -c Girl.cpp
Room.o: Room.cpp Room.h
	g++ -c Room.cpp
tree.o: tree.cpp tree.h Treend.h
	g++ -c tree.cpp
clean:
	rm -rf a.out *.o
