#include <Menu.hpp>

Menu::Menu()
{
    Properties[POINTER_COLOR] = 5;
    Properties[KEY_DOWN] = 's';
    Properties[KEY_UP] = 'w';
    Properties[KEY_LEFT] = 'a';
    Properties[KEY_RIGHT] = 'd';
    Properties[ALTER_MODE] = 'q';
    Properties[INTERACT] = 'e';
    Properties[ABORT] = 'x';

    MenuStrings = { "New Game", "Quit", "Options" };
    PropertyStrings = { "Pointer color", "Key down", "Key up", "Key left", "Key right", "Alter mode", "Interact", "Abort" };
}

void Menu::SetProperty(PropertyNames name, char value)
{
    if(name == POINTER_COLOR)
    {
        if(value > 0 && value < 16)
        {
            Properties[name] = value;
            return;
        }
        throw "Wrong color value.\n";
    }

    if((value >= 'a' && value <= 'z') || (value >= 'A' && value <= 'Z'))
    {
        Properties[name] = value;
        return;
    }
    throw "You can only use letters for now. Sorry for my unprofesionalism.\n";
}
