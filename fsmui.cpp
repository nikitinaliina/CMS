#include "fsmui.h"
#include <iostream>
#include <string>

void FSMUI::Update()
{
    while (true)
    {
        switch (currentState)
        {
            case FSMState::MainMenu:
                MainMenuUpdate();
                break;

            case FSMState::AddContact:
                AddContactUpdate();
                break;

            case FSMState::FindContact:
                FindContactUpdate();
                break;

            case FSMState::EditContact:
                EditContactUpdate();
                break;

            case FSMState::DisplayAll:
                DisplayAllUpdate();
                break;

            case FSMState::DeleteContact:
                DeleteContactUpdate();
                break;

            case FSMState::Exit:
                return; // The hammer!
        }
    }
}


void FSMUI::MainMenuUpdate()
{
    // Display the menu options
    std::cout << "Phonebook Menu" << std::endl;
    std::cout << "1. Add Contact" << std::endl;
    std::cout << "2. Find Contact" << std::endl;
    std::cout << "3. Edit Contact" << std::endl;
    std::cout << "4. Display All Contacts" << std::endl;
    std::cout << "5. Delete Contact" << std::endl;
    std::cout << "6. Exit" << std::endl;

    // Read the input
    int choice;
    std::cout << "Choose the command from the menu" << std::endl;
    std::cin >> choice;

    // react to the input
    switch (choice)
    {
        case 1: currentState = FSMState::AddContact; break;
        case 2: currentState = FSMState::FindContact; break;
        case 3: currentState = FSMState::EditContact; break;
        case 4: currentState = FSMState::DisplayAll; break;
        case 5: currentState = FSMState::DeleteContact; break;
        case 6: currentState = FSMState::Exit; break;
        default:
            // Do nothing!
            ;
    }
}


void FSMUI::AddContactUpdate()
{
    std::cout << __func__;
    int dummy;
    std::cin >> dummy;
    currentState = FSMState::MainMenu;
}
void FSMUI::FindContactUpdate()
{
    std::cout << __func__;
    int dummy;
    std::cin >> dummy;
    currentState = FSMState::MainMenu;
}
void FSMUI::EditContactUpdate()
{
    std::cout << __func__;
    int dummy;
    std::cin >> dummy;
    currentState = FSMState::MainMenu;
}
void FSMUI::DisplayAllUpdate()
{
    std::cout << __func__;
    int dummy;
    std::cin >> dummy;
    currentState = FSMState::MainMenu;
}
void FSMUI::DeleteContactUpdate()
{
    std::cout << __func__;
    int dummy;
    std::cin >> dummy;
    currentState = FSMState::MainMenu;
}