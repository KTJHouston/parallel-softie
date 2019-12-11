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
