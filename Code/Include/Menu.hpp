#pragma once

#include <Pointer.hpp>
#include <map>
#include <vector>
#include <string>
#include <json/json.h>
#include <Lobby.hpp>


class Pointer;
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
    void SetProperty();

    const Json::Value& GetOptions() { return Options; }
    const Json::Value& GetProperties() { return Properties; }

    // defined in UI.cpp
    void Show();
    void ShowProperties();
};