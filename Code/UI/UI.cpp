#include <Board.hpp>
#include <iostream>
#include <Windows.h>

void Card::Show() const
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    if(Front == false)
    {
        SetConsoleTextAttribute(console, 1);
        std::cout << "##";
        SetConsoleTextAttribute(console, 7);
        return;
    }

    if(Suit <= 2)
        SetConsoleTextAttribute(console, 4);
    else
        SetConsoleTextAttribute(console, 8);

    switch(Value)
    {
        case ACE:   std::cout << "A"; break;
        case JACK:  std::cout << "J"; break;
        case QUEEN: std::cout << "Q"; break;
        case KING:  std::cout << "K"; break;
        default:    std::cout << (int)Value;
    }
    switch(Suit)
    {
        case DIAMONDS:  std::cout << "D"; break;
        case HEARTS:    std::cout << "H"; break;
        case SPADES:    std::cout << "S"; break;
        case CLUBS:     std::cout << "C"; break;
    }
    SetConsoleTextAttribute(console, 7);
}

void Column::Show() const
{
    // something OpenGL related
}

void Stack::Show() const
{
    if(!Cards.empty())
    {
        Cards.top().Show();
        return;
    }

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 1);
    std::cout << "[]";
    SetConsoleTextAttribute(console, 7);
}

void Pointer::Show()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 5);
    std::cout << "<";
    SetConsoleTextAttribute(console, 7);
}

void Board::Show()
{
    // Stacks
    for(int i = 0; i < 4; ++i)
    {
        Stacks[i].Show();
        if(Pointer.GetMode() == STACK && Pointer.GetX() == i)
            Pointer.Show();
        std::cout << "\t";  // or another measure of distance
    }
    std::cout << "\t";

    // Hand
    if(CurrentCard + 1 < Hand.Size())
    {
        Hand[CurrentCard + 1].Show();
        if(Pointer.GetMode() == HAND && Pointer.GetX() == 0)
            Pointer.Show();
    }
    std::cout << "\t";
    if(CurrentCard >= 0)
    {
        Hand[CurrentCard].Show();
        if(Pointer.GetMode() == HAND && Pointer.GetX() == 1)
            Pointer.Show();
    }
    
    std::cout << "\n___________________________________________________\n";

    // Columns
    bool cardShown = true;
    for(unsigned int i = 0; cardShown == true; ++i)
    {
        cardShown = false;
        for(unsigned int j = 0; j < 7; ++j)
        {
            if(i < Columns[j].Size())
            {
                Columns[j][i].Show();
                cardShown = true;
                if(Pointer.GetMode() == COLUMN && Pointer.GetX() == j)
                {
                    if(Pointer.GetY() == Columns[j].Size() - 1 - i)
                        Pointer.Show();
                }
            }
            std::cout << "\t";
        }
        std::cout << "\n";
    }
    
}
