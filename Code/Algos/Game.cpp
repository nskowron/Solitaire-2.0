#include <Game.hpp>
#include <iostream>
#include <conio.h>


Game::Game(Menu* men, Pointer* poi) : _Menu(men), _Pointer(poi)
{
    _Pointer->_Menu = _Menu;
    _Pointer->_Board = &Board;
}

ExitCode Game::Move()
{
    Show();

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
    return GAME;
}
