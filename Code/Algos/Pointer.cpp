#include <Pointer.hpp>

Pointer::Pointer(Menu* men, Board* boa, PointerMode mod)
    : _Board(boa), _Menu(men), X(0), Y(0), Mode(mod)
{
    Color = (unsigned int)_Menu->GetProperties()[POINTER_COLOR];
}

void Pointer::AlterMode()
{
    Mode = PointerMode(Mode % 3 + 1);
    if(Mode == HAND && _Board->Hand.Size() == 0)
        Mode = PointerMode(Mode + 1);
    
    X = Y = 0;
}

void Pointer::MvUp()
{
    if(Mode == COLUMN)
        Y = (Y + _Board->Columns[X].Size() - 1) % _Board->Columns[X].Size();
    else if(Mode == PROPERTIES)
        Y = (Y + _Menu->GetProperties().size()) % (_Menu->GetProperties().size() + 1);
}

void Pointer::MvDown()
{
    if(Mode == COLUMN)
        Y = (Y + 1) % _Board->Columns[X].Size();
    else if(Mode == PROPERTIES)
        Y = (Y + 1) % (_Menu->GetProperties().size() + 1);
}

void Pointer::MvLeft()
{
    switch(Mode)
    {
        case STACK:     X = (X + 3) % 4; break;
        case HAND:      if(_Board->CurrentCard >= 0) X = (X + 1) % 2; break;
        case COLUMN:    X = (X + 6) % 7; 
                        if(_Board->Columns[X].Size() == 0)
                            Y = 0;
                        else if(Y >= _Board->Columns[X].Size())
                            Y = _Board->Columns[X].Size() - 1;
                        break;
        //case MENU:      X = (X + 2) % 3; break;
    }
}

void Pointer::MvRight()
{
    switch(Mode)
    {
        case STACK:     X = (X + 1) % 4; break;
        case HAND:      if(_Board->CurrentCard >= 0) X = (X + 1) % 2; break;
        case COLUMN:    X = (X + 1) % 7; 
                        if(_Board->Columns[X].Size() == 0)
                            Y = 0;
                        else if(Y >= _Board->Columns[X].Size())
                            Y = _Board->Columns[X].Size() - 1;
                        break;
        //case MENU:      X = (X + 1) % 3; break;
    }
}
