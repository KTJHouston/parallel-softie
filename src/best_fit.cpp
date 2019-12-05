
#include <iostream>
#include "DNA.h"

using namespace std;

float eval_coat_length(long dna);
float eval_stiffness(long dna);
float eval_bg_color(string bg_color);
float eval_fg_color(string fg_color);
float eval_paw_color(string p_color);
float eval_tail_color(string t_color);
float eval_t_len_and_shape(long dna);
float eval_weight(long dna);
float eval_pp_area(long dna);
float eval_webbing(string webbing);
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
    eval = eval + eval_coat_length(dog.to_number()); 
    //coat stiffness
    eval += eval_stiffness(dog.to_number());
    //coat color
    eval += eval_bg_color(dog.readable_background_color());
    eval += eval_fg_color(dog.readable_foreground_color());
    eval += eval_paw_color(dog.readable_paw_and_tail());
    eval = eval + eval_tail_color(dog.readable_paw_and_tail());
    //tail length and shape
    eval = eval + eval_t_len_and_shape(dog.to_number());
    //weight
    eval = eval + eval_weight(dog.to_number());
    //paw print area
    eval = eval + eval_pp_area(dog.to_number());

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
 * @param long dna
 * NOT TESTED
 ***/
float eval_coat_length(long dna) {
    //snip dna segment:
    int length_bits = 0xff & (dna >> 56);

    //convert dna segment to length in inches:
    float bits_to_inches_ratio = 10.2 / 255;
    float length_inches = length_bits * bits_to_inches_ratio;
    
    //evaluate
    if(length_inches >= 8) {
        cout << "DEBUG: coat_eval returns 0.1" << endl;
        return 0.1;
    }
    else if(length_inches >= 4) {
        cout << "DEBUG: coat_eval returns 0.05" << endl;
        return 0.05;
    }
    else {
        cout << "DEBUG: coat_eval returns 0.0" << endl;
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
 * @param long dna
 * 
 * NOT TESTED
 ***/
float eval_stiffness(long dna) {
    int stiffness = 0x3f & (dna >> 50);

    if(stiffness < 8) {
        cout << "DEBUG: coat_stiffness returns 0.1" << endl;
        return 0.1;
    }
    else if(stiffness < 57) {
        cout << "DEBUG: coat_stiffness returns 0.05" << endl;
        return 0.05;
    }
    else {
        cout << "DEBUG: coat_stiffness returns 0.0" << endl;
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
    size_t found = bg_color.find("white");
    if(found!=string::npos) {
        cout << "DEBUG: bg_color returns 0.1" << endl;
        return 0.1;
    }
    else {
        cout << "DEBUG: bg_color returns 0.0" << endl;
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
    size_t found = fg_color.find("brown");
    if(found!=string::npos) {
        cout << "DEBUG: fg_color returns 0.1" << endl;
        return 0.1;
    }
    else {
        cout << "DEBUG: fg_color returns 0.0" << endl;
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
    string paw_snip = p_color.substr(6, 6);
    size_t found = paw_snip.find("white");
    if(found!=string::npos) {
        cout << "DEBUG: paw_color returns 0.1" << endl;
        return 0.1;
    }
    else {
        cout << "DEBUG: paw_color returns 0.0" << endl;
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
    string tail_snip = t_color.substr(t_color.find_first_of(",") + 2, 6);
    size_t found = tail_snip.find("black");
    if(found!=string::npos) {
        cout << "DEBUG: tail_color returns 0.1" << endl;
        return 0.1;
    }
    else {
        cout << "DEBUG: tail_color returns 0.0" << endl;
        return 0.0;
    }
}

/***
 * eval_t_len_and_shape function
 * 
 * evaluates the dog's tail length and shape
 * to see how close it is to the softie
 * 
 * Desirable softie : 4 to 6 inches, straight-up
 * 
 * @returns float
 * @param long dna
 * NOT TESTED
 ***/
float eval_t_len_and_shape(long dna){
    float eval = 0.0;

    //snip dna segment:
    int tail_length = 0xff & (dna >> 28);
    int tail_shape = 0x3 & (dna >> 26);

    if(tail_length == 0){
        cout << "DEBUG: length returns 0.0" << endl;
        return eval;
    }
    float length_inches = tail_length * .1;

    if(length_inches >= 4 && length_inches <= 6){
        cout << "DEBUG: length returns 0.05" << endl;
        eval += 0.05;
    }

    //evaluate the tail shape
    if(tail_shape == 0){
        cout << "DEBUG: shape returns 0.05" << endl;
        eval += 0.05;
    }
    else {
        cout << "DEBUG: shape returns 0.0" << endl;
    }

    return eval;

}

/***
 * eval_weight function
 * 
 * evaluates the dog's weight
 * to see how close it is to the softie
 * 
 * Desirable softie : 90+ kg
 * 
 * @returns float
 * @param long dna
 * NOT TESTED
 ***/
float eval_weight(long dna){

    int weight = 0x7f & (dna >> 19);
    int incremental_weight = 0x7 & (dna >> 16);
    float total = weight + (incremental_weight * 0.125);
    
   if(total >= 90){
        cout << "DEBUG: weight returns 0.1" << endl;
        return 0.1;
    }
    else{
        return (weight / 90) * 0.1;
    }
    
}

/***
 * eval_pp_area function
 * 
 * evaluates the dog's paw print area
 * to see how close it is to the softie
 * 
 * Desirable softie : Greater than 9 sq. in
 * 
 * @returns float
 * @param long dna
 * NOT TESTED
 ***/
float eval_pp_area(long dna){
    //snip dna segment:
    int area = 0x7f & (dna >> 9);
    
    //offset dna int by 0.5 sq inches:
    float area_inches = (area * 0.1) + 0.5;

    //evaluate
    if(area_inches > 9){
        return 0.1
    }
    else{
        return (area_inches / 9) * 0.1;
    }

}

/***
 * eval_webbing function
 * 
 * evaluates the dog's paw webbing percentage
 * to see how close it is to the softie
 * 
 * Desirable softie : Greater than 9 sq. in
 * 
 * @returns float
 * @param long dna
 * NOT TESTED
 ***/
float eval_webbing(long dna){
    //snip dna segment:
    int webbing = 0x7 & (dna >> 6);

    return (webbing / 7) * 0.1;

}

// TODO: float eval_temper(string temper);