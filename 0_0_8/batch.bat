:: ◊ MAKE_FILE
:: ────────────────────────────
@ECHO OFF

CD %~dp0
make

PAUSE
EXIT /B %ERRORLEVEL%



::SET INCLUDE=-IC:\mingw64\sdl\include
::SET LINKDIR=-LC:\mingw64\sdl\lib

::g++ -Wall -c item_list.cpp %INCLUDE% 
::g++ -Wall -c character.cpp %INCLUDE% 
::g++ -Wall -c main.cpp %INCLUDE% 
::g++ *.o -o main.exe %LINKDIR% -lmingw32 -lSDL2main -lSDL2