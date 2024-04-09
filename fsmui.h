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
        DisplayAll,
        DeleteContact,
        Exit
    };

    FSMState currentState = FSMState::MainMenu;

    void MainMenuUpdate();
    void AddContactUpdate();
    void FindContactUpdate();
    void EditContactUpdate();
    void DisplayAllUpdate();
    void DeleteContactUpdate();
};