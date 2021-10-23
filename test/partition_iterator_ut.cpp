#include <partition_iterator.hpp>
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_NO_CPP17_UNCAUGHT_EXCEPTIONS
#include "catch.hpp"
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>

namespace {

    SCENARIO("Iterate partitions", "[partition]") {
        GIVEN(
         "A sorted vector of integers and paritions based on the equality of "
         "the values") {
            std::vector< int > v{1, 1, 1, 3, 4, 5, 5, 6, 6, 10};
            const auto partitions =
             nstl::create_partitions(begin(v), end(v), std::equal_to< int >());
            WHEN("Calculating the number of the partitions") {
                const auto number_of_partitions =
                 std::distance(std::cbegin(partitions), std::cend(partitions));
                THEN(
                 "The number of partitions is equal to the number of unique "
                 "values in the vector") {
                    REQUIRE(std::distance(begin(v), std::unique(begin(v), end(v))) ==
                            number_of_partitions);
                }
            }
            WHEN("Calculating calling the  size() of the paritions") {
                const auto number_of_partitions = partitions.size();
                THEN(
                 "The size is equal to the number of unique values in the "
                 "vector") {
                    REQUIRE(std::distance(begin(v), std::unique(begin(v), end(v))) ==
                            number_of_partitions);
                }
            }
            WHEN("Iterating over the partitions") {
                for(const auto p : partitions) {
                    THEN("Partition has the same value") {
                        REQUIRE(std::equal(next(cbegin(p)), cend(p), cbegin(p)));
                    }
                }
            }
        }
    }

} // namespace
