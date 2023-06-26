#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pet.h"

// Unit tests for pet.cpp

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
    SUBCASE("Test: happiness increases, energy decreases")
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

TEST_CASE("Sleep")
{
    SUBCASE("Test: energy increases")
    {
        sleep(rex);
        CHECK(rex.name == "Rex");
        CHECK(rex.type == 1);
        CHECK(rex.happiness == 7);
        CHECK(rex.fullness == 6);
        CHECK(rex.energy == 5);
    }
    // add one sleep because energy is 9 from previous test
    sleep(leevi);
    CHECK(leevi.name == "Leevi");
    CHECK(leevi.type == 4);
    CHECK(leevi.happiness == 10);
    CHECK(leevi.fullness == 10);
    CHECK(leevi.energy == 10);

    SUBCASE("Test: maximum")
    {
        sleep(leevi);
        CHECK(leevi.name == "Leevi");
        CHECK(leevi.type == 4);
        CHECK(leevi.happiness == 10);
        CHECK(leevi.fullness == 10);
        CHECK(leevi.energy == 10);
    }
}

TEST_CASE("Display")
{
    SUBCASE("happiness")
    {
        CHECK(display_happiness(rex) == 7);
    }
    SUBCASE("fullness")
    {
        CHECK(display_fullness(rex) == 6);
    }
    SUBCASE("energy")
    {
        CHECK(display_energy(rex) == 5);
    }
}

TEST_CASE("Out and in file")
{
    SUBCASE("Save state to file")
    {
        CHECK(save_state(rex) == true);
    }
    SUBCASE("get state from file")
    {
        std::vector<int> state_vect{};
        bool state_input = get_state(rex, state_vect);
        CHECK(state_input == true);
        CHECK(state_vect[0] == display_happiness(rex));
        CHECK(state_vect[1] == display_fullness(rex));
        CHECK(state_vect[2] == display_energy(rex));
    }
}