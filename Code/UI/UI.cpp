#include <Board.hpp>
#include <Menu.hpp>
#include <Pointer.hpp>
#include <Game.hpp>

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
        SetConsoleTextAttribute(console, Picked ? 4 + 16*5 : 4);
    else
        SetConsoleTextAttribute(console, Picked ? 8 + 16*5 : 8);

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
    if(_Board == nullptr || _Menu == nullptr)
        throw "Pointer not assigned.\n";

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, _Menu->GetProperties()[POINTER_COLOR]);
    std::cout << "<";
    SetConsoleTextAttribute(console, 7);
}

void Board::Show(Pointer* Pointer)
{
    // Stacks
    for(int i = 0; i < 4; ++i)
    {
        Stacks[i].Show();
        if(Pointer->GetMode() == STACK && Pointer->GetX() == i)
            Pointer->Show();
        std::cout << "\t";  // or another measure of distance
    }
    std::cout << "\t";

    // Hand
    if(CurrentCard + 1 < Hand.Size())
        Hand[CurrentCard + 1].Show();
    if(Pointer->GetMode() == HAND && Pointer->GetX() == 0)
        Pointer->Show();
        
    std::cout << "\t";
    if(CurrentCard >= 0)
    {
        Hand[CurrentCard].Show();
        if(Pointer->GetMode() == HAND && Pointer->GetX() == 1)
            Pointer->Show();
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
            }
            if(Pointer->GetMode() == COLUMN && Pointer->GetX() == j && Pointer->GetY() == i)
                Pointer->Show();
            
            std::cout << "\t";
        }
        std::cout << "\n";
    }
}

/*
void Menu::Show(Pointer* Pointer)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    std::cout << "|  ";
    for(int i = 0; i < 3; ++i)
    {
        SetConsoleTextAttribute(console, 3);
        std::cout << MenuStrings.at(i);
        SetConsoleTextAttribute(console, 7);

        if(Pointer->GetMode() == MENU && Pointer->GetX() == i)
        {
            Pointer->Show();
            std::cout << " |  ";
        }
        else std::cout << "  |  ";
    }
} */

/*
void Menu::ShowProperties(Pointer* Pointer)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i = 0; i < Properties.size(); ++i)
    {
        SetConsoleTextAttribute(console, 3);
        std::cout << PropertyStrings.at(i);
        SetConsoleTextAttribute(console, 7);
        std::cout << ": " << Properties[PropertyNames(i)];

        if(Pointer->GetMode() == PROPERTIES && Pointer->GetY() == i)
            Pointer->Show();

        std::cout << "\n";
    }

    SetConsoleTextAttribute(console, 3);
    std::cout << "ESC";
    SetConsoleTextAttribute(console, 7);
    if(Pointer->GetMode() == PROPERTIES && Pointer->GetY() == Properties.size())
        Pointer->Show();
} */

void Game::Show()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    Board.Show(_Pointer);
}
