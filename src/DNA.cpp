#include "DNA.h"

/////////////////////////////////////////////////////////////////
// PUBLIC
/////////////////////////////////////////////////////////////////

DNA::DNA(dna_t dna) {
    this->dna = dna;
}

/***
 * readable_coat_length
 *
 * Coat length is determined by first (most significant) 8 bits
 * in the dna sequence (bits 56 through 63). 00000000 is hairless. 
 * 11111111 is a coat of length 10.2 inches. 11001000 corresponds 
 * to 8 inches. 
 *
 ***/
string DNA::readable_coat_length() {
    //snip dna segment:
    int length_bits = 0xff & (dna >> 56);

    //convert dna segment to length in inches:
    float bits_to_inches_ratio = 10.2 / 255;
    float length_inches = length_bits * bits_to_inches_ratio;
    
    //get binary representation of dna segment:
    string binary_rep = get_binary_representation(length_bits, 8);

    //limit precision of length in inches:
    stringstream ss;
    ss << setprecision(4) << length_inches;
    string inches_rep = ss.str();

    //build output string:
    string output = "[" + binary_rep + "] " + inches_rep + " in. coat";
    return output;
}

/***
 * readable_stiffness
 *
 * Stiffness is determined by 6 bits (bits 50 through 55). 
 * 000000 corresponds to the ultimate in softness. 000111 is 
 * extremely soft. And, 111111 is ultimate sitffness. 
 *
 ***/
string DNA::readable_stiffness() {
    //snip dna segment:
    int stiffness = 0x3f & (dna >> 50);
    
    //get binary representation of dna segment:
    string binary_rep = get_binary_representation(stiffness, 6);
    string output = "[" + binary_rep + "] ";

    //get stiffness description:
    if ( stiffness == 0 ) {
        output += "Ultimate softness";
    }
    else if ( stiffness < 8 ) {
        output += "Extremely soft";
    }
    else if ( stiffness == 0x3f ) {
        output += "Ultimate stiff";
    }
    else if ( stiffness > 0x38 ) {
        output += "Extremely stiff";
    }
    else  {
        output += "More stiff than desirable";
    }
    return output;
}

/***
 * readable_background_color
 *
 * Background color is determined by 6 bits (bits 44 through 49). 
 * The most significant 3 bits are for brightness. And least 
 * significant 3 bits determine color. 
 *
 * Brightness: 000 is bright. 111 is dark. 
 * Color: 
 *   000 - White
 *   001 - Brown
 *   Else - Other
 ***/
string DNA::readable_background_color() {
    //snip dna segment:
    int brightness = 0x7 & (dna >> 47);
    int color = 0x7 & (dna >> 44);
    
    //get binary representation of dna segment:
    string binary_rep_brightness = get_binary_representation(brightness, 3);
    string binary_rep_color = get_binary_representation(color, 3);
    string output = "[" + binary_rep_brightness + " " + binary_rep_color 
        + "] Background color is ";
    
    // Get brightness description:
    if ( brightness == 0 ) {
        output += "very bright ";
    }
    else if ( brightness == 7 ) {
        output += "very dark ";
    }
    else if ( brightness <= 3 ) {
        output += "bright ";
    }
    else if ( brightness >= 4 ) {
        output += "dark ";
    }

    // Get color description:
    if ( color == 0 ) {
        output += "white";
    }
    else if ( color == 1 ) {
        output += "brown";
    }
    else {
        output += "other";
    }
    
    return output;
}

/***
 * readable_foreground_color
 *
 * Foreground color is determined by 6 bits (bits 38 through 43). 
 * The most significant 3 bits are for brightness. And least 
 * significant 3 bits determine color. 
 *
 * Brightness: 000 is very bright. 111 is very dark. 
 * Color: 
 *    000 - White
 *    001 - Brown
 *    010 - Red
 *    011 - Yellow
 *    111 - Black
 *    Else - Other
 ***/
