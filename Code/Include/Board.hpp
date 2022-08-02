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


enum PointerMode { MENU = 1, STACK, COLUMN, HAND };

class Board;
class Pointer
{
private:
    PointerMode Mode;
    unsigned int X;
    unsigned int Y;

public:
    Board* Board;

    Pointer(PointerMode mod = COLUMN) : Mode(mod), X(0), Y(0) {}

    PointerMode GetMode() { return Mode; }
    unsigned int GetX() { return X; }
    unsigned int GetY() { return Y; }

    // defined in Pointer.cpp
    void AlterMode();
    void MvUp();
    void MvDown();
    void MvLeft();
    void MvRight();

    // defined in UI.cpp
    void Show();
};

class Board
{
public:
    Deck Hand;
    int CurrentCard;
    Column* Columns;
    Stack* Stacks;
    Pointer Pointer;

    Board();
    ~Board();

    void Show();
};
