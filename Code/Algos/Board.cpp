#include <Board.hpp>

void Foo() {}

Board::Board() : Hand(true), CurrentCard(-1)
{
    Columns = new Column[7];
    Stacks = new Stack[4];

    Hand.Shuffle();
    for(int i = 0; i < 7; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            Hand[0].Front = false;
            Columns[i].Push(Hand.Remove(0));
        }
        Columns[i][i].Front = true;
    }
    Hand[0].Front = false;
}

Board::~Board()
{
    delete [] Columns;
    delete [] Stacks;
}
