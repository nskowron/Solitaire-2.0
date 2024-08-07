#pragma once

#include <LobbyExitCodes.hpp>
#include <Pointer.hpp>
//#include <Button.hpp>

#include <map>
#include <vector>
#include <string>
#include <json/json.h>

class Pointer;
//class Button;
class Menu
{
private:
    std::string DBFile;
    Json::Value Options;
    Json::Value Properties;
    Pointer* _Pointer;

public:
    // defined in Menu.cpp
    Menu(Pointer*, std::string);
    ExitCode Move();
    ExitCode MoveProperties();
    void SetProperty();

    const Json::Value& GetOptions() { return Options; }
    const Json::Value& GetProperties() { return Properties; }

    // defined in UI.cpp
    void Show();
    void ShowProperties();
};