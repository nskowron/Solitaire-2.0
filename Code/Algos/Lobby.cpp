#include <Lobby.hpp>
#include <Button.hpp>

void Lobby::Open()
{
    ExitCode code = GAME;
    Button button("", {}, &Menu, &Pointer);
    while(code != QUIT)
    {
        if(code == GAME)
        {
            Pointer.OpenGame();
            do code = _Game->Move();
            while (code == GAME);

            if(code == GAME_END)
            {
                button = Button("Congratulations! Do you wish to start a new game?", {{"Yes", NEW}, {"No", QUIT}}, &Menu, &Pointer);
                Pointer.OpenButton(&button);
                do code = button.Move();
                while (code == BUTTON);
            }
        }
        if(code == MENU)
        {
            Pointer.OpenMenu();
            do code = Menu.Move();
            while (code == MENU);

            if(code == NEW)
            {
                button = Button("Are you sure you want to start a new game?", {{"Yes", NEW}, {"No", MENU}}, &Menu, &Pointer);
                Pointer.OpenButton(&button);
                do code = button.Move();
                while (code == BUTTON);
            }
            if(code == QUIT)
            {
                button = Button("Are you sure you want to quit?", {{"Yes", QUIT}, {"No", MENU}}, &Menu, &Pointer);
                Pointer.OpenButton(&button);
                do code = button.Move();
                while (code == BUTTON);
            }
        }
        if(code == NEW)
        {
            delete _Game;
            _Game = new Game(&Menu, &Pointer);
            code = GAME;
        }
    }
}