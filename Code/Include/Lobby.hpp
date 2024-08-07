#pragma once

#include <Menu.hpp>
#include <Pointer.hpp>
#include <Game.hpp>

class Lobby
{
private:
    Menu Menu;
    Pointer Pointer;
    Game* _Game;

public:
    Lobby() : Pointer(), Menu(&Pointer, "Properties.json") { _Game = new Game(&Menu, &Pointer); }
    ~Lobby() { delete _Game; }

    // Defined in Lobby.cpp
    void Open();
};