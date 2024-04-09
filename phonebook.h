#pragma once
#include <vector>
#include "contact.h"

class Phonebook
{
    public:
    void addContact();
    void findContact();
    void displayAll();
    void displayContact(Contact myContact) const;
    //void displayAll();
    //Do not forget to create show all in cpp 
    void deleteContact();
    void editContact();

    private:
    std::vector<Contact> m_phonebook;
};
