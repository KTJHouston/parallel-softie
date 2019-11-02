#include "DNA.h"

/////////////////////////////////////////////////////////////////
// PUBLIC
/////////////////////////////////////////////////////////////////

DNA::DNA(dna_t dna)
{
    this->dna = dna;
}

/*
readable_coat_length

Coat length is determined by first (most significant) 8 bits
in the dna sequence. 00000000 is hairless. 11111111 is a coat 
of length 10.2 inches. 11001000 corresponds to 8 inches. 
*/
string DNA::readable_coat_length()
{
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

/*
readable_stiffness

Stiffness is determined by 6 bits (bits 50 through 55). 
000000 corresponds to the ultimate in softness. 000111 is 
extremely soft. And, 111111 is ultimate sitffness. 
*/
string DNA::readable_stiffness()
{
    //snip dna segment:
    int stiffness = 0x3f & (dna >> 50);
    
    //get binary representation of dna segment:
    string binary_rep = get_binary_representation(stiffness, 6);
    string output = "[" + binary_rep + "] ";

    //get stiffness description:
    if ( stiffness == 0 )
    {
        output += "Ultimate softness";
    }
    else if ( stiffness < 8 )
    {
        output += "Extremely soft";
    }
    else if ( stiffness == 0x3f )
    {
        output += "Ultimate stiff";
    }
    else if ( stiffness > 0x38 )
    {
        output += "Extremely stiff";
    }
    else 
    {
        output += "More stiff than desirable";
    }
    return output;
}

/*
readable_background_color

Background color is determined by 6 bits (bits 44 through 49). 
The most significant 3 bits are for brightness. And least 
significant 3 bits determine color. 

Brightness: 000 is bright. 111 is dark. 
Color: 
000 - White
001 - Brown
Else - Other
*/
string DNA::readable_background_color()
{
    //snip dna segment:
    int brightness = 0x7 & (dna >> 47);
    int color = 0x7 & (dna >> 44);
    
    //get binary representation of dna segment:
    string binary_rep_brightness = get_binary_representation(brightness, 3);
    string binary_rep_color = get_binary_representation(color, 3);
    string output = "[" + binary_rep_brightness + " " + binary_rep_color 
        + "] Background color is ";
    
    // Get brightness description:
    if ( brightness == 0 )
    {
        output += "Very bright ";
    }
    else if ( brightness == 7 )
    {
        output += "Very dark ";
    }
    else if ( brightness <= 3 )
    {
        output += "Bright ";
    }
    else if ( brightness >= 4 )
    {
        output += "Dark ";
    }

    // Get color description:
    if ( color == 0 )
    {
        output += "white";
    }
    else if ( color == 1 )
    {
        output += "brown";
    }
    else
    {
        output += "other";
    }
    
    return output;
}

/*
readable_foreground_color

Foreground color is determined by 6 bits (bits 44 through 49). 
The most significant 3 bits are for brightness. And least 
significant 3 bits determine color. 

Brightness: 000 is very bright. 111 is very dark. 
Color: 
000 - White
001 - Brown
010 - Red
011 - Yellow
111 - Black
Else - Other
*/
string DNA::readable_foreground_color(){
    //snip dna segment:
    int brightness = 0x7 & (dna >> 47);
    int color = 0x7 & (dna >> 44);
    
    //get binary representation of dna segment:
    string binary_rep_brightness = get_binary_representation(brightness, 3);
    string binary_rep_color = get_binary_representation(color, 3);
    string output = "[" + binary_rep_brightness + " " + binary_rep_color 
        + "] Background color is ";
    
    // Get brightness description:
    if ( brightness == 0 ){
        output += "Very bright ";
    }
    else if ( brightness == 7 ){
        output += "Very dark ";
    }
    else if ( brightness <= 3 ){
        output += "Bright ";
    }
    else if ( brightness >= 4 ){
        output += "Dark ";
    }

    // Get color description:
    if ( color == 0 ){
        output += "white";
    }
    else if ( color == 1 ){
        output += "brown";
    }
    else if ( color == 2 ){
        output += "red";
    }
    else if ( color == 3 ){
        output += "yellow";
    }
    else if ( color == 7 ){
        output += "black";
    }
    else{
        output += "other";
    }
    
    return output;
}

string DNA::to_string(DNA d)
{
    string output = "";
    output += d.readable_coat_length() + "\n";
    output += d.readable_stiffness() + "\n";
    output += d.readable_background_color();
    //TODO add other "readable" lines
    return output;
}

/////////////////////////////////////////////////////////////////
// PRIVATE
/////////////////////////////////////////////////////////////////

/*
get_binary_representation

Will return a binary representation of the input value in a string. 
The number of bits to print must be 1 <= bit_count <= 10. 
*/
string DNA::get_binary_representation(int value, int bit_count)
{
    //error check input:
    if (bit_count < 1 || bit_count > 10)
    {
        return "";
    }

    string output = "";
    int single_bit = 1 << (bit_count - 1);

    //iterates from most significant bit to least, appending to output
    for (int i = 0; i < bit_count; i++)
    {
        int and_val = value & single_bit;
        if (and_val == 0)
        {
            output += "0";
        }
        else
        {
            output += "1";
        }
        single_bit = single_bit >> 1;
    }

    return output;
}