string DNA::readable_foreground_color() {
    //snip dna segment:
    int brightness = 0x7 & (dna >> 41);
    int color = 0x7 & (dna >> 38);
    
    //get binary representation of dna segment:
    string binary_rep_brightness = get_binary_representation(brightness, 3);
    string binary_rep_color = get_binary_representation(color, 3);
    string output = "[" + binary_rep_brightness + " " + binary_rep_color 
        + "] Foreground color is ";
    
    // Get brightness description:
    if ( brightness == 0 ) {
        output += "very bright ";
    }
    else if ( brightness == 7 ) {
        output += "very dark ";
    }
    else if ( brightness <= 3 ) {
        output += "bright ";
    }
    else if ( brightness >= 4 ) {
        output += "dark ";
    }

    // Get color description:
    if ( color == 0 ) {
        output += "white";
    }
    else if ( color == 1 ) {
        output += "brown";
    }
    else if ( color == 2 ) {
        output += "red";
    }
    else if ( color == 3 ) {
        output += "yellow";
    }
    else if ( color == 7 ) {
        output += "black";
    }
    else{
        output += "other";
    }
    
    return output;
}


/***
 * readable_paw_and_tail
 *
 * Paw color is determined by 1 bit (bit 37)
 *    0 : white
 *    1 : any other color
 *
 * Tail color is determined by 1 bit (bit 36)
 *    0 : any other color
 *    1 : black
 *
 ***/
string DNA::readable_paw_and_tail() {
    //snip dna segment:
    int paw = 0x1 & (dna >> 37);
    int tail = 0x1 & (dna >> 36);
    
    string binary_rep_paw = get_binary_representation(paw, 1);
    string binary_rep_tail = get_binary_representation(tail, 1);
    string output = "[" + binary_rep_paw + " " + binary_rep_tail + "] ";
    
    // Get paw color:
    if ( paw == 0 ) {
        output += "White paws, ";
    }
    else {
        output += "Any color paws, ";
    }

    // Get tail color:
    if ( tail == 1 ) {
        output += "black tail";
    }
    else {
        output += "any color tail";
    }
    
    return output;
}


/***
 * readable_tail_length_and_shape
 * 
 * Tail length is determined by 8 bits (bits 28 through 35):
 *     00000000 : tailless
 *     11111111 : tail of 25.5 inches or longer
 *     the remaining values are determined by the 
 *        formula (int * 0.1) = inches
 *
 * Tail appearance(shape) is determined by 2 bits (bits 26 and 27):
 *     00 : pointing straight up, 
 *     01 : pointing horizontally, 
 *     10 : pointing straight down, 
 *     11 : highly undesirable curly tailed appearance
 *
 ***/
string DNA::readable_tail_length_and_shape() {
    //snip dna segment:
    int tail_length = 0xff & (dna >> 28);
    int tail_shape = 0x3 & (dna >> 26);
    
    string binary_rep_length = get_binary_representation(tail_length, 8);
    string binary_rep_shape = get_binary_representation(tail_shape, 2);
    string output = "[" + binary_rep_length + " " + binary_rep_shape + "] ";

    if( tail_length == 0) {
        output += "tailless";
        return output;
    }
    else {
        //convert dna segment to length in inches:
        float length_inches = tail_length * .1;
        
        //limit precision of length in inches:
        stringstream ss;
        ss << setprecision(4) << length_inches;
        string inches_rep = ss.str();

        //build output string:
        output += inches_rep + " in. long, ";
        
        // Get shape description:
        switch(tail_shape) {
            case 0:
                output += "straight-up";
                break;
            case 1:
                output += "horizontal";
                break;
            case 2:
                output += "straight-down";
                break;
            case 3:
                output += "curly tailed";
                break;
            default:
                output += "UNDEFINED";
                break;
        }
    }
    return output;

}

/***
 * readable_weight
 *
 * Weight is determined by 10 bits (bits 16 through 25).
 * The first seven (bits 19 through 25) = weight in kgs 
 * Add the last three (bits 16 through 18) = weight in increments of 1/8 kg.
 * 
 * "18 kg. Thus, a weight characteristic of 0000101011 would be a weight of 5 3/8 kg."
 ***/
string DNA::readable_weight() {
    //snip dna segment:
    //TODO: fix these segments so the values are properly grabbed
    int weight = 0x7f & (dna >> 19);
    int incremental_weight = 0x7 & (dna >> 16);
    
    string binary_rep_weight = get_binary_representation(weight, 7);
    string binary_rep_inc_weight = get_binary_representation(incremental_weight, 3);
    string output = "[" + binary_rep_weight + binary_rep_inc_weight + "] ";
    
    float total = weight + (incremental_weight * 0.125);
    
    stringstream ss;
    ss << setprecision(4) << total;
    string kgs_rep = ss.str();

    output += kgs_rep + " kg weight";

    return output;
}

