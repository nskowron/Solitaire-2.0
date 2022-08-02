#pragma once

#include <vector>
#include <stack>
#include <Card.hpp>
#include <Pointer.hpp>


class Deck
{
private:
    std::vector<Card> Cards;

public:
    Deck() : Cards({}) {}
    Deck(Card card) : Cards({card}) {}

    unsigned int Size() { return Cards.size(); }

    // defined in Deck.cpp
    Deck(bool full); // true - Deck will be full

    Card& operator[] (unsigned int);
    Card& Remove(unsigned int);
    void Add(Card);
    void Shuffle();
};

class Column
{
public:
    std::vector<Card> Cards;

public:
    Column() : Cards({}) {}
    Column(Card card) : Cards({card}) {}

    unsigned int Size() { return Cards.size(); }
    void Push(Card card) { Cards.push_back(card); }

    // defined in Column.cpp
    Card& operator[] (unsigned int);
    void Add(Card); 
    void Add(Column);
    Column& Remove(unsigned int); // removes & returns first x cards

    // defined in UI.cpp
    void Show() const;
};

class Stack
{
private:
    CardSuits Suit;
    std::stack<Card> Cards;

public:
    Stack() {}
    Stack(CardSuits sui) : Suit(sui) {}
    Stack(Card card) : Suit(card.GetSuit()), Cards({card}) {}

    // defined in Stack.cpp
    void Add(Card card);
    Card& Remove();
    Card& Top();

    // defined in UI.cpp (include the lack of card)
    void Show() const;
};

class Pointer;
class Board
{
public:
    Deck Hand;
    int CurrentCard;
    Column* Columns;
    Stack* Stacks;

    // defined in Board.cpp
    Board();
    ~Board();

    // defined in UI.cpp
    void Show(Pointer*);
};
