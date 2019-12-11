#include <iostream>
#include <string>
#include <vector>

#include "best_fit.h"
#include "DNA.h"
#include "Island.h"

using namespace std;

int check_parents(vector<DNA> parents);

int main(int argc, char** argv) {
    
    /**
     * attribute : shift value : max_size
     * -----------------------
     * coat_length    : 56   : 256   
     * stiffness      : 50   : 64
     * back_color     : 44   : 64
     * fore_color     : 38   : 64
     * paw_&_tail     : 36   : 4
     * tail_len_&_shp : 26   : 1024
     * weight         : 16   : 1024
     * pawprint_area  : 9    : 128
     * webbing        : 6    : 8
     * temper         : 0    : 64
     * ****/
    //print out all possibles values of one attribute
    /*
     for (long i = 0; i < 1024; i++) {

        long input = i << 16;
        DNA d = DNA(input);
        cout << d.readable_weight() << endl;
        cout.flush();

    } */
    /*
    //Test Best_fit
    unsigned long input = 0b1111111000000111000000000101001111110011110100011011010111000100;
    unsigned long softie =  0b1111001000000111000000000101001100100010110100001011010111000100;
    unsigned long failure = 0b0000000000000000000000000000000000000000000000000000000000000000;
    DNA d = DNA(failure);
    cout << DNA::to_string(d) << endl;
    float evaluation = best_fit(d);
    cout << "Best Fit Percentage: " << evaluation << endl;
    */
    /*
    //Test breeding:
    DNA d = DNA();
    DNA e = DNA();
    DNA child = DNA::breed(d, e);
    cout << DNA::to_string(d) << endl << endl;
    cout << DNA::to_string(e) << endl << endl;
    cout << DNA::to_string(child) << endl << endl;
    */

    Island island = Island(500);
    DNA softie;
    //int softie_index = -1;
    int gen_cnt = 0;
    
    //find parents:
    vector<DNA> parents = island.find_parents();

    //setting my own starting parents:
    //parents[0] = DNA(0);
    //parents[1] = DNA(0);

    //if parent is softie, end
    //softie_index = check_parents(parents);

    while ( island.percent_softie() < .1 ) {
        //print ratings:
        cout << "Gen " << gen_cnt << endl;
        for (int i = 0; i < parents.size(); i++) {
            cout << "Rating: " << rate(parents[i]) << endl;
        }
        cout << "Softie Percent: " << island.percent_softie() << endl;
        cout << endl;

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
    }

    cout << "Gen " << gen_cnt << endl;
    for (int i = 0; i < parents.size(); i++) {
        cout << "Rating: " << rate(parents[i]) << endl;
        cout << DNA::to_string(parents[i]) << endl << endl;
    }
    cout << "Softie Percent: " << island.percent_softie() << endl;
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
