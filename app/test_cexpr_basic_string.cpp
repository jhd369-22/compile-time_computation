#include <iostream>
#include <ra/cexpr_basic_string.hpp>

constexpr bool testing_empty_string_constructor();
constexpr bool testing_copy_constructor();
constexpr bool testing_copy_assignment_operator();
constexpr bool testing_string_constructor();
constexpr bool testing_iterator_constructor();
constexpr bool testing_push_back();
constexpr ra::cexpr::cexpr_basic_string<char, 10> testing_push_back_helper();
constexpr bool testing_pop_back();
constexpr ra::cexpr::cexpr_basic_string<char, 10> testing_pop_back_helper();
constexpr bool testing_append();
constexpr ra::cexpr::cexpr_basic_string<char, 10> testing_append_helper();


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
constexpr bool testing_copy_assignment_operator() {
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

// test6 helper function
constexpr ra::cexpr::cexpr_basic_string<char, 10> testing_push_back_helper() {
    ra::cexpr::cexpr_basic_string<char, 10> r;
    r.push_back('h');

    return r;
}

// test6
constexpr bool testing_push_back() {
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r = testing_push_back_helper();
    static_assert(r.max_size() == 10);
    static_assert(r.capacity() == 10);
    static_assert(r.size() == 1);
    static_assert(r.begin() != r.end());
    static_assert(r[0] == 'h');

    return true;
}

// test7 helper function
constexpr ra::cexpr::cexpr_basic_string<char, 10> testing_pop_back_helper() {
    ra::cexpr::cexpr_basic_string<char, 10> r("hello");
    r.pop_back();

    return r;
}

// test7
constexpr bool testing_pop_back() {
    constexpr ra::cexpr::cexpr_basic_string<char, 10> r = testing_pop_back_helper();
    static_assert(r.max_size() == 10);
    static_assert(r.capacity() == 10);
    static_assert(r.size() == 4);
    static_assert(r.begin() != r.end());
    static_assert(r[4] == '\0');

    return true;
}

// test8 helper function
constexpr ra::cexpr::cexpr_basic_string<char, 15> testing_append_helper() {
    ra::cexpr::cexpr_basic_string<char, 15> r("hello");
    r.append(" world");

    return r;
}

// test8 append
constexpr bool testing_append() {
    constexpr ra::cexpr::cexpr_basic_string<char, 15> r = testing_append_helper();
    static_assert(r.max_size() == 15);
    static_assert(r.capacity() == 15);
    static_assert(r.size() == 11);
    static_assert(r.begin() != r.end());
    static_assert(r[0] == 'h');
    static_assert(r[1] == 'e');
    static_assert(r[2] == 'l');
    static_assert(r[3] == 'l');
    static_assert(r[4] == 'o');
    static_assert(r[5] == ' ');
    static_assert(r[6] == 'w');
    static_assert(r[7] == 'o');
    static_assert(r[8] == 'r');
    static_assert(r[9] == 'l');
    static_assert(r[10] == 'd');
    static_assert(r[11] == '\0');

    return true;
}

int main() {
    static_assert(testing_empty_string_constructor(), "test1 failed");
    static_assert(testing_copy_constructor(), "test2 failed");
    static_assert(testing_copy_assignment_operator(), "test3 failed");
    static_assert(testing_string_constructor(), "test4 failed");
    static_assert(testing_iterator_constructor(), "test5 failed");
    static_assert(testing_push_back(), "test6 failed");
    static_assert(testing_pop_back(), "test7 failed");
    static_assert(testing_append(), "test8 failed");

    return 0;
}