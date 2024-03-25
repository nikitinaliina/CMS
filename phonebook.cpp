#include "contact.h"
#include "phonebook.h"
#include "userinterface.h"

void Phonebook::addContact()
    //
    {
        Contact myContact = UserInterface::returnContact();
        m_phonebook.push_back(myContact);
        std::cout << "Contact added succesfully!" << std::endl;
    }

void Phonebook::findContact()

{
    Contact myContact = UserInterface::returnNameSurname();
    std::string name = myContact.getName();
    std::string surname = myContact.getSurname();
    //I think there is a better way to rewrite this part above
    bool isFound {false};
    for (const auto& contact : m_phonebook)
        {
            if (contact.getName() == name && contact.getSurname() == surname)
                {
                    isFound = true;
                    Phonebook::displayContact(contact);
                    break;
                }
        }
        
            if (isFound == false)
                {
                    std::cout << "No contact found !" << std::endl;
                }   
                
}

void Phonebook::displayAll()
{
    for (auto& contact : m_phonebook)
        {
            Phonebook::displayContact(contact);
        }
}

void Phonebook::displayContact(Contact myContact) const
    {
        std::cout << "Contact: " << myContact.getName() << ' ' << myContact.getSurname() << std::endl;
        std::cout << "Phonenumber: " << myContact.getNumber() << std::endl;
    }



void Phonebook::deleteContact()
    {
        Contact myContact = UserInterface::returnNameSurname();
        std::string name = myContact.getName();
        std::string surname = myContact.getSurname();
        bool isFound {false};
        for (auto& contact : m_phonebook)
                    
            {
                if (contact.getName() == name && contact.getSurname() == surname) 
                    {
                        isFound = true;
                        std::vector<Contact>::iterator i;
                        *i = contact;
                        m_phonebook.erase(i);
                        if (isFound == false)
                        {
                            std::cout << "No contact found !" << std::endl;
                        }   
                    }    
            }                    
    }
            
void Phonebook::editContact()
    {
        Contact myContact = UserInterface::returnNameSurname();
        std::string name = myContact.getName();
        std::string surname = myContact.getSurname();
        bool isFound {false};
        for (auto& contact : m_phonebook)
        //Probably this for-loop with if-statement will also be wrapped into a function
        {            
            if (contact.getName() == name && contact.getSurname() == surname)
            {
                isFound = true;            
            }
            int select = UserInterface::editContactMenu();
            UserInterface::editContact(select, myContact);

            if (isFound == false)
            {
                std::cout << "No contact found" << std::endl;
            }
        }
    }        