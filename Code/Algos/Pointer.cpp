#include <Board.hpp>

void Pointer::AlterMode()
{
    Mode = PointerMode(Mode % 4 + 1);
}

void Pointer::MvUp()
{
    if(Mode == COLUMN)
    {
        
    }
}
