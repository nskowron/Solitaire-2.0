#pragma once

#include <Board.hpp>
#include <Menu.hpp>
#include <iostream>

class Board;
class Menu;

enum PointerMode { COLUMN = 1, HAND, STACK, pMENU, PROPERTIES };

class Pointer
{
private:
    PointerMode Mode;
    unsigned int X;
    unsigned int Y;

public:
    Board* _Board;
    Menu* _Menu;

    Pointer() :  X(0), Y(0), Mode(COLUMN), _Board(nullptr), _Menu(nullptr) {}

    bool operator==(Pointer);

    PointerMode GetMode() { return Mode; }
    unsigned int GetX() { return X; }
    unsigned int GetY() { return Y; }
    void OpenMenu() { Mode = pMENU; }
    void OpenProperties() { Mode = PROPERTIES; }

    // defined in Pointer.cpp
    void AlterGameMode();
    void MvUp();
    void MvDown();
    void MvLeft();
    void MvRight();

    // defined in UI.cpp
    void Show();
};