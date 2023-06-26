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

int display_happiness(Pet& pet)
{
    return pet.happiness;
}

int display_fullness(Pet& pet)
{
    return pet.fullness;
}

int display_energy(Pet& pet)
{
    return pet.energy;
}