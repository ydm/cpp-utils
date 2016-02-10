#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../utils/file.hpp"


TEST_CASE("Read files", "")
{
    using namespace utils::file;
    static const std::string expected("\nThe quick brown fox jumps over the lazy dog.\n");
    REQUIRE(read("./files/file/text.txt") == expected);
    REQUIRE(read("./files/file/empty.txt") == "");
    REQUIRE(read("./files/file/__unexisting__") == "");
}
