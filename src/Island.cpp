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
    this->dogs = vector<DNA>(size);
    Island::fill();
}//end constructor

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
}//end find_parents

/**
 * set_parents function
 * 
 * Sets the island to have only the two given parents as inhabitants. 
 */
void Island::set_parents(vector<DNA> parents) {
    dogs = vector<DNA>(size);
    dogs[0] = parents[0];
    dogs[1] = parents[1];
}//end set_parents

/**
 * breed function
 * 
 * Fills the island with offspring from the first two dogs. 
 */
void Island::breed() {
    DNA p1 = dogs[0];
    DNA p2 = dogs[1];

    #pragma omp parallel for shared(dogs)
    for (int i = 2; i < size; i++) {
        dogs[i] = DNA::breed(p1, p2);
    }
}//end breed

/**
 * percent_softie function
 * 
 * Returns the percentage of dogs on the island 
 * that are considered softies. 
 */
float Island::percent_softie() {
    float softie_cnt = 0;
    for (int i = 0; i < dogs.size(); i++) {
        if ( rate(dogs[i]) >= 1.0 ) {
            softie_cnt++;
        }
    }
    return softie_cnt / dogs.size();
}//end percent_softie

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
    #pragma omp parallel for shared(dogs)
    for (int i = 0; i < size; i++) {
        dogs[i] = DNA();
    }
}//end fill
