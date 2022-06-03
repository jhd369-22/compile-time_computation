#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <ra/cexpr_basic_string.hpp>

// catch2 template test cases
TEMPLATE_TEST_CASE("empty_string constructor", "[cexpr_basic_string]", char, unsigned char, wchar_t) {
    constexpr ra::cexpr::cexpr_basic_string<TestType, 10> r;
    CHECK(static_assert(r.size() == 0));
    CHECK(static_assert(r.capacity() == 10));
    CHECK(static_assert(r.max_size() == 10));
    CHECK(static_assert(r.begin() == r.end()));
}


