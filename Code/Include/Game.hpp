#include <Menu.hpp>
#include <Board.hpp>
#include <Pointer.hpp>

class Game
{
private:
    Board board;
    Menu menu;
    Pointer pointer;

public:
    Game() : pointer(&menu, &board) {}

    // defined in UI.cpp
    void Show();
};