When I cam across with a need to iterate over the partitioned array, either throug the std::partition or std::sort. I realized that there is nothing in stl that can simplify my task. So I decided to write a small library for doing so.


Iterate over partitions (trivial case)
```cpp
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

```

Split string to tokens
```cpp
std::string v = "abc asdf wer asdfk";
for(const auto p :
    nstl::create_partitions(std::cbegin(v), std::cend(v), [](auto lhs, auto rhs) {
         return lhs != ' ';
    })) {
    std::cout << std::string(p.begin(), p.end()) << std::endl;
}
```
