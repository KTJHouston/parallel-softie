#include <iostream>
#include <string>

#include "DNA.h"

using namespace std;
void print_states(int num);

int main(int argc, char** argv) {
    
    /**
     * attribute : shift value : max_size
     * -----------------------
     * coat_length    : 56   : 255   
     * stiffness      : 50   : 64
     * back_color     : 47   : 64
     * fore_color     : 41   : 64
     * paw_&_tail     : 37   : 4
     * tail_len_&_shp : 33   : 1024
     * weight         : 26   : 1024
     * pawprint_area  : 11   : 128
     * webbing        :      : 8
     * temper         : none : 64
     * ****/
    //print out all possibles values of one attribute
    for (long i = 0; i < 128; i++) {
        long input = i << 11;
        DNA d = DNA(input);
        cout << d.readable_tail_length_and_shape() << endl;
        cout.flush();
    }
    
    //DNA d = DNA(8);
    //cout << DNA::to_string(d) << endl;
}
