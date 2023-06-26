#ifndef PET_H
#define PET_H

#include <string>

const int MAX = 10;
const int MIN = 0;

enum Type { dog = 1,
            cat = 2,
            bunny = 3,
            lizard = 4,
            bird = 5 };
struct Pet
{
    std::string name{"Rex"};
    Type type{dog};
    int happiness{5};
    int fullness{5};
    int energy{5};
};

void feed_pet(Pet &pet);

#endif