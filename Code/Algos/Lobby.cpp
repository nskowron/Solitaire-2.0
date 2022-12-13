#include <Lobby.hpp>

Lobby::Lobby() : Pointer(), Menu(&Pointer, "Properties.json"), Game(&Menu, &Pointer)
{
    ExitCode code = GAME;
    while(code != QUIT)
    {
        while(code == GAME)
            code = Game.Move();
    }
}