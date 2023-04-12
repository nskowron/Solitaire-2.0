#include <Menu.hpp>
#include <fstream>
#include <conio.h>
#include <filesystem>

Menu::Menu(Pointer* poi, std::string db_file) : DBFile(db_file), _Pointer(poi)
{
    std::filesystem::path filepath(db_file);
    if(std::filesystem::exists(filepath) == false)
    {
        Json::Value new_options;
        new_options["New Game"] = Json::nullValue;
        new_options["Exit"] = Json::nullValue;
        new_options["Return"] = Json::nullValue;
        Json::Value new_properties;
        new_properties["Pointer Color"] = 5;
        new_properties["Key Up"] = 119;
        new_properties["Key Down"] = 115;
        new_properties["Key Left"] = 97;
        new_properties["Key Right"] = 100;
        new_properties["Interact"] = 101;
        new_properties["Alter Mode"] = 113;
        new_properties["Drop Cards"] = 120;
        new_properties["Open Menu"] = 109;
        new_options["Properties"] = new_properties;

        std::ofstream new_data(db_file);
        new_data << new_options;
        new_data.close();
    }

    Json::Reader reader;
    std::ifstream data(db_file);
    reader.parse(data, Options);
    Properties = Options["Properties"];
    data.close();
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
    std::cout << "\n\nType in the new value (Enter to confirm): ";
    std::cin >> value;

    Properties[Properties.getMemberNames()[_Pointer->GetY()]] = (int)value;
}
