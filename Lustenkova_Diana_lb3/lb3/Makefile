all: main clean

main: main.o controller.o cell.o field.o field_creator.o entity.o enemy.o player.o Damage.o Healing.o Rift.o
	g++ main.o controller.o cell.o field.o field_creator.o entity.o enemy.o player.o Damage.o Healing.o Rift.o

main.o: main.cpp field/field_creator.h
	g++ -c main.cpp

controller.o: controller.cpp controller.h entities/player.h entities/enemy.h
	g++ -c controller.cpp

field.o: field/field.cpp field/field.h field/cell.h
	g++ -c field/field.cpp

cell.o: field/cell.cpp field/cell.h events/Healing.h events/Damage.h events/Rift.h events/event.h
	g++ -c field/cell.cpp

field_creator.o: field/field_creator.cpp field/field_creator.h field/field.h events/Healing.h events/Damage.h events/Rift.h
	g++ -c field/field_creator.cpp

player.o: entities/player.cpp entities/player.h entities/entity.h
	g++ -c entities/player.cpp

enemy.o: entities/enemy.cpp entities/enemy.h entities/entity.h
	g++ -c entities/enemy.cpp

entity.o: entities/entity.cpp entities/entity.h field/field.h
	g++ -c entities/entity.cpp

Damage.o: events/Damage.cpp events/Damage.h events/event.h
	g++ -c events/Damage.cpp

Healing.o: events/Healing.cpp events/Healing.h events/event.h
	g++ -c events/Healing.cpp

Rift.o: events/Rift.cpp events/Rift.h events/event.h
	g++ -c events/Rift.cpp


clean: main
	rm -f *.o