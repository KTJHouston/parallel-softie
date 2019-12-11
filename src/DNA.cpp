#include "DNA.h"

/////////////////////////////////////////////////////////////////
// STATIC PRIVATE VARIABLES
/////////////////////////////////////////////////////////////////
bool DNA::seed_set = false;

/////////////////////////////////////////////////////////////////
// PUBLIC
/////////////////////////////////////////////////////////////////

/**
 * Constructor
 * 
 * Create a DNA object with a random sequence. 
 **/
DNA::DNA() {
    //set rand seed:
    if ( !seed_set ) {
        srand(time(0));
        seed_set = true;
    }

    //set sequence:
    this->dna = ((dna_t)(rand()) << 32) + rand();
}//end DNA() constructor

/**
 * Constructor
 * 
 * Create a DNA object with a specific sequence. 
 **/
DNA::DNA(dna_t dna) {
    //set rand seed:
    if ( !seed_set ) {
        srand(time(0));
        seed_set = true;
    }

    //set sequence:
    this->dna = dna;
}//end DNA(dna_t) constructor

/**
 * readable_coat_length
 *
 * Coat length is determined by first (most significant) 8 bits
 * in the dna sequence (bits 56 through 63). 00000000 is hairless. 
 * 11111111 is a coat of length 10.2 inches. 11001000 corresponds 
 * to 8 inches. 
 *
 **/
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
}//end readable_coat_length

/**
 * readable_stiffness
 *
 * Stiffness is determined by 6 bits (bits 50 through 55). 
 * 000000 corresponds to the ultimate in softness. 000111 is 
 * extremely soft. And, 111111 is ultimate sitffness. 
 *
 **/
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
    else if ( stiffness == 63 ) {
        output += "Ultimate stiff";
    }
    else if ( stiffness > 56 ) {
        output += "Extremely stiff";
    }
    else  {
        output += "More stiff than desirable";
    }
    return output;
}//end readable_stiffness

/**
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
 **/
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
}//end readable_background_color

/**
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
 **/
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
}//end readable_foreground_color


/**
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
 **/
string DNA::readable_paw_and_tail() {
    //snip dna segment:
    int paw = 0x1 & (dna >> 37);
    int tail = 0x1 & (dna >> 36);
    
    string binary_rep_paw = get_binary_representation(paw, 1);
    string binary_rep_tail = get_binary_representation(tail, 1);
    string output = "[" + binary_rep_paw + " " + binary_rep_tail + "] ";
    
    // Get paw color:
    if ( paw == 0 ) {
        output += "white paws, ";
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
}//end readable_paw_and_tail


/**
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
 **/
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

}//end readable_tail_length_and_shape

/**
 * readable_weight
 *
 * Weight is determined by 10 bits (bits 16 through 25).
 * The first seven (bits 19 through 25) = weight in kgs 
 * Add the last three (bits 16 through 18) = weight in increments of 1/8 kg.
 * 
 * 18 kg. Thus, a weight characteristic of 0000101011 would be a weight of 5 3/8 kg.
 **/
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
}//end readable_weight

/**
 * readable_pawprint_area
 *
 * Pawprint area is determined by 7 bits (bits 9 through 15):
 *   0000000 is 0.5 sq in. 
 *   1111111 is 13.2 sq in 
 *   0100011 is 4 sq in. 
 *
 **/
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
}//end readable_pawprint_area

/**
 * readable_webbing
 * 
 * Webbing is determined by 3 bits (bits 6 through 8). 
 * 000 is 1/8 webbed. 111 is fully webbed. And 011 is 
 * 1/2 webbed. 
 **/
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
}//end readable_webbing

/**
 * readable_temper
 * 
 * Temper is determined by 6 bits (bits 0 through 5). 
 * 000000 corresponds to the ultimate in mild-termpered-disposition. 
 * 000100 is extremely mild tempered. And, 111111 is "meaner than a 
 * junkyard dog" - the ultimate in non-mild-temperedness. 
 * 
 * The largest number still considered extremely mild tempered will 
 * be 000111 as to match stiffness. 
 **/
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
    else if ( temper == 63 ) {
        output += "Ultimate non-mild-temperedness";
    }
    else if ( temper > 56 ) {
        output += "Extremely unmild tempered";
    }
    else  {
        output += "Less mild tempered than desirable";
    }
    return output;

}//end readable_temper

