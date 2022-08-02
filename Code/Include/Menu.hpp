#pragma once

#include <Pointer.hpp>
#include <map>

class Pointer;

enum PropertyNames { POINTER_COLOR = 0, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class Menu
{
private:
    std::map<PropertyNames, char> Properties;

public:
    std::map<PropertyNames, char>& GetProperties() { return Properties; }

    // defined in Menu.cpp
    Menu();
    void SetProperty(PropertyNames, char);

    // defined in UI.cpp
    void Show(Pointer*);
};