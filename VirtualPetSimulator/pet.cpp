#include "pet.h"

/* Function increases happiness and fullness 1 integer,
 * if variable does not have maximum value.
*/
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

/* Function increases happiness 1 integer,
 * if variable does not have maximum value.
 * And decreases energy 1 integer,
 * if variable does not have minimum value.
*/
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

/* Function increases energy 1 integer,
 * if variable does not have maximum value.
*/
void sleep(Pet &pet)
{
    if (pet.energy < MAX)
    {
        ++pet.energy;
    }
}

/* Function returns current happiness
*/
int display_happiness(Pet &pet)
{
    return pet.happiness;
}

/* Function returns current fullness
*/
int display_fullness(Pet &pet)
{
    return pet.fullness;
}

/* Function returns current energy
*/
int display_energy(Pet &pet)
{
    return pet.energy;
}

/* Function saves state to state.txt file.
 * Returns false if file can not open.
*/
bool save_state(Pet &pet)
{
    std::ofstream state_file{"state.txt"};

    if(!state_file.is_open())
    {
        std::cerr << "state.txt could not be opened for writing!\n";
        return false;
    }
    state_file << display_happiness(pet) << '\n'
    << display_fullness(pet) << '\n'
    << display_energy(pet) << '\n'; 
    state_file.close();
    return true;
}

/* Function gets state from output file and
 * and saves it to vector.
 * Function returns false, if file can not open,
 * or if vector size is not 3 (3 variables to get out from file.)
*/
bool get_state(Pet &pet, std::vector<int> &state_vect)
{
    std::ifstream state_file{"state.txt"};

    if(!state_file.is_open())
    {
        std::cerr << "state.txt could not be opened for reading!\n";
    }

    int state;
    while(state_file >> state)
    {
        state_vect.push_back(state);
    }

    if(state_vect.size() != 3)
    {
        std::cerr << "could not find data from state.txt!\n";
        return false;
    }

    return true;
}