#include <Board.hpp>
#include <exception>

void Stack::Add(Card card)
{
    if(Cards.empty())
    {
        if(card.GetValue() == ACE)
        {
            Cards.push(card);
            Suit = card.GetSuit();
            return;
        }
        throw "Cards have to be stacked increasingly, starting with an Ace.\n";
    }

    if(Suit != card.GetSuit())
        throw "Card must be of the same suit as the stack.\n";

    if(card.GetValue() == Cards.top().GetValue() + 1)
    {
        Cards.push(card);
        return;
    }
    throw "Cards have to be stacked increasingly, starting with an Ace.\n";
}

Card& Stack::Remove()
{
    if(Cards.empty())
        throw "The stack is empty.\n";

    Card card(Cards.top());
    Cards.pop();
    return card;
}

Card& Stack::Top()
{
    if(Cards.empty())
        throw "The stack is empty.\n";
    return Cards.top();
}
