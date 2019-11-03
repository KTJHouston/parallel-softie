#include <iostream>
#include <string>

#include "DNA.h"

using namespace std;

int main(int argc, char** argv) {
    for (long i = 0; i < 64; i++) {
        long input = i;// << 50;
        DNA d = DNA(input);
        cout << d.readable_temper() << endl;
    }
    
    DNA d = DNA(8);
    cout << DNA::to_string(d) << endl;
}