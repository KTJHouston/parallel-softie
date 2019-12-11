#ifndef DNA_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define DNA_H

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef unsigned long dna_t;

class DNA {
    private:
    dna_t dna;
    static bool seed_set;

    public:

    DNA();
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
    long to_number();

    static DNA breed(DNA a, DNA b);

    private:

    static string get_binary_representation(int value, int bit_count);

    static int rand_num(int start, int end);
    static dna_t clip(dna_t value, int start, int end);
    static dna_t multipoint_crossover(dna_t a, dna_t b, int cut_num);
    static void mutate(dna_t &seq, int mut_num);

}; //end DNA class

#endif //DNA_H
