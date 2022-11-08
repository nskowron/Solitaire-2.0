#include <Board.hpp>

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

void Board::AddToClip(Pointer* pointer)
{
    Clip.origin.mode = pointer->GetMode();
    Clip.origin.X = pointer->GetX();

    if(pointer->GetMode() == HAND)
        Clip.data.card = Hand[CurrentCard];

    else if(pointer->GetMode() == COLUMN)
        Clip.data.column = Columns[pointer->GetX()].PickUp(Columns[pointer->GetX()].Size() - pointer->GetY());

    else if(pointer->GetMode() == STACK)
        Clip.data.card = Stacks[pointer->GetX()].Top();
}

void Board::PutBackClip(Pointer* pointer)
{
    if(pointer->GetMode() == HAND)
        throw "Can't put cards here.\n";

    else if(pointer->GetMode() == COLUMN)
    {
        if(Clip.data.card == Card())
            Columns[pointer->GetX()].Add(Clip.data.column);
        else
            Columns[pointer->GetX()].Add(Clip.data.card);
    }
    else if(pointer->GetMode() == STACK)
    {
        if(Clip.data.column.Size() > 1)
            throw "Can put only 1 card on a stack.\n";

        else if(Clip.data.column.Size() == 1)
            Stacks[pointer->GetX()].Add(Clip.data.column[0]);
        else
            Stacks[pointer->GetX()].Add(Clip.data.card);
    }
}

void Board::RemoveClip()
{
    if(Clip.Empty() == false)
    {
        if(Clip.origin.mode == HAND)
        {
            Hand.Remove(CurrentCard);
            CurrentCard--;
        }

        else if(Clip.origin.mode == COLUMN)
            Columns[Clip.origin.X].Remove(Clip.data.column.Size());

        else if(Clip.origin.mode == STACK)
            Stacks[Clip.origin.X].Remove();
    }
}

void Board::FlipHand()
{
    if(CurrentCard + 1 == Hand.Size())
        CurrentCard = -1;
    else
    {
        CurrentCard++;
        Hand[CurrentCard].Front = true;
    }

    if(CurrentCard + 1 != Hand.Size())
        Hand[CurrentCard + 1].Front = false;
}
