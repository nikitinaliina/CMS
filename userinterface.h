#pragma once

#include <iostream>
#include <string>
#include "contact.h"

class UserInterface
{
public:
    Contact returnContact();
    Contact returnNameSurname();
    int editContactMenu();
    void editContact(int select, Contact myContact);
    void displayMenu();
    int MenuChoice();
    void handleMenuChoice(int choice);

    static UserInterface& instance()
    {
        static UserInterface * myInstance = new UserInterface();
        return *myInstance;
    }

};  



