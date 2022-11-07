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

void Board::RemoveClip()
{
    if(Clip.Empty() == false)
    {
        if(Clip.origin.mode == HAND)
            Hand.Remove(CurrentCard);

        else if(Clip.origin.mode == COLUMN)
            Columns[Clip.origin.X].Remove(Clip.data.column->Size());

        else if(Clip.origin.mode == STACK)
            Stacks[Clip.origin.X].Remove();
    }
}
