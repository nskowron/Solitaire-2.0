#include <Board.hpp>
#include <exception>

Card& Column::operator[] (unsigned int i)
{
    if(i < Cards.size())
        return Cards.at(i);
    throw "Out of Column's range.\n";
}

void Column::Add(Card& card)
{
    if(Cards.empty())
    {
        if(card.GetValue() == KING)
        {
            Cards.push_back(card);
            return;
        }
        throw "Only King can be placed in an empty spot.\n";
    }

    if(card.GetValue() == Cards.back().GetValue() - 1)
    {
        if(Cards.back().GetSuit() <= 2)
        {
            if(card.GetSuit() > 2)
            {
                Cards.push_back(card);
                return;
            }
            throw "Cards have to be placed on cards with a different color.\n";
        }
        else
        {
            if(card.GetSuit() <= 2)
            {
                Cards.push_back(card);
                return;
            }
            throw "Cards have to be placed on cards with a different color.\n";
        }
    }
    throw "Cards have to be placed decreasingly.\n";
}

/* void Column::Add(Column col)
{
    Add(col.Cards.front());
    for(int i = 1; i < col.Size(); ++i)
    {
        Cards.push_back(col.Cards.at(i));
    }
} */

void Column::Remove(unsigned int i)
{
    if(operator[](i).Front == false)
        throw "Can't remove uncovered cards.\n";

    Cards.erase(Cards.begin() + i, Cards.end());

    if(Cards.size() > 0)
        Cards.back().Front = true;
}

Card& Column::PickUp(unsigned int i) // Index of pointer
{
    if(operator[](i).Front == false)
        throw "Can't pick up uncovered cards.\n";

    for(unsigned int j = i; j < Size(); ++j)
        operator[](j).Picked = true;

    return operator[](i);
}

void Column::Unpick(unsigned int i)
{
    while(i < Size())
    {
        operator[](i).Picked = false;
        ++i;
    }
}
