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
    Card& PickUp(unsigned int);
    void Unpick(unsigned int);
    Card Remove(unsigned int);
    void Add(Card&);
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
    void Push(Card& card) { Cards.push_back(card); }

    // defined in Column.cpp
    Card& operator[] (unsigned int);
    void Add(Card&); 
    //void Add(Column);
    void Remove(unsigned int); // removes & returns cards at index x and higher
    Card& PickUp(unsigned int);
    void Unpick(unsigned int);

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

    unsigned int Size() { return Cards.size(); }

    // defined in Stack.cpp
    void Add(Card&);
    Card& Top();
    Card& PickUp();
    void Unpick();
    Card Remove();

    // defined in UI.cpp (include the lack of card)
    void Show() const;
};

enum PointerMode;
class Pointer;
class Clipboard // keeps data about the origin of the clipboard card
{

public:
    Card* Data;
    Pointer* Origin;

    Clipboard() { Clear(); }

    void Clear() { Data = nullptr; }
    bool Empty() { return Data == nullptr; }
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
    void PickUp(Pointer*);
    void Unpick(Pointer*);
    void PutDown(Pointer*);
    //void ClearClip();
    void RemoveClip();
    void FlipHand();

    // defined in UI.cpp
    void Show(Pointer*);
};
