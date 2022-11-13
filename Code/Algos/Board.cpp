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

void Board::PickUp(Pointer* pointer) //podswietla
{
    *Clip.Origin = *pointer;

    if(pointer->GetMode() == HAND)
        Clip.Data = &Hand.PickUp(CurrentCard);

    else if(pointer->GetMode() == COLUMN)
        Clip.Data = &Columns[pointer->GetX()].PickUp(pointer->GetY());

    else if(pointer->GetMode() == STACK)
        Clip.Data = &Stacks[pointer->GetX()].PickUp();
}

void Board::Unpick(Pointer* pointer)
{
    if(pointer->GetMode() == HAND)
        Hand.Unpick(CurrentCard);

    else if(pointer->GetMode() == COLUMN)
        Columns[pointer->GetX()].Unpick(pointer->GetY());

    else if(pointer->GetMode() == STACK)
        Stacks[pointer->GetX()].Unpick();
}

void Board::PutDown(Pointer* pointer)
{
    if(pointer->GetMode() == HAND)
        throw "Can't put cards here.\n";

    else if(Clip.Origin->GetMode() == COLUMN)
    {
        if(pointer->GetMode() == COLUMN)
        {
            for(unsigned int i = Clip.Origin->GetY(); i < Columns[Clip.Origin->GetX()].Size(); ++i)
                Columns[pointer->GetX()].Add(Columns[Clip.Origin->GetX()][i]);
        }

        else if(pointer->GetMode() == STACK)
        {
            if(Clip.Origin->GetY() == Columns[Clip.Origin->GetX()].Size() - 1)
                Stacks[pointer->GetX()].Add(*Clip.Data);
            else
                throw "Can't put more than one card on stack.\n";
        }
    }
    else if(pointer->GetMode() == COLUMN)
        Columns[pointer->GetX()].Add(*Clip.Data);
        
    else if(pointer->GetMode() == STACK)
        Stacks[pointer->GetX()].Add(*Clip.Data);
}

void Board::RemoveClip()
{
    if(Clip.Empty() == false)
    {
        if(Clip.Origin->GetMode() == HAND)
        {
            Hand.Remove(CurrentCard);
            CurrentCard--;
        }

        else if(Clip.Origin->GetMode() == COLUMN)
            Columns[Clip.Origin->GetX()].Remove(Clip.Origin->GetY());

        else if(Clip.Origin->GetMode() == STACK)
            Stacks[Clip.Origin->GetX()].Remove();
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