/***
 * readable_pawprint_area
 *
 * Pawprint area is determined by 7 bits (bits 9 through 15):
 *   0000000 is 0.5 sq in. 
 *   1111111 is 13.2 sq in 
 *   0100011 is 4 sq in. 
 *
 ***/
string DNA::readable_pawprint_area() {
    //snip dna segment:
    int area = 0x7f & (dna >> 9);
    
    //offset dna int by 0.5 sq inches:
    float area_inches = (area * 0.1) + 0.5;
    
    //get binary representation of dna segment:
    string binary_rep = get_binary_representation(area, 7);

    //limit precision of length in inches:
    stringstream ss;
    ss << setprecision(4) << area_inches;
    string inches_rep = ss.str();

    //build output string:
    string output = "[" + binary_rep + "] " + inches_rep + " sq. in. pawprint area";

    return output;
}

/***
 * readable_webbing
 *
 * Webbing is determined by 3 bits (bits 6 through 8). 
 * 000 is 1/8 webbed. 111 is fully webbed. And 011 is 
 * 1/2 webbed. 
 ***/
string DNA::readable_webbing() {
    //snip dna segment:
    int webbing = 0x7 & (dna >> 6);
    
    //get binary representation of dna segment:
    string binary_rep = get_binary_representation(webbing, 3);
    string output = "[" + binary_rep + "] ";

    switch(webbing) {
        case 0:
            output += "1/8";
            break;
        case 1:
            output += "25 percent";
            break;
        case 2:
            output += "3/8";
            break;
        case 3:
            output += "50 percent";
            break;
        case 4:
            output += "5/8";
            break;
        case 5:
            output += "75 percent";
            break;
        case 6:
            output += "7/8";
            break;
        case 7:
            output += "100 percent";
            break;
    }
    output += " webbed";

    //get stiffness description:
    return output;
}

/***
 * readable_temper
 *
 * Temper is determined by 6 bits (bits 0 through 5). 
 * 000000 corresponds to the ultimate in mild-termpered-disposition. 
 * 000100 is extremely mild tempered. And, 111111 is "meaner than a 
 * junkyard dog" - the ultimate in non-mild-temperedness. 
 *
 * The largest number still considered extremely mild tempered will 
 * be 000111 as to match stiffness. 
 ***/
string DNA::readable_temper() {
    //snip dna segment:
    int temper = 0x3f & dna;
    
    //get binary representation of dna segment:
    string binary_rep = get_binary_representation(temper, 6);
    string output = "[" + binary_rep + "] ";

    //get temper description:
    if ( temper == 0 ) {
        output += "Ultimate mild-temperedness";
    }
    else if ( temper < 8 ) {
        output += "Extremely mild tempered";
    }
    else if ( temper == 0x3f ) {
        output += "Ultimate non-mild-temperedness";
    }
    else if ( temper > 0x38 ) {
        output += "Extremely unmild tempered";
    }
    else  {
        output += "Less mild tempered than desirable";
    }
    return output;

}

string DNA::to_string(DNA d) {
    string output = "";
    output += d.readable_coat_length() + "\n";
    output += d.readable_stiffness() + "\n";
    output += d.readable_background_color() + "\n";
    output += d.readable_foreground_color() + "\n";
    output += d.readable_paw_and_tail() + "\n";
    output += d.readable_tail_length_and_shape() + "\n";
    output += d.readable_weight() + "\n";
    output += d.readable_pawprint_area() + "\n";
    output += d.readable_webbing() + "\n";
    output += d.readable_temper();
    return output;
}

/////////////////////////////////////////////////////////////////
// PRIVATE
/////////////////////////////////////////////////////////////////

/***
 * get_binary_representation
 *
 * Will return a binary representation of the input value in a string. 
 * The number of bits to print must be 1 <= bit_count <= 10. 
 ***/
string DNA::get_binary_representation(int value, int bit_count) {
    //error check input:
    if (bit_count < 1 || bit_count > 10) {
        return "";
    }

    string output = "";
    int single_bit = 1 << (bit_count - 1);

    //iterates from most significant bit to least, appending to output
    for (int i = 0; i < bit_count; i++) {
        int and_val = value & single_bit;
        if (and_val == 0) {
            output += "0";
        }
        else {
            output += "1";
        }
        single_bit = single_bit >> 1;
    }

    return output;
}