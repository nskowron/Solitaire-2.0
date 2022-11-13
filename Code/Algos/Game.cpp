#include <Game.hpp>
#include <iostream>
#include <conio.h>


Game::Game(Menu* men, Pointer* poi) : _Menu(men), _Pointer(poi)
{
    Board.Clip.Origin = &ClipHolder;
    _Pointer->_Menu = _Menu;
    _Pointer->_Board = &Board;
}

int Game::Play()
{
    //Board.Clip.Origin = new Pointer(&menu, &board, PROPERTIES);
    char input = getch();
    if(input == _Menu->GetProperties()[MENU])               return 1;
    else if(input == _Menu->GetProperties()[KEY_DOWN])      _Pointer->MvDown();
    else if(input == _Menu->GetProperties()[KEY_UP])        _Pointer->MvUp();
    else if(input == _Menu->GetProperties()[KEY_LEFT])      _Pointer->MvLeft();
    else if(input == _Menu->GetProperties()[KEY_RIGHT])     _Pointer->MvRight();
    else if(input == _Menu->GetProperties()[ALTER_MODE])    _Pointer->AlterMode();
    else if(input == _Menu->GetProperties()[ABORT])
    {
        if(Board.Clip.Empty() == false)
        {
            Board.Unpick(Board.Clip.Origin);
            Board.Clip.Clear();
        }
    }
    else if(input == _Menu->GetProperties()[INTERACT])
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
    return 0;
}
