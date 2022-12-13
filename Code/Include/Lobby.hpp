#pragma once

#include <Game.hpp>
#include <Menu.hpp>
#include <Pointer.hpp>

enum ExitCode {GAME = 0, MENU = 1, NEW = 2, QUIT = 3};

class Lobby
{
private:
    Menu Menu;
    Pointer Pointer;
    Game Game;

public:
    Lobby();
};