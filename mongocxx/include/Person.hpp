#pragma once

#include <iostream>
#include <string>

namespace SocialApp {
    class Person {
        private:
          int _id;
          std::string _firstName;
          std::string _lastName;
        public:
          Person(int id, std::string firstName, std::string lastName);
          int getId();
          std::string getFirstName();
          std::string getLastName();
          std::string getFullName();
          void setFirstName(std::string value);
          void setLastName(std::string value);
          friend std::ostream& operator<<(std::ostream& stream, Person& value);
    };
};
