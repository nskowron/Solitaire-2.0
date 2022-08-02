#pragma once

#include <Board.hpp>
#include <Menu.hpp>

class Board;
class Menu;

enum PointerMode { COLUMN = 1, HAND, STACK, MENU, PROPERTIES };

class Pointer
{
private:
    PointerMode Mode;
    unsigned int X;
    unsigned int Y;
    unsigned int Color;

public:
    Board* _Board;
    Menu* _Menu;

    Pointer(Menu*, Board*, PointerMode = COLUMN);

    PointerMode GetMode() { return Mode; }
    unsigned int GetX() { return X; }
    unsigned int GetY() { return Y; }

    // defined in Pointer.cpp
    void AlterMode();
    void MvUp();
    void MvDown();
    void MvLeft();
    void MvRight();

    // defined in UI.cpp
    void Show();
};