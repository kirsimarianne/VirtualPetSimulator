#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pet.h"

TEST_CASE("Create with initialised values and setted values")
{
    Pet pet1{};
    CHECK(pet1.name == "Rex");
    CHECK(pet1.type == 1);
    CHECK(pet1.happiness == 5);
    CHECK(pet1.fullness == 5);
    CHECK(pet1.energy == 5);

    Pet pet2{"Mirri", Type::cat, 6, 6, 6};
    CHECK(pet2.name == "Mirri");
    CHECK(pet2.type == 2);
    CHECK(pet2.happiness == 6);
    CHECK(pet2.fullness == 6);
    CHECK(pet2.energy == 6);
}

TEST_CASE("Feed pet")
{
    Pet pet1{};
    feed_pet(pet1);
    CHECK(pet1.name == "Rex");
    CHECK(pet1.type == 1);
    CHECK(pet1.happiness == 6);
    CHECK(pet1.fullness == 6);
    CHECK(pet1.energy == 5);

    Pet pet2{"Mirri", Type::cat, 10, 10, 10};
    CHECK(pet2.name == "Mirri");
    CHECK(pet2.type == 2);
    CHECK(pet2.happiness == 10);
    CHECK(pet2.fullness == 10);
    CHECK(pet2.energy == 10);
}
