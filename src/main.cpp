#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "best_fit.h"
#include "DNA.h"
#include "Island.h"

using namespace std;

int check_parents(vector<DNA> parents);
int single_island_sim(int size, bool verbose);
float multi_percent_softie(vector<Island> islands);

int main(int argc, char** argv) {
    //run sim 100 times:
    for (int i = 0; i < 100; i++) {
        int gen = single_island_sim(500, false);
    }
    //cout << "Gen " << gen << endl;
}

/**
 * check_parents function
 * 
 * Returns the index in the given array of parents which is 
 * considered a softie. If no parents are softies, -1 is returned. 
 */
int check_parents(vector<DNA> parents) {
    int softie_index = -1;
    for (int i = 0; i < parents.size(); i++) {
        if ( rate(parents[i]) >= 1.0 ) {
            softie_index = i;
            break;
        }
    }
    return softie_index;
}

/**
 * single_island_sim funciton
 * 
 * Creates an Island of a given size. Continues the 
 * breeding process until 10% of the islands population 
 * is up to softie standards. 
 * 
 * Verbose flag will print the generation number, the 
 * characteristics of the current parents, and the  
 * percentage of the island which count as softies. 
 * 
 * Even if the verbose flag is off, it will print the time 
 * the simulation ran for. 
 */
int single_island_sim(int size, bool verbose) {
    //start timer:
    auto t_start = std::chrono::high_resolution_clock::now();

    //init island:
    Island island = Island(size);
    int gen_cnt = 0;

    while ( island.percent_softie() < .1 ) {
        //find parents:
        vector<DNA> parents = island.find_parents();

        //set parents:
        island.set_parents(parents);

        //breed from parents:
        island.breed();

        //increase generation counter:
        gen_cnt++;

        //print ratings:
        if ( verbose ) {
            cout << "Gen " << gen_cnt << endl;
            for (int i = 0; i < parents.size(); i++) {
                cout << "Rating: " << rate(parents[i]) << endl;
            cout << DNA::to_string(parents[i]) << endl << endl;
            }
            cout << "Softie Percent: " << island.percent_softie() << endl;
            cout << endl;
        }
    }

    //end timer:
    auto t_end = std::chrono::high_resolution_clock::now();

    //print time to complete simulation:
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t_end - t_start ).count();
    //cout << "Single island speed: " << duration << " microseconds" << endl;
    cout << gen_cnt << "," << duration << endl;

    return gen_cnt;
}//end single island sim

/**
 * multi_percent_softie function
 * 
 * Returns the percentage of dogs on all the islands 
 * which qualify as softies. The function assumes the 
 * size of the islands are the same. 
 */
float multi_percent_softie(vector<Island> islands) {
    float total_percent = 0;
    for (int i = 0; i < islands.size(); i++) {
        total_percent += islands[i].percent_softie();
    }
    return total_percent / islands.size();
}
