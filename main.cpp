#include <iostream>
#include "snowman.hpp"
#include <unistd.h>
#include <stdexcept>

using namespace std;
using namespace ariel;

int main() {

    for(int i=11111111 ; i<=44444444 ; i++)
    {
        try
        {
            cout << snowman(i) << endl;
        }
        catch(out_of_range)
        {
            continue;
        }
    }
    return 0;

}
