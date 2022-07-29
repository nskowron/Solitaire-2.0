#pragma once

#include <vector>
#include <Card.hpp>

class Deck
{
private:
    std::vector<Card> Cards;

public:
    Deck() : Cards({}) {}
    Deck(Card card) : Cards({card}) {}

    // defined in Algos.cpp
    Deck(bool full); // true - Deck will be full

    const Card& operator [] (unsigned int);
    const Card& Remove(unsigned int);
    void Add(Card card);
};

class Column
{
private:
    std::vector<Card> Cards;

public:
    Column() : Cards({}) {}
    Column(Card card) : Cards({card}) {}

    // defined in Algos.cpp
    void Add(Card); 
    void Add(Column);
    const Column& Remove(int); // removes & returns first x cards

    // defined in UI.cpp
    void Show();
};