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
	g++ -c main.cpp -o main.o -Wall

video.o: video.cpp
	g++ -c video.cpp -o video.o -I$(SFML_INCLUDE) -Wall

main: $(OBJECTS)
	g++ $(OBJECTS) -o main.exe $(SFML_FULL)
	rm $(OBJECTS)