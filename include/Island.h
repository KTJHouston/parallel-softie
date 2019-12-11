#ifndef ISLAND_H
#define ISLAND_H

#include <vector>

#include "best_fit.h"
#include "DNA.h"

using namespace std;

class Island {
    private:
    int size;
    vector<DNA> dogs;

    public:

    Island(int size);

    private:
    void fill();
}; //end Island class

#endif //ISLAND_H
