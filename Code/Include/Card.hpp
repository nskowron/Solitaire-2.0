#pragma once

enum CardValues { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum CardSuits { DIAMONDS, HEARTS, CUBS, SPADES };


class Card
{
private:
    CardValues Value;
    CardSuits Suit;

public:
    bool Front;

    Card(CardValues val, CardSuits sui, bool front = true) : Value(val), Suit(sui), Front(front) {};
    const CardValues& GetValue() { return Value; }
    const CardSuits& GetSuit() { return Suit; }

    // defined in UI.cpp
    void Show();
};
