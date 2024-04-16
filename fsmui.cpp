#include "fsmui.h"
#include <iostream>
#include <string>
#include "contact.h"
#include "phonebook.h"


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

            case FSMState::EditContactName:
                EditContactUpdateName();
                //or EditContactNameUpdate();
                break;

            case FSMState::EditContactSurname:
                EditContactUpdateSurname();
                break;

            case FSMState::EditContactNumber:
                EditContactUpdateNumber();
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

    // React to the input
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
    std::string name, surname, number;
    std::cout << "Enter Name" << std::endl;
    std::cin >> name;
    std::cout << "Enter Surname" << std::endl;
    std::cin >> surname;
    std::cout << "Enter Number" << std::endl;
    std::cin >> number;
    Contact myContact {name, surname, number};
    Phonebook::instance().addContact(myContact);
    currentState = FSMState::MainMenu;
}
void FSMUI::FindContactUpdate()
{
    std::string name, surname;
    std::cout << "Enter a name" << std::endl;
    std::cin >> name;
    std::cout << "Enter a surname" << std::endl;
    std::cin >>surname;
    //Not sure if I need this
    //Contact myContact {name, surname};
    Contact myContact = Phonebook::instance().findContact(name, surname);
    std::cout << myContact << std::endl;
    currentState = FSMState::MainMenu;
}
void FSMUI::EditContactUpdate()
{
    int select;
    std::cout << "Choose update: " << std::endl;
    std::cout << "1. Update Name" << std::endl;
    std::cout << "2. Update Surname" << std::endl;
    std::cout << "3. Update Number" << std::endl;
    std::cin >> select;

    switch(select)
    {
        case 1: currentState = FSMState::EditContactName; break;
        case 2: currentState = FSMState::EditContactSurname; break;
        case 3: currentState = FSMState::EditContactNumber; break;
	    default:
        ; 
	}
}

void FSMUI::EditContactUpdateName()
{
//find contact and return a contact
    std::string name, surname;
    std::cout << "Enter a name" << std::endl;
    std::cin >> name;
    std::cout << "Enter a surname" << std::endl;
    std::cin >>surname;
    Contact newData = Phonebook::instance().findContact(name, surname);
    //insert new name 
    //return new contact = new data
    std::string new_name;
    std::cout << "Insert new name" << std::endl;
    std::cin >> new_name;
    newData.setName(new_name);
    Phonebook::instance().editContact(name, surname, newData);
    std::cout << newData << std::endl;
    currentState = FSMState::MainMenu;
}

void FSMUI::EditContactUpdateSurname()
{
    std::string name, surname;
    std::cout << "Enter a name" << std::endl;
    std::cin >> name;
    std::cout << "Enter a surname" << std::endl;
    std::cin >>surname;
    Contact newData = Phonebook::instance().findContact(name, surname);
    std::string new_surname;
    std::cout << "Insert new surname" << std::endl;
    std::cin >> new_surname;
    newData.setSurname(new_surname);
    Phonebook::instance().editContact(name, surname, newData);
    std::cout << newData << std::endl;
    currentState = FSMState::MainMenu;
}

void FSMUI::EditContactUpdateNumber()
{
    std::string name, surname;
    std::cout << "Enter a name" << std::endl;
    std::cin >> name;
    std::cout << "Enter a surname" << std::endl;
    std::cin >>surname;
    Contact newData = Phonebook::instance().findContact(name, surname);
    std::string new_number;
    std::cout << "Insert new number" << std::endl;
    std::cin >> new_number;
    newData.setNumber(new_number);
    Phonebook::instance().editContact(name, surname, newData);
    std::cout << newData << std::endl;
    currentState = FSMState::MainMenu;
}

void FSMUI::DisplayAllUpdate()
{
    Phonebook::instance().getAll();
    currentState = FSMState::MainMenu;
}

void FSMUI::DeleteContactUpdate()
{
    std::string name, surname;
    std::cout << "Enter a name" << std::endl;
    std::cin >> name;
    std::cout << "Enter a surname" << std::endl;
    std::cin >>surname;
    Phonebook::instance().deleteContact(name, surname);
    currentState = FSMState::MainMenu;
}