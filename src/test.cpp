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

int main(int argc, char** argv) {
    int test_num = 0;
    int gen = 0;
    int gen_goal = 5000;
    while ( gen < gen_goal ) {
        gen = single_island_sim(500, false);
        cout << "Gen " << gen << endl;
        test_num++;
    }
    cout << test_num << " test before over " << gen_goal << " generations." << endl;
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
 * Verbose flag will print when the generation count 
 * reaches multiples of 100 and when the simulation 
 * is complete. The end of simulation print out includes 
 * the final generation number, the characteristics of the 
 * achieved parents, and the final softie percentage. 
 * 
 * Even if the verbose flag is off, it will print the time 
 * the simulation ran for. Also, it will print the generation 
 * count on multiples of 1000 for debugging purposes. 
 */
int single_island_sim(int size, bool verbose) {
    //start timer:
    auto t_start = std::chrono::high_resolution_clock::now();

    //init island:
    Island island = Island(size);
    int gen_cnt = 0;
    
    //find parents:
    vector<DNA> parents = island.find_parents();

    while ( island.percent_softie() < .1 ) {
        //print ratings:
        /*cout << "Gen " << gen_cnt << endl;
        for (int i = 0; i < parents.size(); i++) {
            cout << "Rating: " << rate(parents[i]) << endl;
        }
        cout << "Softie Percent: " << island.percent_softie() << endl;
        cout << endl;*/

        //set parents:
        island.set_parents(parents);

        //breed from parents:
        island.breed();

        //find parents:
        parents = island.find_parents();

        //if parent is softie, end
        //softie_index = check_parents(parents);

        //increase generation counter:
        gen_cnt++;
        if ( verbose && gen_cnt % 100 == 0 ) {
            cout << "Gen " << gen_cnt << endl;
        }
        if ( gen_cnt % 1000 == 0 ) {
            cout << "Gen " << gen_cnt << " (at least)" << endl;
            float p = island.percent_softie();
            cout << "Island percent: " << p << endl;
            for (int i = 0; i < parents.size(); i++) {
                cout << "Rating: " << rate(parents[i]) << endl;
                cout << DNA::to_string(parents[i]) << endl << endl;
            }
        }
    }

    auto t_end = std::chrono::high_resolution_clock::now();

    if ( verbose ) {
        cout << "Gen " << gen_cnt << endl << endl;
        for (int i = 0; i < parents.size(); i++) {
            //cout << "Rating: " << rate(parents[i]) << endl;
            cout << DNA::to_string(parents[i]) << endl << endl;
        }
        cout << "Softie Percent: " << island.percent_softie() << endl;
    }

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t_end - t_start ).count();
    cout << "Single island speed: " << duration << " microseconds" << endl;

    return gen_cnt;
}
