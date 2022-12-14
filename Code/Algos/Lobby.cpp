#include <Lobby.hpp>


void Lobby::Open()
{
    ExitCode code = GAME;
    while(code != QUIT)
    {
        if(code == GAME)
        {
            Pointer.OpenGame();
            do code = _Game->Move();
            while (code == GAME);
        }
        if(code == MENU)
        {
            Pointer.OpenMenu();
            do code = Menu.Move();
            while (code == MENU);
        }
        if(code == NEW)
        {
            delete _Game;
            _Game = new Game(&Menu, &Pointer);
            code = GAME;
        }
    }
}