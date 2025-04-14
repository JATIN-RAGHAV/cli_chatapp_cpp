#include <iostream>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include "../utils/utils.h"
#include <netinet/in.h>

int PORT = 8080;

int main() {
        int server_fd;
        struct sockaddr_in address;
        int PORT = 8080;
        int addr_len = sizeof(address);
        
        if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
                std::cerr << "Can't start the server";
                exit(1);
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        if(bind(server_fd,(struct sockaddr*)&address, sizeof(address)) != 0){
                std::cerr << "Can't bind socket to address";
                exit(2);
        }

        listen(server_fd,10);
        std::cout << "Server is listening on port: " << PORT << '\n';


        while(true){
                int client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len);
                handle_connection(client_fd);
        }
}
