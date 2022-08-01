#include <Board.hpp>
#include <exception>

void Stack::Add(Card card)
{
    if(Suit != card.GetSuit())
        throw "Card must be of the same suit as the stack.\n";

    if(Cards.empty())
    {
        if(card.GetValue() == ACE)
        {
            Cards.push(card);
            return;
        }
        throw "Cards have to be stacked increasingly, starting with an Ace.\n";
    }
    else
    {
        if(card.GetValue() == Cards.top().GetValue() + 1)
        {
            Cards.push(card);
            return;
        }
        throw "Cards have to be stacked increasingly, starting with an Ace.\n";
    }
}

const Card& Stack::Remove()
{
    if(Cards.empty())
        throw "The stack is empty.\n";

    Card card(Cards.top());
    Cards.pop();
    return card;
}

const Card& Stack::Top()
{
    if(Cards.empty())
        throw "The stack is empty.\n";
    return Cards.top();
}
