#include <Menu.hpp>

Menu::Menu()
{
    Properties[POINTER_COLOR] = 5;
    Properties[KEY_DOWN] = 's';
    Properties[KEY_UP] = 'w';
    Properties[KEY_LEFT] = 'a';
    Properties[KEY_RIGHT] = 'd';
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
