#include <iostream>
#include <random>

#include "PersonRepositoryTests.hpp"

namespace SocialApp {

    PersonRepositoryTests::PersonRepositoryTests(PersonRepository *repo) {
        _repo = repo;
    }

    void PersonRepositoryTests::clearCollectionData() {
        std::cout << "Cleaning up existing collection" << std::endl;
        std::cout << std::endl;
        _repo->dropCollection();
    }

    void PersonRepositoryTests::createSampleData() {
        std::cout << "Adding some mock data to collection" << std::endl;
        std::cout << std::endl;
        auto data = std::vector<SocialApp::Person>{};
        data.push_back(Person{1, "Shyam", "Arjarapu"});
        data.push_back(Person{2, "Giri", "Manda"});
        data.push_back(Person{3, "Nidhi", "Arjarapu"});
        _repo->bulkInsert(data);
    }

    void PersonRepositoryTests::getPersonById() {
        std::optional<SocialApp::Person> person = _repo->getPersonById(2);
        std::cout << "getPersonById(2): "  << std::endl;
        if (person) {
            std::cout << person.value() << std::endl << std::endl;
        }
        else {
            std::cout << "Match not found." << std::endl << std::endl;
        }
    }

    void PersonRepositoryTests::getPersonsByLastName() {
        std::vector<SocialApp::Person> data = _repo->getPersonsByLastName("Arjarapu");
        std::cout << "getPersonsByLastName(\"Arjarapu\"): "  << std::endl;
        for(SocialApp::Person& p : data) {
            std::cout << p << std::endl;
        }
        std::cout << std::endl;
    }

    void PersonRepositoryTests::insertPersonsInBulk() {
        for(int j = 1; j <= 10000; j++) {
            auto data = std::vector<SocialApp::Person>{};
            for(int i = 0; i < 1000; i++) {
                auto person = generateAPerson(j*1000 + i);
                data.push_back(person);
            }
            _repo->bulkInsert(data);
            data.clear();
            if (j % 100 == 0) {
            std::cout << "Completed adding " << std::to_string(j*1000 + 1000) << " of 10,000,000" << std::endl;
            }
        }
        std::cout << std::endl;
    }

    Person PersonRepositoryTests::generateAPerson(int i) {
        Person person = Person{
            i,
            "fname" + std::to_string(std::rand() % 200),
            "lname" + std::to_string(std::rand() % 1000),
        };
        return person;
    }

    void PersonRepositoryTests::run() {
        clearCollectionData();
        createSampleData();
        getPersonById();
        getPersonsByLastName();
        insertPersonsInBulk();
    }
};