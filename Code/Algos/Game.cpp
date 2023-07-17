#include <Game.hpp>

#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>


Game::Game(Menu* men, Pointer* poi) : _Menu(men), _Pointer(poi), Finish(false)
{
    _Pointer->_Menu = _Menu;
    _Pointer->_Board = &Board;
}

ExitCode Game::Move()
{
    Show();

    if(Board.Stacks[0].Size() == KING &&
        Board.Stacks[1].Size() == KING &&
        Board.Stacks[2].Size() == KING &&
        Board.Stacks[3].Size() == KING)
    {
        return GAME_END;
    }

    char input = getch();
    if(input == _Menu->GetProperties()["Open Menu"].asInt())        return MENU;
    else if(input == _Menu->GetProperties()["Key Down"].asInt())    _Pointer->MvDown();
    else if(input == _Menu->GetProperties()["Key Up"].asInt())      _Pointer->MvUp();
    else if(input == _Menu->GetProperties()["Key Left"].asInt())    _Pointer->MvLeft();
    else if(input == _Menu->GetProperties()["Key Right"].asInt())   _Pointer->MvRight();
    else if(input == _Menu->GetProperties()["Alter Mode"].asInt())  _Pointer->AlterGameMode();
    else if(input == _Menu->GetProperties()["Drop Cards"].asInt())
    {
        if(Board.Clip.Empty() == false)
        {
            Board.Unpick(Board.Clip.Origin);
            Board.Clip.Clear();
        }
    }
    else if(input == _Menu->GetProperties()["Interact"].asInt())
    {
        try
        {
            if(Board.Clip.Empty())
            {
                if(_Pointer->GetMode() == HAND && _Pointer->GetX() == 0)
                    Board.FlipHand();
                else
                    Board.PickUp(_Pointer);
            }
            else
            {
                if(_Pointer->GetMode() == HAND && _Pointer->GetX() == 0)
                {
                    Board.Unpick(Board.Clip.Origin);
                    Board.FlipHand();
                    Board.Clip.Clear();
                }
                else
                {
                    Board.PutDown(_Pointer);
                    Board.Unpick(_Pointer);
                    Board.RemoveClip();
                    Board.Clip.Clear();

                    Finish = Board.AllUncovered();
                }
            }
        }
        catch(const char* e)
        {
            if(Board.Clip.Empty() == false)
            {
                Board.Unpick(Board.Clip.Origin);
                Board.Clip.Clear();
            }
        }
    }
    else if(input == _Menu->GetProperties()["Finish"].asInt())
    {
        if(Finish == true)
            AutoFinish();
    }
    return GAME;
}

void Game::AutoFinish()
{
    Finish = false;
    Board.Clip.Clear();

    while(Board.Stacks[0].Size() != KING ||
        Board.Stacks[1].Size() != KING ||
        Board.Stacks[2].Size() != KING ||
        Board.Stacks[3].Size() != KING)
    {
        for(unsigned int col = 0; col < 7; ++col)
        {
            _Pointer->OpenGame();
            for(unsigned int moves = 0; moves < col; ++moves)
                _Pointer->MvRight();
            _Pointer->MvUp();

            try
            {
                Board.PickUp(_Pointer);
                Board.Unpick(_Pointer);
                _Pointer->AlterGameMode();
                for(unsigned int sta = 0; sta < 4; ++sta)
                {
                    try
                    {
                        Board.PutDown(_Pointer);
                        Board.RemoveClip();
                        Board.Clip.Clear();

                        _Pointer->OpenGame();
                        Show();
                        std::this_thread::sleep_for(std::chrono::milliseconds(600));
                        break;
                    }
                    catch(const char* e) 
                    { _Pointer->MvRight(); }
                }
            }
            catch(const char* e)
            {
                if(Board.Clip.Empty() == false)
                    Board.Clip.Clear();
            }
        }
    }

    _Pointer->OpenGame();
    Move();
}
