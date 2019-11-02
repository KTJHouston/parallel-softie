#include <iostream>
#include <string>

#include "DNA.h"

using namespace std;

int main(int argc, char** argv)
{
    long input = (long)0xffd3a << 44;
    DNA d = (input);
    cout << DNA::to_string(d) << endl;
}