#pragma once

#include <Board.hpp>
#include <Menu.hpp>
#include <Button.hpp>

#include <iostream>

class Board;
class Menu;
class Button;

enum PointerMode { COLUMN = 1, HAND, STACK, pMENU, PROPERTIES, pBUTTON };

class Pointer
{
private:
    PointerMode Mode;
    unsigned int X;
    unsigned int Y;

public:
    Board* _Board;
    Menu* _Menu;
    Button* _Button;

    Pointer() :  X(0), Y(0), Mode(COLUMN), _Board(nullptr), _Menu(nullptr), _Button(nullptr) {}

    bool operator==(Pointer);

    PointerMode GetMode() { return Mode; }
    unsigned int GetX() { return X; }
    unsigned int GetY() { return Y; }

    void OpenMenu() { _Button = nullptr; Mode = pMENU; Reset(); }
    void OpenProperties() { _Button = nullptr; Mode = PROPERTIES; Reset(); }
    void OpenGame() { _Button = nullptr; Mode = COLUMN; Reset(); }
    void OpenButton(Button* button) { _Button = button; Mode = pBUTTON; Reset(); }
    void Reset() { X = Y = 0; }

    // defined in Pointer.cpp
    void AlterGameMode();
    void MvUp();
    void MvDown();
    void MvLeft();
    void MvRight();

    // defined in UI.cpp
    void Show();
};