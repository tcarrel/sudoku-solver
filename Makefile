ARGS = -Wall -pedantic -std=c++11 -time -g

all: .main.o .Game.o .Init.o .Colors.o .Structs.o .Commands.o
	g++ $(ARGS) .Structs.o .main.o .Game.o .Init.o .Colors.o .Commands.o -o sudoku

.main.o: main.cpp Game.h Structs.h Colors.h Debug.h Init.h
	g++ $(ARGS) -c main.cpp -o .main.o

.Init.o: Init.cpp Init.h Colors.h Debug.h
	g++ $(ARGS) -c Init.cpp -o .Init.o

.Colors.o: Colors.cpp Colors.h Debug.h
	g++ $(ARGS) -c Colors.cpp -o .Colors.o

.Game.o: Game.cpp Init.h Game.h Structs.h Debug.h
	g++ $(ARGS) -c Game.cpp -o .Game.o

.Structs.o: Structs.cpp Structs.h
	g++ $(ARGS) -c Structs.cpp -o .Structs.o

.Commands.o: Commands/Command_base.cpp Commands/Command_base.h
	g++ $(ARGS) -c Commands/Command_base.cpp -o ../.Commands.o

clean:
	rm -f .*.o sudoku
