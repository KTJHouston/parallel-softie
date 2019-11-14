
#include "DNA.h"

using namespace std;

float eval_coat_length(int coat_length);
float eval_stiffness(string stiffness);
float eval_bg_color(string bg_color);
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

    //coat stiffness
    eval += eval_stiffness(dog.readable_stiffness);
    //coat color
    eval += eval_bg_color(dog.readable_background_color);
float eval_coat_length(int coat_length) { 
    if(coat_length >= 8) {
        return 0.1;
    }
    else if(coat_length >= 4) {
        return 0.05;
    }
    else {
        return 0.0;
    }
}

float eval_stiffness(string stiffness) {
    if(stiffness.compare("Extremely soft") == 0 || stiffness.compare("Ultimate Softness") == 0) {
        return 0.1;
    }
    else if(stiffness.compare("More stiff than desirable") == 0) {
        return 0.05;
    }
    else {
        return 0.0;
    }
    
}

float eval_bg_color(string bg_color) {
    if(bg_color.compare("white") == 0) {
        return 0.1;
    }
    else {
        return 0.0;
    }
    }
    else {
        /* code */
    }

    return 0.0;
}