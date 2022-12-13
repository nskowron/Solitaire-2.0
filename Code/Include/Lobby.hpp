#pragma once

#include <Menu.hpp>
#include <Pointer.hpp>
#include <Game.hpp>

class Lobby
{
private:
    Menu Menu;
    Pointer Pointer;
    Game _Game;

public:
    Lobby::Lobby() : Pointer(), Menu(&Pointer, "Properties.json"), _Game(&Menu, &Pointer) {}
    void Open();
};