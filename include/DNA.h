#ifndef DNA_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define DNA_H

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>

using namespace std;

typedef unsigned long dna_t;

class DNA {
    private:
    dna_t dna;

    public:

    DNA(dna_t dna);

    string readable_coat_length();
    string readable_stiffness();
    string readable_background_color();
    string readable_foreground_color();
    string readable_paw_and_tail();
    string readable_tail_length_and_shape();
    string readable_weight();
    string readable_pawprint_area();
    string readable_webbing();
    string readable_temper();
    static string to_string(DNA d);

    private:

    string get_binary_representation(int value, int bit_count);

}; //end DNA class

#endif //DNA_H
