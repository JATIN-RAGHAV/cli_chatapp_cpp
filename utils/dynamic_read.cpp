#include <algorithm>
#include <string>
#include <sys/socket.h>
#include <vector>
#include <iostream>

std::string dynamic_read(int sock){
        std::string data;
        std::vector<char> buffer(1024);

        while(true){
                int read = recv(sock, buffer.data(), buffer.size(), 0);
                std::cout << buffer.data();
                if(std::find(buffer.begin(), buffer.end(), '\r') != buffer.end()){
                        data.append(buffer.data(),read);
                        return data;
                }
                data.append(buffer.data(),read);
        }
        return nullptr;
}
