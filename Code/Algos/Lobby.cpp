#include <Lobby.hpp>


void Lobby::Open()
{
    ExitCode code = GAME;
    while(code != QUIT)
    {
        while(code == GAME)
            code = _Game.Move();
        while(code == MENU)
            code = Menu.Move();
        if(code == NEW)
        {
            _Game = Game(&Menu, &Pointer);
        }
    }
}