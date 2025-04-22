#include <iostream>
#include <netinet/in.h>
#include "arpa/inet.h"
#include <sys/socket.h>
#include "../utils/utils.hpp"


int PORT = 8080;
std::string IP{"127.0.0.1"};

int main(){
        int sock;
        struct sockaddr_in server_addr;
        int addr_len = sizeof(server_addr);

        if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0){
                std::cout << "Unable to create a socket";
                exit(1);
        }
        server_addr.sin_port = htons(PORT);
        server_addr.sin_family = AF_INET;

        inet_pton(AF_INET, IP.c_str(), &server_addr.sin_addr);

        if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0){
                std::cerr << "Couldn't connect to the server.";
                exit(2);
        }

        std::cout << "Connection made\n";
        std::string Message{"Hello server\n"
        "This is line two\n"
        "This is line three\r"};
        send(sock, Message.c_str(), Message.size(), 0);

        std::cout << dynamic_read(sock) << '\n';
}
