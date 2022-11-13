#include <Board.hpp>
#include <exception>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

Deck::Deck(bool full)
{
    for(CardSuits sui = DIAMONDS; sui <= SPADES; sui = CardSuits(sui + 1))
    {
        for(CardValues val = ACE; val <= KING; val = CardValues(val + 1))
        {
            Cards.push_back(Card(val, sui));
        }
    }
}

Card& Deck::operator[](unsigned int i)
{
    if(i < Cards.size() && i >= 0)
        return Cards.at(i);
    throw "Out of Deck's range.\n";
}

Card& Deck::PickUp(unsigned int i)
{
    operator[](i).Picked = true;
    return operator[](i);
}

void Deck::Unpick(unsigned int i)
{
    operator[](i).Picked = false;
}

Card Deck::Remove(unsigned int i)
{
    Card card(operator[](i));
    Cards.erase(Cards.begin() + i);
    return card;
}

void Deck::Add(Card& card)
{
    Cards.push_back(card);
}

void Deck::Shuffle()
{
    if(Cards.size() > 0)
    {
        srand(time(NULL));
        for(int i = 0; i < 200; ++i)
        {
            std::swap(Cards.at(rand() % Cards.size()), Cards.at(rand() % Cards.size()));
        }
    }
}
