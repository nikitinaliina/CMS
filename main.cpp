#include <iostream>
#include <string>
#include <vector>
#include "contact.h"
#include "userinterface.h"
#include "phonebook.h"

int main()
{
   UserInterface::displayMenu();
   int choice = UserInterface::MenuChoice();
   UserInterface::handleMenuChoice(choice);

}