#include "contact.h"
#include "phonebook.h"
#include "userinterface.h"


void Phonebook::addContact(const Contact& myContact)
    
    {
        m_phonebook.push_back(myContact);
        std::cout << "Contact added successfully!" << std::endl;
    }

Contact Phonebook::findContact(const std::string& name, const std::string& surname)

{
    for (const auto& contact : m_phonebook)
        {
            if (contact.getName() == name && contact.getSurname() == surname)
                {
                    return contact;
                }
        }
        //I think it will be better to output smth like "No contact found"
        return Contact("", "");
                
}

bool Phonebook::deleteContact(const std::string& name, const std::string& surname)
    {
        for (auto& contact : m_phonebook)
                    
            {
                if (contact.getName() == name && contact.getSurname() == surname) 
                    {
                        std::vector<Contact>::iterator i;
                        *i = contact;
                        m_phonebook.erase(i);
                        return true;                        
                    }
            }
            //if NOT FOUND
            return false;                    
    }
            
bool Phonebook::editContact(const std::string& name, const std::string& surname, const Contact& newData)
    {
        for (auto& contact : m_phonebook)
        {            
            if (contact.getName() == name && contact.getSurname() == surname)
            {
                contact = newData;           
            }
        }
        return false;
    }        