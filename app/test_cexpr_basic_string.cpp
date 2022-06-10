#include <cassert>
#include <iostream>
#include <ra/cexpr_basic_string.hpp>

constexpr bool testing_empty_string_constructor();
constexpr bool testing_copy_constructor();
constexpr bool testing_copy_assignment_operator();
constexpr bool testing_string_constructor();
constexpr bool testing_iterator_constructor();
constexpr ra::cexpr::cexpr_basic_string<char, 10> testing_push_back_helper();
constexpr bool testing_push_back();
constexpr ra::cexpr::cexpr_basic_string<char, 10> testing_pop_back_helper();
constexpr bool testing_pop_back();
constexpr ra::cexpr::cexpr_basic_string<char, 15> testing_append_helper();
constexpr bool testing_append();
bool testing_self_append();
constexpr ra::cexpr::cexpr_basic_string<char, 15> testing_template_append_helper();
constexpr ra::cexpr::cexpr_basic_string<char, 15> testing_template_self_append_helper();
bool testing_template_self_append();
constexpr std::size_t testing_to_string_helper();
constexpr bool testing_to_string();
bool testing_to_string2();

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
    static_assert(r[1] == '\0');

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

// test8
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

// test8 self append
bool testing_self_append() {
    ra::cexpr::cexpr_basic_string<char, 15> r("hello");
    r.append(r.data());

    assert(r.max_size() == 15);
    assert(r.capacity() == 15);
    assert(r.size() == 10);
    assert(r.begin() != r.end());
    assert(r[0] == 'h');
    assert(r[1] == 'e');
    assert(r[2] == 'l');
    assert(r[3] == 'l');
    assert(r[4] == 'o');
    assert(r[5] == 'h');
    assert(r[6] == 'e');
    assert(r[7] == 'l');
    assert(r[8] == 'l');
    assert(r[9] == 'o');
    assert(r[10] == '\0');

    return true;
}

// test9 helper function
constexpr ra::cexpr::cexpr_basic_string<char, 15> testing_template_append_helper() {
    ra::cexpr::cexpr_basic_string<char, 15> r("hello");
    ra::cexpr::cexpr_basic_string<char, 15> r2(" world");
    r.append<15>(r2);

    return r;
}

// test9 helper function2
constexpr ra::cexpr::cexpr_basic_string<char, 15> testing_template_self_append_helper() {
    ra::cexpr::cexpr_basic_string<char, 15> r("hello");
    r.append<15>(r);

    return r;
}

// test9
constexpr bool testing_template_append() {
    constexpr ra::cexpr::cexpr_basic_string<char, 15> r = testing_template_append_helper();
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

    constexpr ra::cexpr::cexpr_basic_string<char, 15> r2 = testing_template_self_append_helper();
    static_assert(r2.max_size() == 15);
    static_assert(r2.capacity() == 15);
    static_assert(r2.size() == 10);
    static_assert(r2.begin() != r2.end());
    static_assert(r2[0] == 'h');
    static_assert(r2[1] == 'e');
    static_assert(r2[2] == 'l');
    static_assert(r2[3] == 'l');
    static_assert(r2[4] == 'o');
    static_assert(r2[5] == 'h');
    static_assert(r2[6] == 'e');
    static_assert(r2[7] == 'l');
    static_assert(r2[8] == 'l');
    static_assert(r2[9] == 'o');
    static_assert(r2[10] == '\0');

    return true;
}

// test10 helper function
constexpr std::size_t testing_to_string_helper() {
    char str[15] = "number is ";
    char* str_end = str + 10;

    return ra::cexpr::to_string(66, &(*str_end), 15, &(str_end));
}

// test10
constexpr bool testing_to_string() {
    constexpr std::size_t num_str = testing_to_string_helper();
    static_assert(num_str == 2);

    return true;
}

// test11
bool testing_to_string2() {
    char str[15] = "number is ";
    char* str_end = str + 10;

    std::size_t num_size = ra::cexpr::to_string(66, &(*str_end), 15, &(str_end));
    ra::cexpr::cexpr_basic_string<char, 15> r(str);
    assert(r.data()[0] == 'n');
    assert(r.data()[1] == 'u');
    assert(r.data()[2] == 'm');
    assert(r.data()[3] == 'b');
    assert(r.data()[4] == 'e');
    assert(r.data()[5] == 'r');
    assert(r.data()[6] == ' ');
    assert(r.data()[7] == 'i');
    assert(r.data()[8] == 's');
    assert(r.data()[9] == ' ');
    assert(r.data()[10] == '6');
    assert(r.data()[11] == '6');
    assert(r.data()[12] == '\0');

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
    static_assert(testing_template_append(), "test9 failed");
    static_assert(testing_to_string(), "test10 failed");
    assert(testing_to_string2());
    assert(testing_self_append());

    return 0;
}