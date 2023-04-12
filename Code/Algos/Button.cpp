#include <Button.hpp>
#include <LobbyExitCodes.hpp>
#include <Pointer.hpp>

#include <conio.h>

Button::Button(std::string message, std::map< std::string, ExitCode > options, Menu* menu, Pointer* pointer) 
    : Message(message), Options(options), _Menu(menu), _Pointer(pointer) {}

ExitCode Button::Move()
{
    Show();

    char input = getch();
    if(input == _Menu->GetProperties()["Key Left"].asInt())         _Pointer->MvLeft();
    else if(input == _Menu->GetProperties()["Key Right"].asInt())   _Pointer->MvRight();
    else if(input == _Menu->GetProperties()["Interact"].asInt())
    {
        auto it = Options.begin();
        for(unsigned int i = 0; i < _Pointer->GetX(); ++i)
            it++;

        return it->second;
    }

    return BUTTON;
}