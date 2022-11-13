#pragma once

#include <Menu.hpp>
#include <Board.hpp>
#include <Pointer.hpp>

class Game
{
public:
    Board Board;
    Pointer ClipHolder; // Probably temprorary - needed to avoid errors with Clipboard
    Menu* _Menu;
    Pointer* _Pointer;

public:
    Game(Menu*, Pointer*);

    //defined in Game.cpp
    int Play();

    // defined in UI.cpp
    void Show();
};