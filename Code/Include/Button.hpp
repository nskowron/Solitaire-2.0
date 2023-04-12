#pragma once

#include <iostream>
#include <Pointer.hpp>
#include <Menu.hpp>
#include <map>
#include <LobbyExitCodes.hpp>

class Pointer;
class Menu;
class Button
{
private:
    std::string Message;
    std::map< std::string, ExitCode > Options;
    Menu* _Menu;
    Pointer* _Pointer;

public:
    Button(std::string, std::map< std::string, ExitCode >, Menu*, Pointer*);

    ExitCode Move();
    const std::map< std::string, ExitCode >& GetOptions() { return Options; }

    void Show();
};