# ◊ MAKE_FILE
# ────────────────────────────
SFML_INCLUDE = -IC:\mingw64\sfml\include
SFML_LIB = -LC:\mingw64\sfml\lib
SFML_FILES = -lsfml-graphics -lsfml-window -lsfml-system

OBJECTS = main.o

all: main run

clean:
	rm main.exe
	rm $(OBJECTS)

run:
	main.exe

main.o: main.cpp
	g++ -Wall main.cpp -c -o main.o $(SFML_INCLUDE)

main: $(OBJECTS)
	g++ $(OBJECTS) -o main.exe $(SFML_LIB) $(SFML_FILES)
	rm $(OBJECTS)