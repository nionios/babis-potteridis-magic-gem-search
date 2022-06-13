make:
	g++ -lncurses\
 ./src/intro/intro.cpp\
 ./src/map/map.cpp\
 ./src/map/print_map.cpp\
 ./src/map/print_map_menu.cpp\
 ./src/main.cpp\
 ./src/entities/gem.cpp\
 ./src/entities/malfoy.cpp\
 ./src/entities/potter.cpp\
 ./src/base_classes/entity.cpp\
 ./src/base_classes/movable.cpp\
 ./src/helpers/vector_printer.cpp\
 ./src/helpers/gather.cpp\
 ./src/helpers/init_pairs.cpp\
 ./src/helpers/setup_ncurses.cpp\
 ./src/files/load/load.cpp\
 ./src/files/interpret/interpret.cpp\
 ./src/exceptions/exceptions.cpp\
 ./src/mechanics/place.cpp\
 ./src/mechanics/erase.cpp\
 -I./include/intro/\
 -I./include/map/\
 -I./include/entities/\
 -I./include/base_classes/\
 -I./include/helpers/\
 -I./include/files/load/\
 -I./include/files/interpret/\
 -I./include/exceptions/\
 -I./include/mechanics/\
 -o $(ONAME)
	mv $(ONAME) ./bin/
run:
	make
	./bin/$(ONAME)

ONAME=Potter_and_the_Search_for_the_Magic_Gem
