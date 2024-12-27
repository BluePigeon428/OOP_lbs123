all: main clean

main: main.o controller.o cell.o field.o entity.o enemy.o player.o
	g++ main.o controller.o cell.o field.o entity.o enemy.o player.o

main.o: main.cpp
	g++ -c main.cpp

controller.o: controller.cpp controller.h entities/player.h entities/enemy.h
	g++ -c controller.cpp

field.o: field/field.cpp field/field.h field/cell.h
	g++ -c field/field.cpp

cell.o: field/cell.cpp field/cell.h
	g++ -c field/cell.cpp

player.o: entities/player.cpp entities/player.h entities/entity.h
	g++ -c entities/player.cpp

enemy.o: entities/enemy.cpp entities/enemy.h entities/entity.h
	g++ -c entities/enemy.cpp

entity.o: entities/entity.cpp entities/entity.h
	g++ -c entities/entity.cpp



clean: main
	rm -f *.o