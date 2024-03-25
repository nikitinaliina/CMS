#include "userinterface.h"
#include "contact.h"
#include "phonebook.h"

Contact UserInterface::returnContact()
    {

        std::string name, surname, number;
        std::cout << "Enter Name" << std::endl;
        std::cin >> name;
        std::cout << "Enter Surname" << std::endl;
        std::cin >> surname;
        std::cout << "Enter Number" << std::endl;
        std::cin >> number;
        Contact myContact {name, surname, number};
        return myContact;    
    }

Contact UserInterface::returnNameSurname()
    {
        std::string name, surname;
        std::cout << "Enter a name" << std::endl;
        std::cin >> name;
        std::cout << "Enter a surname" << std::endl;
        std::cin >>surname;
        Contact myContact {name, surname};
        return myContact;
    }

int UserInterface::editContactMenu()
    {
        int select;
        std::cout << "Choose update: " << std::endl;
        std::cout << "1. Update Name" << std::endl;
        std::cout << "2. Update Surname" << std::endl;
        std::cout << "3. Update Number" << std::endl;
        std::cin >> select;
        return select;
    }

void UserInterface::editContact(int select, Contact myContact)
    {
        //TODO create enum and in case statements substitute "1" with "Update_Name" etc.
        //enum updates {updateName, updateSurname, updateNumber};
        //int update;

        switch(select)
        {
            case 1:
            // 1.Update Name
                {
                    std::string new_name;
                    std::cout << "Insert new name" << std::endl;
                    std::cin >> new_name;
                    myContact.setName(new_name);
                    break;
                }
            case 2:
            //2.Update Surname
                {
                    std::string new_surname;
                    std::cout << "Insert new surname" << std::endl;
                    std::cin >> new_surname;
                    myContact.setSurname(new_surname);
                    break;
                }
            case 3:
            //3.Update Number
                {
                    std::string new_number;
                    std::cout << "Insert new number" << std::endl;
                    std::cin >> new_number;
                    myContact.setNumber(new_number);
                    break;
                }

        }
    }

void UserInterface::displayMenu()
    {
        
        std::cout << "Phonebook Menu" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Find Contact" << std::endl;
        std::cout << "3. Edit Contact" << std::endl;
        std::cout << "4. Display All Contacts" << std::endl;
        std::cout << "5. Delete Contact" << std::endl;
        std::cout << "6. Exit" << std::endl;
    }

int UserInterface::MenuChoice()
    {
        int choice;
        std::cout << "Choose the command from the menu" << std::endl;
        std::cin >> choice;
        return choice;
    }

void UserInterface::handleMenuChoice(int choice)
    {
        bool done {false};
        {
            //In order to call a method from a class it is neccessary to create a class object
            Phonebook phonebook;
            switch(choice)
            {
            case 1:
            //1. Add Contact
                {
                    phonebook.addContact();
                    break;
                }
            case 2:
            //Find Contact
                {
                    phonebook.findContact();    
                    break;
                }
            case 3:
            //Edit Contact
                {
                    phonebook.editContact();
                    break;
                }
            case 4:
            //Display All Contacts
                {
                    phonebook.displayAll();
                    break;
                }
            case 5:
            //Delete Contact
                {
                    phonebook.deleteContact();
                    break;
                }
            case 6:
            //Exit
                {
                    done = true;
                }
            default:
            std::cout << "Invalid choice. Try again!" << std::endl;
            }
        }
        

    }

