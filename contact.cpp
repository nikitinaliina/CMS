#include "contact.h"

std::ostream & operator << (std::ostream &out, const Contact &c)
{
    out << "Name: " << c.getName() << std::endl;
    out << "Surname: " << c.getSurname() << std::endl;
    out << "Phone Number: " << c.getNumber() << std::endl;

    return out;
}


Contact::Contact(const std::string& name, 
            const std::string& surname, 
            const std::string& number) 
            {setName(name);
            setSurname(surname);
            setNumber(number);}

Contact::Contact(const std::string& name, 
            const std::string& surname) 
            {setName(name);
            setSurname(surname);}
            
void Contact::setName(const std::string& name) { m_name = name; }

const std::string& Contact::getName() const { return m_name; }

void Contact::setSurname(const std::string& surname) { m_surname = surname; }

const std::string& Contact::getSurname() const{ return m_surname; }

void Contact::setNumber(const std::string& number) { m_number = number; }

const std::string& Contact::getNumber() const { return m_number; }
      

   
   