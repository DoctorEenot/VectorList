#include <iostream>
#include "VectorList.h"

int main()
{
    VectorList<int> vlist(10000);


    for (int i = 0; i < 1000000; i++) {
        if (i % 10000 == 0) {
            vlist.enlarge();
        }
        vlist.set(i, i);
        
    }


    for (int i = 0; i < 1000000; i++) {
        int num = vlist.get(i);
        if (num != i) {
            std::cout << "WRONG NUMBER! " << i << std::endl;
            break;
        }
        //std::cout << num << std::endl;
    }
    return 0;
}