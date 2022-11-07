#include <Game.hpp>
#include <iostream>
#include <conio.h>


void Game::Play()
{
    while(true)
    {
        Show();
        char input = getch();
        if(input == menu.GetProperties()[KEY_DOWN])         pointer.MvDown();
        else if(input == menu.GetProperties()[KEY_UP])      pointer.MvUp();
        else if(input == menu.GetProperties()[KEY_LEFT])    pointer.MvLeft();
        else if(input == menu.GetProperties()[KEY_RIGHT])   pointer.MvRight();
        else if(input == menu.GetProperties()[ALTER_MODE])  pointer.AlterMode();
        else if(input == menu.GetProperties()[ABORT])       board.Clip.Clear();
        else if(input == menu.GetProperties()[INTERACT])
        {
            if(pointer.GetMode() == HAND && pointer.GetX() == 0)
            {
                board.Clip.Clear();

                if(board.CurrentCard + 1 == board.Hand.Size())
                    board.CurrentCard = -1;
                else
                {
                    board.CurrentCard++;
                    board.Hand[board.CurrentCard].Front = true;
                }
                board.Hand[board.CurrentCard + 1].Front = false;

                continue;
            }
            if(board.Clip.Empty())
            {
                // take stuff
                try
                {
                    board.Clip.origin.mode = pointer.GetMode();
                    board.Clip.origin.X = pointer.GetX();

                    if(pointer.GetMode() == HAND)
                    {
                        board.Clip.data.real_card = board.Hand[board.CurrentCard];
                        board.Clip.data.card = &board.Clip.data.real_card;
                    }

                    else if(pointer.GetMode() == COLUMN)
                    {
                        board.Clip.data.real_col = board.Columns[pointer.GetX()].PickUp(board.Columns[pointer.GetX()].Size() - pointer.GetY());
                        board.Clip.data.column = &board.Clip.data.real_col;
                    }

                    else if(pointer.GetMode() == STACK)
                    {
                        board.Clip.data.real_card = board.Stacks[pointer.GetX()].Top();
                        board.Clip.data.card = &board.Clip.data.real_card;
                    }
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                    board.Clip.Clear();
                }
            }
            else
            {
                // give stuff
                try
                {
                    if(pointer.GetMode() == HAND)
                        throw "Can't put cards here.\n";

                    else if(pointer.GetMode() == COLUMN)
                    {
                        if(board.Clip.data.card == nullptr)
                            board.Columns[pointer.GetX()].Add(*board.Clip.data.column);
                        else
                            board.Columns[pointer.GetX()].Add(*board.Clip.data.card);
                    }
                    else if(pointer.GetMode() == STACK)
                    {
                        if(board.Clip.data.card == nullptr)
                            throw "Can put only 1 card on a stack.\n";
                        else
                            board.Stacks[pointer.GetX()].Add(*board.Clip.data.card);
                    }

                    board.RemoveClip();
                    board.Clip.Clear();
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
    }
}
