#include <fstream>
#include <iostream>
#include <string>

std::string read_env(std::string path){
        std::ifstream file(path);

        if(!file.is_open()){
                std::cerr << "Couldn't open the file " << path;
                exit(1);
        }

        std::string s{};
        file >> s;
        file.close();
        return s;
}
