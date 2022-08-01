#pragma once

enum CardValues { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum CardSuits { DIAMONDS = 1, HEARTS, CLUBS, SPADES };


class Card
{
private:
    CardValues Value;
    CardSuits Suit;

public:
    bool Front;

    Card(CardValues val, CardSuits sui, bool front = true) : Value(val), Suit(sui), Front(front) {};
    const CardValues& GetValue() const { return Value; }
    const CardSuits& GetSuit() const { return Suit; }

    bool operator == (Card card) { return Value == card.GetValue() && Suit == card.GetSuit(); }

    // defined in UI.cpp
    void Show();
};
