#include "Person.hpp"

namespace SocialApp {

    Person::Person(int id, std::string firstName, std::string lastName) {
        _id = id;
        _firstName = firstName;
        _lastName = lastName;
    }

    int Person::getId() {
        return _id;
    }

    std::string Person::getFirstName() {
        return _firstName;
    }

    std::string Person::getLastName() {
        return _lastName;
    }

    std::string Person::getFullName() {
        return getFirstName() + " " + getLastName();
    }

    void Person::setFirstName(std::string value) {
        _firstName = value;
    }

    void Person::setLastName(std::string value) {
        _lastName = value;
    }
    std::ostream& operator<<(std::ostream& stream, Person& value) {
        return stream << "{ \"_id\": " << value.getId() 
          << ", \"fname:\": \"" << value.getFirstName() 
          << "\", \"lname:\": \"" << value.getLastName() 
          << "\" }";
    }
}
