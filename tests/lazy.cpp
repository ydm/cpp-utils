#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../utils/lazy.hpp"


// ------------------------
// Test object
// ------------------------
class Object
{
public:
    Object(int v) : value(v) {}
    ~Object() = default;
    const int value;
};


// ------------------------
// Lazy evaluator
// ------------------------
class Test : public utils::lazy::Lazy<Object>
{
public:
    Test(const int value) : value_(value) {}
    ~Test() = default;
protected:
    Object *init() const override { return new Object(-value_); }
private:
    const int value_;
};


// ------------------------
// Test case
// ------------------------
TEST_CASE("Lazy evaulation", "[lazy]")
{
    const Test t(777);

    SECTION("operator-> should evaluate")
    {
        REQUIRE(t.pointer() == nullptr);
        REQUIRE(t->value == -777);
        REQUIRE(t.pointer() != nullptr);
    }
    
    SECTION("operator() should evaluate")
    {
        REQUIRE(t.pointer() == nullptr);
        REQUIRE(t().value == -777);
        REQUIRE(t.pointer() != nullptr);
    }

    SECTION("both operators should work together")
    {
        REQUIRE(t.pointer() == nullptr);
        REQUIRE(t->value  == -777     );
        REQUIRE(t().value == -777     );
        REQUIRE(t->value  == t().value);
        REQUIRE(t.pointer() != nullptr);
    }
}
