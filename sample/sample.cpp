#include <iterator>
#include <partition_iterator.hpp>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    std::vector< int > v = {1, 2, 3, 2, 3, 4, 5, 1, 2};
    for(const auto p :
        nstl::create_partitions(std::cbegin(v), std::cend(v), [](auto lhs, auto rhs) {
            return lhs <= rhs;
        })) {
        std::cout << "new partition" << std::endl;
        std::copy(p.begin(),
                  p.end(),
                  std::ostream_iterator< int >(std::cout, ","));
    }
}
