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

void play(Pet& pet)
{
    if(pet.happiness < MAX)
    {
        ++pet.happiness;
    }
    if(pet.energy > MIN)
    {
        --pet.energy;
    }
}

void sleep(Pet& pet)
{
    if(pet.energy < MAX)
    {
        ++pet.energy;
    }
}