#pragma once

#include <Board.hpp>
#include <Menu.hpp>

enum ExitCode;
class Game
{
private:
    Board Board;
    Menu* _Menu;
    Pointer* _Pointer;
    bool Finish;

    void AutoFinish();

public:
    Game(Menu*, Pointer*);

    //defined in Game.cpp
    ExitCode Move();

    // defined in UI.cpp
    void Show();
};