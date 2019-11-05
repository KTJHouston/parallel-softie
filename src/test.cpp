#include <iostream>
#include <string>

#include "DNA.h"

using namespace std;
void print_states(int num);

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
    for (long i = 0; i < 1024; i++) {
        long input = i << 16;
        DNA d = DNA(input);
        cout << d.readable_weight() << endl;
        cout.flush();
    }
    
    //DNA d = DNA(8);
    //cout << DNA::to_string(d) << endl;
}
