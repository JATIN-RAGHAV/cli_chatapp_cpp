#include <pqxx/pqxx>
#include <unistd.h>
#include "iostream"
#include "common.h"
#include "libenvpp/env.hpp"

std::string get_connection_string();

void database(){

        std::string connection_string = get_connection_string();

        pqxx::connection conn{connection_string};

        pqxx::work txn{conn};

        pqxx::result r = txn.exec("SELECT * FROM first");

        for (auto row : r){
                int id{row["id"].as<int>()};
                std::string name{row["name"].as<std::string>()};
                std::cout << "id: " << id << ", name: " << name << '\n';
        }

        std::cout << "Got some string";

        txn.commit();
}

std::string get_connection_string(){
        std::string dbname{"users"};
        std::string user{"users_owner"};
        std::string host{"ep-nameless-frost-a177hh9k-pooler.ap-southeast-1.aws.neon.tech"};
        std::string password = read_env(".env");
        std::stringstream connection_stream;

        connection_stream << "dbname=" << dbname << " user=" << user << " password=" << password << " host=" << host << " sslmode=required";

        return connection_stream.str();
}
