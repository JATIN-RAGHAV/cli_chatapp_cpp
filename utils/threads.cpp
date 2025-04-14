#include <thread>
#include <vector>

std::vector<std::thread*> get_threads_vector(int number){
        std::vector<std::thread*> threads{new std::thread[number]};
        return threads;
}
