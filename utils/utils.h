#include <thread>
#include <vector>
void handle_connection(int client_fd);
std::vector<std::thread*> get_threads_vector(int number);
std::string dynamic_read(int sock);
