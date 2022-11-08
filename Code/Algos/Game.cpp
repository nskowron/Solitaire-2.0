#include <Game.hpp>
#include <iostream>
#include <conio.h>


void Game::Play()
{
    char input;
    while(  board.Stacks[0].Size() != 13 ||
            board.Stacks[1].Size() != 13 ||
            board.Stacks[2].Size() != 13 ||
            board.Stacks[3].Size() != 13 )
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        Show();
        input = getch();
        if(input == menu.GetProperties()[KEY_DOWN])         pointer.MvDown();
        else if(input == menu.GetProperties()[KEY_UP])      pointer.MvUp();
        else if(input == menu.GetProperties()[KEY_LEFT])    pointer.MvLeft();
        else if(input == menu.GetProperties()[KEY_RIGHT])   pointer.MvRight();
        else if(input == menu.GetProperties()[ALTER_MODE])  pointer.AlterMode();
        else if(input == menu.GetProperties()[ABORT])       board.Clip.Clear();
        else if(input == menu.GetProperties()[INTERACT])
        {
            try
            {
                if(pointer.GetMode() == HAND && pointer.GetX() == 0)
                {
                    board.Clip.Clear();
                    board.FlipHand();
                }
                else if(board.Clip.Empty())
                    board.AddToClip(&pointer);
    
                else
                {
                    board.PutBackClip(&pointer);
                    board.RemoveClip();
                    board.Clip.Clear();
                }
            }
            catch(const char* e)
            {
                std::cerr << e << '\n';
                board.Clip.Clear();
            }
        }
    }
}
