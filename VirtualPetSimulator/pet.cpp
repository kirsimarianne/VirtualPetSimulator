#include "pet.h"

void feed_pet(Pet &pet)
{
    if (pet.happiness < MAX)
    {
        ++pet.happiness;
    }
    if (pet.fullness < MAX)
    {
        ++pet.fullness;
    }
}

void play(Pet &pet)
{
    if (pet.happiness < MAX)
    {
        ++pet.happiness;
    }
    if (pet.energy > MIN)
    {
        --pet.energy;
    }
}

void sleep(Pet &pet)
{
    if (pet.energy < MAX)
    {
        ++pet.energy;
    }
}

int display_happiness(Pet &pet)
{
    return pet.happiness;
}

int display_fullness(Pet &pet)
{
    return pet.fullness;
}

int display_energy(Pet &pet)
{
    return pet.energy;
}

bool save_state(Pet &pet)
{
    std::ofstream state_file{"state.txt"};

    if(!state_file.is_open())
    {
        std::cerr << "state.txt could not be opened for writing!\n";
        return false;
    }
    state_file << "pet.name\n" 
    << "Happiness: " << display_happiness(pet) 
    << "\nFullness: " << display_fullness(pet) 
    << "\nEnergy: " << display_energy(pet);
    state_file.close();
    return true;
}