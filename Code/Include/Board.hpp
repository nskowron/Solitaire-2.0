#pragma once

#include <vector>
#include <stack>
#include <Card.hpp>

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

    const Card& operator[] (unsigned int);
    const Card& Remove(unsigned int);
    void Add(Card);
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
    const Card& operator[] (unsigned int);
    void Add(Card); 
    void Add(Column);
    const Column& Remove(unsigned int); // removes & returns first x cards

    // defined in UI.cpp
    void Show();
};

class Stack
{
private:
    CardSuits Suit;
    std::stack<Card> Cards;

public:
    Stack(CardSuits sui) : Suit(sui) {}
    Stack(Card card) : Suit(card.GetSuit()), Cards({card}) {}

    // defined in Stack.cpp
    void Add(Card card);
    const Card& Remove();
    const Card& Top();

    // defined in UI.cpp (include the lack of card)
    void Show();
};


enum PointerMode { MENU, STACK, COLUMN, HAND };

class Pointer
{
private:
    PointerMode Mode;
    unsigned int X;
    unsigned int Y;

public:
    Pointer(PointerMode mod = COLUMN) : Mode(mod), X(0), Y(0) {}

    // defined in Pointer.cpp
    void AlterMode();
    void MvUp();
    void MvDown();
    void MvLeft();
    void MvRight();
};

