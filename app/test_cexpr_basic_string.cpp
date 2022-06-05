#include <iostream>
#include <ra/cexpr_basic_string.hpp>

// test1
constexpr bool testing_empty_string_constructor() {
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r;
    static_assert(r.max_size() == 10);
    static_assert(r.capacity() == 10);
    static_assert(r.size() == 0);
    static_assert(r.begin() == r.end());
    static_assert(r[0] == '\0');

    return true;
}

// test2
constexpr bool testing_copy_constructor() {
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r;
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r2(r);
    static_assert(r2.max_size() == 10);
    static_assert(r2.capacity() == 10);
    static_assert(r2.size() == 0);
    static_assert(r2.begin() == r2.end());
    static_assert(r2[0] == '\0');

    return true;
}

// test3
constexpr bool testing_copy_assignment() {
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r;
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r2 = r;
    static_assert(r2.max_size() == 10);
    static_assert(r2.capacity() == 10);
    static_assert(r2.size() == 0);
    static_assert(r2.begin() == r2.end());
    static_assert(r2[0] == '\0');

    return true;
}

// test4
constexpr bool testing_string_constructor() {
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r("hello");
    static_assert(r.max_size() == 10);
    static_assert(r.capacity() == 10);
    static_assert(r.size() == 5);
    static_assert(r.begin() != r.end());
    static_assert(r[0] == 'h');
    static_assert(r[1] == 'e');
    static_assert(r[2] == 'l');
    static_assert(r[3] == 'l');
    static_assert(r[4] == 'o');
    static_assert(r[5] == '\0');

    return true;
}


// test5
constexpr bool testing_iterator_constructor() {
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r("hello");
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r2(r.begin(), r.end());
    static_assert(r2.max_size() == 10);
    static_assert(r2.capacity() == 10);
    static_assert(r2.size() == 5);
    static_assert(r2.begin() != r2.end());
    static_assert(r2[0] == 'h');
    static_assert(r2[1] == 'e');
    static_assert(r2[2] == 'l');
    static_assert(r2[3] == 'l');
    static_assert(r2[4] == 'o');
    static_assert(r2[5] == '\0');

    return true;
}

int main() {
    static_assert(testing_empty_string_constructor(), "test1 failed");
    static_assert(testing_copy_constructor(), "test2 failed");
    static_assert(testing_copy_assignment(), "test3 failed");
    static_assert(testing_string_constructor(), "test4 failed");
    static_assert(testing_iterator_constructor(), "test5 failed");

    return 0;
}