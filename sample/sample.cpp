#include <partition_iterator.hpp>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    std::vector< int > v{1, 1, 1, 3, 4, 5, 5, 6, 6, 10};
    for(const auto p :
        nstl::create_partitions(std::cbegin(v), std::cend(v), std::equal_to< int >())) {
        std::cout << "new partition" << std::endl;
        for(const auto v : p) {
            std::cout << v << std::endl;
        }
    }
}
