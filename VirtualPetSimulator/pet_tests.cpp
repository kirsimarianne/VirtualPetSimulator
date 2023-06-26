#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pet.h"

// Initialize with base values
Pet rex{};
// Initialize with new values
Pet mirri{"Mirri", Type::cat, 6, 6, 6};
// Initialize with maximum values
Pet leevi{"Leevi", Type::lizard, 10, 10, 10};
// Intialize with minimum values
Pet bob{"Bob", Type::bunny, 0, 0, 0};

TEST_CASE("Test initialization")
{
    SUBCASE("Test initialization with base values")
    {
        CHECK(rex.name == "Rex");
        CHECK(rex.type == 1);
        CHECK(rex.happiness == 5);
        CHECK(rex.fullness == 5);
        CHECK(rex.energy == 5);
    }

    SUBCASE("Test initialization with base values")
    {
        CHECK(mirri.name == "Mirri");
        CHECK(mirri.type == 2);
        CHECK(mirri.happiness == 6);
        CHECK(mirri.fullness == 6);
        CHECK(mirri.energy == 6);
    }
}

TEST_CASE("Feed pet")
{
    SUBCASE("Test: happiness and fullness increases")
    {
        feed_pet(rex);
        CHECK(rex.name == "Rex");
        CHECK(rex.type == 1);
        CHECK(rex.happiness == 6);
        CHECK(rex.fullness == 6);
        CHECK(rex.energy == 5);
    }

    SUBCASE("Test: happiness and fullness maximum")
    {
        feed_pet(leevi);
        CHECK(leevi.name == "Leevi");
        CHECK(leevi.type == 4);
        CHECK(leevi.happiness == 10);
        CHECK(leevi.fullness == 10);
        CHECK(leevi.energy == 10);
    }  
}

TEST_CASE("Play")
{
    SUBCASE("Test: happiness and fullness increases")
    {
        play(rex);
        CHECK(rex.name == "Rex");
        CHECK(rex.type == 1);
        CHECK(rex.happiness == 7);
        CHECK(rex.fullness == 6);
        CHECK(rex.energy == 4);
    }

    SUBCASE("Test: happiness maximum")
    {
        play(leevi);
        CHECK(leevi.name == "Leevi");
        CHECK(leevi.type == 4);
        CHECK(leevi.happiness == 10);
        CHECK(leevi.fullness == 10);
        CHECK(leevi.energy == 9);
    }

    SUBCASE("Test: energy minimum")
    {
        play(bob);
        CHECK(bob.name == "Bob");
        CHECK(bob.type == 3);
        CHECK(bob.happiness == 1);
        CHECK(bob.fullness == 0);
        CHECK(bob.energy == 0);
    }

    
}