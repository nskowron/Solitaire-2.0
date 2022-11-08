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
private:
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
    void Remove(unsigned int); // removes & returns first x cards
    Column PickUp(unsigned int); // copies first x cards, doesnt remove them

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

enum PointerMode;
class Clipboard // keeps data about the origin of the clipboard card
{
    struct Data
    {
        Column column;
        Card card;
    };
    struct Origin
    {
        PointerMode mode;
        unsigned int X;
    };

public:
    Data data;

public:
    Origin origin;

    void Clear() { data.card = Card(); data.column = Column(); }
    bool Empty() { return data.card == Card() && data.column.Size() == 0; }
};

class Pointer;
class Board
{
public:
    Clipboard Clip;
    Deck Hand;
    int CurrentCard;
    Column* Columns;
    Stack* Stacks;

    // defined in Board.cpp
    Board();
    ~Board();
    void RemoveClip();

    // defined in UI.cpp
    void Show(Pointer*);
};
