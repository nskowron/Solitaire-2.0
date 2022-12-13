#pragma once


#include <Menu.hpp>
#include <Board.hpp>
#include <Pointer.hpp>
#include <Lobby.hpp>


enum ExitCode;
class Board;
class Game
{
private:
    Board Board;
    Menu* _Menu;
    Pointer* _Pointer;

public:
    Game(Menu*, Pointer*);

    //defined in Game.cpp
    ExitCode Move();

    // defined in UI.cpp
    void Show();
};