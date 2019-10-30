#include "DNA.h"

/////////////////////////////////////////////////////////////////
// PUBLIC
/////////////////////////////////////////////////////////////////

DNA::DNA(dna_t dna)
{
    this->dna = dna;
}

{

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
