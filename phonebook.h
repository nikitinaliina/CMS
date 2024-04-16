#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "contact.h"


class Phonebook
{
    public:
    static Phonebook& instance()
    {
        static Phonebook* myInstance = new Phonebook();
        return *myInstance;
    }
    void addContact(const Contact& c);
    Contact findContact(const std::string& name, const std::string& surname);
    bool deleteContact(const std::string& name, const std::string& surname);
    bool editContact(const std::string& name, const std::string& surname, const Contact& newData);
    const std::vector<Contact>& getAll() const {return m_phonebook;  }
    private:
    std::vector<Contact> m_phonebook;
};
