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
    int length_bits = 0xff & (dna >> 56);
    float bits_to_inches_ratio = 10.2 / 255;
    float length_inches = length_bits * bits_to_inches_ratio;
    
    string binary_rep = get_binary_representation(length_bits, 8);
    stringstream ss;
    ss << setprecision(4) << length_inches;
    string inches_rep = ss.str();
    string output = "[" + binary_rep + "] " + inches_rep + " in. coat";
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

int main() {
    return 0;
}