
#include <iostream>
#include "DNA.h"

using namespace std;

float eval_coat_length(string coat_length);
float eval_stiffness(string stiffness);
float eval_bg_color(string bg_color);
float eval_fg_color(string fg_color);
float eval_paw_color(string p_color);
float eval_tail_color(string t_color);
//float eval_t_len_and_shape(int length, string shape);
//float eval_weight(int weight);
//float eval_pp_area(int sq_inches);
//float eval_webbing(string webbing);
//float eval_temper(string temper);

/***
 * best_fit function
 * 
 * designed to rate a dog's DNA against
 * the DNA of the desired 'softie' type
 * 
 * There are 10 characteristics: coat length, stiffness,
 * coat background color, foreground color, paw color, tail color,
 * tail length (and shape), weight, pawprint area, webbing, and temper
 * 
 * TODO: remove once all aux methods are created
 * tail length and shape = 4 to 6 inches, pointing straight up
 * weight >= 90 kg
 * pawprint area > 9 sq inches
 * webbing = fully webbed between toes
 * temper = extremely mild tempered
 *
 * Any dog with a float of 1.0 or higher is considered a softie. Each
 * characteristic is responsible for 0.1 of the total evaluation.
 * 
 * ***/   
float best_fit(DNA dog) {
    float eval = 0.0;
    //coat_length
    eval += eval_coat_length(dog.readable_coat_length());

    //coat stiffness
    eval += eval_stiffness(dog.readable_stiffness);
    //coat color
    eval += eval_bg_color(dog.readable_background_color);
    eval += eval_fg_color(dog.readable_foreground_color);
    eval += eval_paw_color(dog.readable_paw_and_tail);
    eval += eval_tail_color(dog.readable_paw_and_tail);

    return eval;
}

/***
 * eval_coat_length function
 * 
 * evaluates the dog's coat length to see how close it
 * is to the softie
 * 
 * Desirable softie : 8 inches or longer
 * Close but not quite : 4 - 8 inches
 * 
 * @returns float
 * @param int coat_length
 * 
 ***/
float eval_coat_length(string coat_length) {
    int start = coat_length.find_first_of("]") + 1; 
    int end = coat_length.find_first_of("i") - start;
    string new_coat_length = coat_length.substr(start, end);
    cout << "DEBUG: coat_length in eval coat_length is : " << new_coat_length << endl;
    int coat_len = std::stoi(new_coat_length);
    
    if(coat_len >= 8) {
        return 0.1;
    }
    else if(coat_len >= 4) {
        return 0.05;
    }
    else {
        return 0.0;
    }
}

/***
 * eval_stiffness function
 * 
 * evaluates the dog's coat stiffness to see how close it
 * is to the softie
 * 
 * Desirable softie : Ultimate softness, Extremely soft
 * Close but not quite : More stiff than desirable
 * 
 * @returns float
 * @param string stiffness
 * 
 ***/
float eval_stiffness(string stiffness) {
    if(stiffness.find("Extremely soft") == 0 || stiffness.find("Ultimate Softness") == 0) {
        return 0.1;
    }
    else if(stiffness.find("More stiff than desirable") == 0) {
        return 0.05;
    }
    else {
        return 0.0;
    }
    
}

/***
 * eval_bg_color function
 * 
 * evaluates the dog's coat background color
 * to see how close it is to the softie
 * 
 * Desirable softie : white (background)
 * 
 * @returns float
 * @param string bg_color
 * 
 ***/
float eval_bg_color(string bg_color) {
    //white background
    if(bg_color.find("white") == 0) {
        return 0.1;
    }
    else {
        return 0.0;
    }
  
}


/***
 * eval_fg_color function
 * 
 * evaluates the dog's coat foreground color
 * to see how close it is to the softie
 * 
 * Desirable softie : brown (spots)
 * 
 * @returns float
 * @param string fg_color
 * 
 ***/
float eval_fg_color(string fg_color) {
    //brown spots
    if(fg_color.find("brown") == 0){
        return 0.1;
    }
    else {
        return 0.0;
    }

}


/***
 * eval_paw_color function
 * 
 * evaluates the dog's paw color
 * to see how close it is to the softie
 * 
 * Desirable softie : white
 * 
 * @returns float
 * @param string p_color
 * 
 ***/
float eval_paw_color(string p_color) {
    string paw_snip = p_color.substr(0,p_color.find_first_of("paws"));
    if(paw_snip.find("white") == 0) {
        return 0.1;
    }
    else {
        return 0.0;
    }
}


/***
 * eval_tail_color function
 * 
 * evaluates the dog's tail color
 * to see how close it is to the softie
 * 
 * Desirable softie : black
 * 
 * @returns float
 * @param string t_color
 * 
 ***/
float eval_tail_color(string t_color) {
    string tail_snip = t_color.substr(t_color.find_first_of("paws"), t_color.end);
    if(tail_snip.find("black") == 0) {
        return 0.1;
    }
    else {
        return 0.0;
    }
}

// TODO: float eval_t_len_and_shape(int length, string shape);
// TODO: float eval_weight(int weight);
// TODO: float eval_pp_area(int sq_inches);
// TODO: float eval_webbing(string webbing);
// TODO: float eval_temper(string temper);