#include <algorithm>
#include <string>
#include <sys/socket.h>
#include <vector>

std::string dynamic_read(int sock){
        std::string data;
        std::vector<char> buffer(1024);

        while(true){
                int read = recv(sock, buffer.data(), buffer.size(), 0);
                auto found = buffer.begin();
                if((found = std::find(buffer.begin(), buffer.end(), '\r')) != buffer.end()){
                        data.append(buffer.begin(), found);
                        return data;
                }
                data.append(buffer.data(),read);
        }
        return nullptr;
}
