#include <Menu.hpp>
#include <fstream>

Menu::Menu(Pointer* poi, std::string db_file) : DBFile(db_file), _Pointer(poi)
{
    Json::Reader reader;
    std::ifstream data(db_file);
    reader.parse(data, Options);
    Properties = Options["Properties"];
}

void Menu::SetProperty()
{
    if(_Pointer->GetY() > Properties.size() - 1)
        throw "Out of Menu's range.\n";

    char value;
    std::cout << "Type in the new value (Enter to confirm): ";
    std::cin >> value;

    Properties[_Pointer->GetY()] = value;
}
