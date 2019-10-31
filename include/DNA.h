#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>

using namespace std;

typedef unsigned long dna_t;

class DNA
{
    private:
    dna_t dna;

    public:

    DNA(dna_t dna);

    string readable_coat_length();
    //readable_stiffness
    //readable_background_color
    //readable_foreground_color
    //readable_paw_and_tail
    //readable_tail_leangth_and_shape
    //readable_weight
    //readable_pawprint_area
    //readable_webbing
    //readbale_temper
    //to_string

    private:

    string get_binary_representation(int value, int bit_count);

};
