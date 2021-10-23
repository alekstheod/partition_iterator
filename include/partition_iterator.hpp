#include <iterator>

namespace nstl {
    namespace detail {
        template< typename Iterator >
        struct range {
            using iterator_type = Iterator;
            range(Iterator first, Iterator last) : m_begin{first}, m_end{last} {
            }
            Iterator begin() const {
                return m_begin;
            }

            Iterator end() const {
                return m_end;
            }

          private:
            Iterator m_begin;
            Iterator m_end;
        };

        template< typename Iterator, typename Compare >
        Iterator get_next(Iterator first, Iterator last, Compare compare) {
            auto pred = first;
            while(first != last && compare(*pred, *(first))) {
                pred = first;
                first++;
            }

            return first;
        }

        template< typename Iterator, typename Compare >
        struct range_iterator {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::size_t;
            using value_type = Iterator;
            using pointer = value_type*;
            using reference = value_type&;
            range_iterator(Iterator first, Iterator last, Compare compare)
             : m_begin{first}, m_next{get_next(first, last, compare)}, m_end{last}, m_compare{compare} {
            }

            range_iterator& operator++() {
                m_begin = m_next;
                m_next = get_next(m_begin, m_end, m_compare);
                return *this;
            }

            range_iterator operator++(int) {
                auto result = *this;
                m_begin = m_next;
                m_next = get_next(m_begin, m_end, m_compare);
                return result;
            }

            range< Iterator > operator*() const {

                return {m_begin, m_next};
            }

            bool operator==(range_iterator other) const {
                return (m_begin == other.m_begin);
            }

            bool operator!=(range_iterator other) const {
                return !(m_begin == other.m_begin);
            }

          private:
            Iterator m_begin;
            Iterator m_next;
            Iterator m_end;
            Compare m_compare;
        };

        template< typename RangeType, typename Compare >
        struct partitions {
            using Iterator = typename RangeType::iterator_type;
            partitions(Iterator first, Iterator last, Compare compare)
             : m_begin{first}, m_end{last}, m_compare{compare} {
            }

            range_iterator< Iterator, Compare > begin() const {
                return {m_begin, m_end, m_compare};
            }

            range_iterator< Iterator, Compare > end() const {
                return {m_end, m_end, m_compare};
            }

            std::size_t size() const {
                return static_cast< std::size_t >(std::distance(begin(), end()));
            }

          private:
            Iterator m_begin;
            Iterator m_end;
            Compare m_compare;
        };

    } // namespace detail
    template< typename Iterator, typename Compare >
    auto create_partitions(Iterator begin, Iterator end, Compare compare) {
        return detail::partitions< detail::range< Iterator >, Compare >{begin, end, compare};
    };
} // namespace nstl
