#include <iostream>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "Person.hpp"
#include "PersonRepository.hpp"
#include "PersonRepositoryTests.hpp"

int main(int, char**) {
    const std::string connectionString = "mongodb://localhost:27017";
    const std::string databaseName = "social";
    const std::string collectionName = "people";
    
    mongocxx::instance inst{}; // invoke only once per program
    auto uri = mongocxx::uri{connectionString};
    auto client = mongocxx::client{uri};
    auto personRepo = SocialApp::PersonRepository{client};
    auto tests = SocialApp::PersonRepositoryTests{&personRepo};

    tests.run();
}
