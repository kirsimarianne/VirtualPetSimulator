#include "pet.h"

void feed_pet(Pet& pet)
{
    if(pet.happiness < MAX)
    {
        ++pet.happiness;
    }
    if(pet.fullness < MAX)
    {
        ++pet.fullness;
    }
}