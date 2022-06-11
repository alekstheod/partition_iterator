#include <partition_iterator.hpp>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    std::vector< int > v = {1, 2, 4, 5, 6, 8, 9};
    for(const auto p :
        nstl::create_partitions(std::cbegin(v), std::cend(v), [](auto lhs, auto rhs) {
            return (rhs - lhs) < 2;
        })) {

        std::cout << "partition" << std::endl;
        for(auto val : p) {
            std::cout << val << std::endl;
        }
    }

    return 0;
}
