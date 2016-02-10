#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../utils/str.hpp"


TEST_CASE("Join strings", "[str::join]")
{
    using namespace utils::str;
    REQUIRE(join(", ", {"qwe", "asd", "zxc"}) == "qwe, asd, zxc");
    REQUIRE(join(  "", {"qwe", "asd", "zxc"}) == "qweasdzxc");
    REQUIRE(join(  "", {}) == "");
    REQUIRE(join(", ", {}) == "");
}


TEST_CASE("Remove leading whitespace", "str::lstrip")
{
    using namespace utils::str;
    REQUIRE(lstrip("")        ==    "");
    REQUIRE(lstrip(" qwe")    == "qwe");
    REQUIRE(lstrip("  qwe")   == "qwe");
    REQUIRE(lstrip("\tqwe")   == "qwe");
    REQUIRE(lstrip("\t\tqwe") == "qwe");
    REQUIRE(lstrip("\nqwe")   == "qwe");
    REQUIRE(lstrip("\n\nqwe") == "qwe");
}


TEST_CASE("Remove trailing whitespace", "str::rstrip")
{
    using namespace utils::str;
    REQUIRE(rstrip("")        ==    "");
    REQUIRE(rstrip("qwe ")    == "qwe");
    REQUIRE(rstrip("qwe  ")   == "qwe");
    REQUIRE(rstrip("qwe\t")   == "qwe");
    REQUIRE(rstrip("qwe\t\t") == "qwe");
    REQUIRE(rstrip("qwe\n")   == "qwe");
    REQUIRE(rstrip("qwe\n\n") == "qwe");
}


TEST_CASE("Remove leading and trailing whitespace", "str::strip")
{
    using namespace utils::str;
    REQUIRE(strip("")         ==    "");
    REQUIRE(strip("\nqwe  ")  == "qwe");
    REQUIRE(strip("\tqwe  ")  == "qwe");
    REQUIRE(strip("\tqwe\t")  == "qwe");
    REQUIRE(strip("\tqwe\n")  == "qwe");
    REQUIRE(strip("\nqwe\t")  == "qwe");
    REQUIRE(strip("\nqwe\n")  == "qwe");
}


TEST_CASE("Check if string starts with another string", "str::startsWith")
{
    using namespace utils::str;
    REQUIRE(startsWith("qwe",   "q") == true );
    REQUIRE(startsWith("qwe",   "w") == false);
    REQUIRE(startsWith("qwe",   "e") == false);
    REQUIRE(startsWith(" qwe",  "q") == false);
    REQUIRE(startsWith(" qwe", " q") == true );
}
