#include <string>
#include <vector>

#include "Person.hpp"
#include "PersonRepository.hpp"

using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;

namespace SocialApp {
    
    PersonRepository::PersonRepository(mongocxx::client& client) {
        _collection = client[databaseName][collectionName];
    }

    void PersonRepository::dropCollection() {
      _collection.drop();  
    }

    std::vector<Person> PersonRepository::getPersonsByLastName(std::string lastName) {
        auto dataset = std::vector<Person>{};
        bsoncxx::builder::basic::document builder = {};
        builder.append(kvp("lname", lastName));
        bsoncxx::document::view filter = builder.extract().view();
        auto cursor = _collection.find(filter);
        for(auto&& document : cursor) {
            Person p = fromBson(document);
            dataset.push_back(p);
        }
        return dataset;
    }

    std::optional<Person> PersonRepository::getPersonById(int id) {
        bsoncxx::builder::basic::document builder = {};
        builder.append(kvp("_id", id));
        bsoncxx::document::view filter = builder.extract().view();
        bsoncxx::stdx::optional<bsoncxx::document::value> result = _collection.find_one(filter);
        if (result) {
            bsoncxx::document::view value = (*result).view();
            return fromBson(value);
        }
        return {};
    }

    void PersonRepository::bulkInsert(std::vector<Person> persons) {
        auto bulk = _collection.create_bulk_write();
        for(Person& person: persons) {
            auto operation = mongocxx::model::insert_one{toBson(person)};
            bulk.append(operation);
        }
        bulk.execute();
    }

    Person PersonRepository::fromBson(bsoncxx::document::view value) {
        Person person = Person{
            value["_id"].get_int32(), 
            value["fname"].get_utf8().value.to_string(),
            value["lname"].get_utf8().value.to_string()};
        return person;
    }

    bsoncxx::document::view PersonRepository::toBson(Person value) {
        bsoncxx::builder::basic::document builder = {};
        builder.append(kvp("_id", value.getId()));
        builder.append(kvp("fname", value.getFirstName()));
        builder.append(kvp("lname", value.getLastName()));
        return builder.extract().view();
    }
}
