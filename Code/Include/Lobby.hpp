#pragma once

#include <Game.hpp>
#include <Menu.hpp>
#include <Pointer.hpp>

class Lobby
{
private:
    Menu Menu;
    Pointer Pointer;
    Game Game;

public:
    Lobby();
};