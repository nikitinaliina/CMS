#pragma once 
#include <stdint.h>

class FSMUI
{
public:
    void Update();
    static FSMUI& instance ()
    {
        static FSMUI* myInstance = new FSMUI();
        return *myInstance;
    }

private:
    enum class FSMState
    {
        MainMenu,
        AddContact,
        FindContact,
        EditContact,
        EditContactName,
        EditContactSurname,
        EditContactNumber,
        DisplayAll,
        DeleteContact,
        Exit
    };

    FSMState currentState = FSMState::MainMenu;

    void MainMenuUpdate();
    void AddContactUpdate();
    void FindContactUpdate();
    void EditContactUpdate();
    void EditContactUpdateName();
    void EditContactUpdateSurname();
    void EditContactUpdateNumber();
    void DisplayAllUpdate();
    void DeleteContactUpdate();   
};