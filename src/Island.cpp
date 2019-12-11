#include "Island.h"

/////////////////////////////////////////////////////////////////
// PUBLIC
/////////////////////////////////////////////////////////////////

/**
 * Constructor
 * 
 * Creates an Island with a specific size. Size is assumed to be
 * 2 or greater. 
 */
Island::Island(int size) {
    this->size = size;
    this->dogs = {};
    Island::fill();
}

/**
 * find_parents function
 * 
 * Searches through all dogs on the island to find the two dogs
 * which rate the closest to the softie.
 */
vector<DNA> Island::find_parents() {
    //take first two dogs as starting parents
    vector<DNA> parents(2);
    vector<float> parent_ratings(2);
    for (int i = 0; i < parents.size(); i++) {
        parents[i] = dogs[i];
        parent_ratings[i] = rate(parents[i]);
    }

    //identify lower of two parents:
    int lower_index = parent_ratings[0] > parent_ratings[1];

    //compare to other dogs on island:
    for (int i = 2; i < dogs.size(); i++) {//iterate through dogs
        //get current dogs rating:
        float r = rate(dogs[i]);

        //compare current dog to lower parent:
        if ( parent_ratings[lower_index] < r ) {//if current dog is better than the parent
            //replace parent:
            parents[lower_index] = dogs[i];
            parent_ratings[lower_index] = r;

            //determine new lower parent:
            lower_index = parent_ratings[0] > parent_ratings[1];
        }
    }

    //return best parents
    return parents;
}

/**
 * set_parents function
 * 
 * Sets the island to have only the given parents as inhabitants. 
 */
void Island::set_parents(vector<DNA> parents) {
    dogs = parents;
}

/////////////////////////////////////////////////////////////////
// PRIVATE
/////////////////////////////////////////////////////////////////

/**
 * fill function
 * 
 * Adds dogs randomly generated dogs to the island 
 * until it is full. 
 */
void Island::fill() {
    while ( dogs.size() < size ) {
        dogs.push_back(DNA());
    }
}
