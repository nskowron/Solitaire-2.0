#include <Board.hpp>
#include <exception>

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

const Card& Deck::operator[](unsigned int i)
{
    if(i < Cards.size())
        return Cards.at(i);
    throw "Out of Deck's range.\n";
}

const Card& Deck::Remove(unsigned int i)
{
    if(i < Cards.size())
    {
        Card card(Cards.at(i));
        Cards.erase(Cards.begin() + i);
        return card;
    }
    throw "Out of Deck's range.\n";
}

void Deck::Add(Card card)
{
    Cards.push_back(card);
}
