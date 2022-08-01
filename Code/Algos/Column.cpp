#include <Board.hpp>
#include <exception>

const Card& Column::operator[] (unsigned int i)
{
    if(i < Cards.size())
        return Cards.at(i);
    throw "Out of Column's range.\n";
}

void Column::Add(Card card)
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

void Column::Add(Column col)
{
    Add(col.Cards.front());
    for(int i = 1; i < col.Size(); ++i)
    {
        Cards.push_back(col.Cards.at(i));
    }
}

const Column& Column::Remove(unsigned int i)
{
    if(i > Cards.size())
        throw "There aren't that many cards in the column.\n";

    if(Cards.at(Cards.size() - i).Front == false)
        throw "Can't pick up uncovered cards.\n";

    Column col;
    while(i > 0)
    {
        auto currentCard = Cards.end() - i--;
        col.Cards.push_back(*currentCard);
        Cards.erase(currentCard);
    }
    Cards.back().Front = true;

    return col;
}
