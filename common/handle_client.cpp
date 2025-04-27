#include "common.h"
#include "iostream"
#include <sys/socket.h>

 void handle_connection(int client_fd){
        std::cout << dynamic_read(client_fd) << '\n';
        std::string msg{"Message from server\n"
        "This is line two from server\n"
        "This is the third line fromt he server and the last one\r,,"};
        send(client_fd, msg.c_str(), msg.size(), 0);
}
