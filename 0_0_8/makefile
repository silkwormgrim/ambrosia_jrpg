# ◊ MAKE_FILE
# ────────────────────────────
SFML_INCLUDE = C:\mingw64\sfml\include
SFML_LIB = C:\mingw64\sfml\lib
SFML_FILES = -lsfml-graphics -lsfml-window -lsfml-system
SFML_FULL = -L$(SFML_LIB) $(SFML_FILES)

OBJECTS = main.o video.o

all: main run

run:
	main.exe

main.o: main.cpp
	g++ -Wall -c main.cpp -I$(SFML_INCLUDE) -o main.o

video.o: video.cpp
	g++ -Wall -c video.cpp -I$(SFML_INCLUDE) -o video.o

main: $(OBJECTS)
	g++ $(OBJECTS) -o main.exe $(SFML_FULL)
	rm $(OBJECTS)