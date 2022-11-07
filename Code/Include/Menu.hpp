#pragma once

#include <Pointer.hpp>
#include <map>
#include <vector>
#include <string>

class Pointer;


enum MenuOptions { NEW_GAME = 0, QUIT, OPTIONS };
enum PropertyNames { POINTER_COLOR = 0, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, ALTER_MODE, INTERACT, ABORT };

class Menu
{
private:
    // probably gonna want to play with some json with this
    std::map<PropertyNames, char> Properties;
    std::vector<std::string> MenuStrings;
    std::vector<std::string> PropertyStrings;

public:
    std::map<PropertyNames, char>& GetProperties() { return Properties; }

    // defined in Menu.cpp
    Menu();
    void SetProperty(PropertyNames, char);

    // defined in UI.cpp
    void Show(Pointer*);
    void ShowProperties(Pointer*);
};