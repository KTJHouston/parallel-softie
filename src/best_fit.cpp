
#include "DNA.h"

using namespace std;

float eval_coat_length(int coat_length);
/***
 * best_fit function
 * 
 * designed to rate a dog's DNA against
 * the DNA of the desired 'softie' type
 * 
 * coat_length >= 8 inches
 * stiffness = extremely soft (or even better ultimate softness)
 * background color = white
 * foreground color = brown
 * paw color = white
 * tail color = black
 * tail length and shape = 4 to 6 inches, pointing straight up
 * weight >= 90 kg
 * pawprint area > 9 sq inches
 * webbing = fully webbed between toes
 * temper = extremely mild tempered
 *
 * Any dog with a float of 1.0 or higher is considered a softie. Each
 * characteristic is responsible for 0.1 of the total evaluation
 * 
 * ***/   
float best_fit(DNA dog) {
    float eval = 0.0;
    //coat_length
    eval += eval_coat_length(stoi(dog.readable_coat_length));

float eval_coat_length(int coat_length) { 
    if(coat_length >= 8) {
        return 0.1;
    }
    else if(coat_length >= 4) {
        return 0.05;
    }
    else {
    }
    //coat stiffness
    if(dog.readable_stiffness == "Extremely soft" || dog.readable_stiffness == "Ultimate Softness") {
        eval += 0.1;
    }
    else {
        /* code */
    }
    //coat color
    if(dog.readable_background_color == "white"){
        eval += 0.1;
    }
    else {
        /* code */
    }
    if(dog.readable_foreground_color == "brown"){
        eval += 0.1;
    }
    else {
        /* code */
    }

    return 0.0;
}