#pragma once

#include <string>
#include <vector> 
#include <mongocxx/client.hpp>
#include <bsoncxx/json.hpp>

#include "Person.hpp"

namespace SocialApp {
    class PersonRepository {
        private:
          mongocxx::collection _collection;
          std::string databaseName = "social";
          std::string collectionName = "people";
          Person fromBson(bsoncxx::document::view value);
          bsoncxx::document::view toBson(Person value);
          
        public:
          PersonRepository(mongocxx::client& client);
          std::vector<Person> getPersonsByLastName(std::string lastName);
          std::optional<Person> getPersonById(int id);
          void bulkInsert(std::vector<Person> persons);
          void dropCollection();
    };
};
