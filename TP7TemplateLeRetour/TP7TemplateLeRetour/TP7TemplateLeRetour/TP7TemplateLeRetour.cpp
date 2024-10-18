// Tourenne - Audebert
// Vincent  - Dorine

#include <iostream>
#include "coopointer.h"

using namespace std;

int main()
{

    int* ip = new int(3);

    //coo::coopointer<int> c1;
    coo::coopointer<int> c2(ip);
    coo::coopointer<int> c3(c2);

    //cout << c1 << endl;

    std::cout << "Hello World!\n";
}
