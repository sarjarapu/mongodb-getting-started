#pragma once

#include <iostream>

#include "PersonRepository.hpp"

namespace SocialApp {
    class PersonRepositoryTests {
        private:
            PersonRepository *_repo;
            void getPersonById();
            void getPersonsByLastName();
            void insertPersonsInBulk();
            Person generateAPerson(int i);     
            void clearCollectionData();
            void createSampleData();
            
        public:
            PersonRepositoryTests(PersonRepository *repo);
            void run();
    };
};