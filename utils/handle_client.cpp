#include "./utils.h"
#include "iostream"
#include <sys/socket.h>

 void handle_connection(int client_fd){
        std::cout << dynamic_read(client_fd) << '\n';
        std::string msg{"Message from server\r"};
        send(client_fd, msg.c_str(), msg.size(), 0);
}
