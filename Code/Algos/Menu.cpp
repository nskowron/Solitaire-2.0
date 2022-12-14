#include <Menu.hpp>
#include <fstream>
#include <conio.h>

Menu::Menu(Pointer* poi, std::string db_file) : DBFile(db_file), _Pointer(poi)
{
    Json::Reader reader;
    std::ifstream data(db_file);
    reader.parse(data, Options);
    Properties = Options["Properties"];
}

ExitCode Menu::Move()
{
    if(_Pointer->GetMode() == PROPERTIES)
        return MoveProperties();

    Show();
    
    char input = getch();
    if(input == Properties["Key Right"].asInt())       _Pointer->MvRight();
    else if(input == Properties["Key Left"].asInt())   _Pointer->MvLeft();
    else if(input == Properties["Interact"].asInt())
    {
        if(Options.getMemberNames()[_Pointer->GetX()] == "New Game")        return NEW;
        else if(Options.getMemberNames()[_Pointer->GetX()] == "Exit")       return QUIT;
        else if(Options.getMemberNames()[_Pointer->GetX()] == "Return")     return GAME;
        else if(Options.getMemberNames()[_Pointer->GetX()] == "Properties") _Pointer->OpenProperties();
    }
    return MENU;
}

ExitCode Menu::MoveProperties()
{
    ShowProperties();

    char input = getch();
    if(input == Properties["Key Down"].asInt())         _Pointer->MvDown();
    else if(input == Properties["Key Up"].asInt())      _Pointer->MvUp();
    else if(input == Properties["Interact"].asInt())
    {
        if(_Pointer->GetY() == Properties.size())
            _Pointer->OpenMenu();

        else
            SetProperty();
    }
    return MENU;
}

void Menu::SetProperty()
{
    if(_Pointer->GetY() > Properties.size() - 1)
        throw "Out of Menu's range.\n";

    char value;
    std::cout << "Type in the new value (Enter to confirm): ";
    std::cin >> value;

    Properties[Properties.getMemberNames()[_Pointer->GetY()]] = (int)value;
}
