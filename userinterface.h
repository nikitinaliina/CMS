#include <iostream>
#include <string>
#include "contact.h"
#pragma once

class UserInterface
{
    public:
    static Contact returnContact();
    static Contact returnNameSurname();
    static int editContactMenu();
    static void editContact(int select, Contact myContact);
    static void displayMenu();
    static int MenuChoice();
    static void handleMenuChoice(int choice);

};  



