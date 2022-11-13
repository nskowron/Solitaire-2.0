#include <Lobby.hpp>

Lobby::Lobby() : Pointer(), Menu(), Game(&Menu, &Pointer)
{
    int exitCode = 0;
    while(exitCode != 1)
    {
        Game.Show();
        exitCode = Game.Play();
    }
}