/////////////////////////////////////////////////////////////////
// STATIC PUBLIC
/////////////////////////////////////////////////////////////////

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
}//end to_string

long DNA::to_number() {
    return this->dna;
}

/**
 * breed function
 * 
 * Breeds two dna sequences randomly. 
 * Has between [1, 5) crosses and 
 * between [0, 4) mutations. 
 * 
 * Look to the documentation of mutate 
 * and multipoint_crossover functions for 
 * definitions of a "cross" and a "mutation". 
 **/
DNA DNA::breed(DNA a, DNA b) {
    //get random number of crosses:
    int cut_num = rand_num(1, 5);

    //cross:
    dna_t child = multipoint_crossover(a.dna, b.dna, cut_num);

    //get random number of mutations:
    int mut_num = rand_num(0, 4);

    //mutate:
    mutate(child, mut_num);

    return DNA(child);
}//end breed


/////////////////////////////////////////////////////////////////
// STATIC PRIVATE
/////////////////////////////////////////////////////////////////

/**
 * get_binary_representation
 * 
 * Will return a binary representation of the input value in a string. 
 * The number of bits to print must be 1 <= bit_count <= 10. 
 **/
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
}//end get_binary_representation

/**
 * rand_num function
 * 
 * Returns a random integer [start, end).
 **/
int DNA::rand_num(int start, int end) {
    int diff = end - start;
    int r = rand() % diff;
    r += start;
    return r;
}//end rand_num

/**
 * clip function
 * 
 * Returns only the bits of value between [start, end). 
 * Assumed that start <= end <= 64;
 **/
dna_t DNA::clip(dna_t value, int start, int end) {
    long s = 0xffffffffffffffff << start;
    long e;
    if (end == 64 ) {
        e = 0xffffffffffffffff;
    } else {
        e = 0x7fffffffffffffff >> (63 - end);
    }
    return (s & e) & value;
}//end clip

/**
 * multipoint_crossover function
 * 
 * Performs a multipoint crossover of the two dna 
 * sequences with a given number of cuts. The location 
 * of cuts are chosen by dividing the sequence into 
 * equally sized ranges. Each range will have a cut 
 * places randomly within it. 
 * 
 * A cross is when the bits of the new dna sequecne 
 * switch from originating from one parent to the other.   
 **/
dna_t DNA::multipoint_crossover(dna_t a, dna_t b, int cut_num) {
    //generate cross points:
    vector<int> cuts(cut_num);
    for (int i = 0; i < cut_num; i++) {
        int start = floor(i * 64 / cut_num);
        int end = floor((i+1) * 64 / cut_num);
        cuts[i] = rand_num(start, end);
    }

    //random pick starting sequence:
    dna_t current = (rand_num(0, 2)) ? a : b;

    //splice new sequence:
    dna_t new_sequence = 0;
    int last_cut = 0;
    for (int i = 0; i <= cuts.size(); i++) {
        //determine end of clip:
        int clip_end;
        if (i == cuts.size()) {
            clip_end = 64;
        } else {
            clip_end = cuts[i];
        }

        //get clip:
        dna_t new_segment = clip(current, last_cut, clip_end);

        //add clip to new sequence:
        new_sequence = new_sequence | new_segment;

        //switch sequence:
        if (current == a) {
            current = b;
        } else {
            current = a;
        }

        //set last cut:
        last_cut = clip_end;
    }

    return new_sequence;
}//end multipoint_crossover

/**
 * mutate function
 * 
 * Flips a given number of bits. The bits chosen 
 * are entirely random, and there is no attempt 
 * made to spread them evenly. Provided sequence 
 * is manipulated directly. 
 **/
void DNA::mutate(dna_t &seq, int mut_num) {
    vector<int> already_flipped = {};
    for (int i = 0; i < mut_num; i++) {
        int to_flip = rand_num(0, 64);
        if ( !count(already_flipped.begin(), already_flipped.end(), to_flip) ) {
            //if not already flipped:
            dna_t to_xor = (long)(1) << to_flip;
            seq = seq ^ to_xor;
            already_flipped.push_back(to_flip);
        } else {
            //if already flipped:
            //try again:
            i--;
        }
    }
}
