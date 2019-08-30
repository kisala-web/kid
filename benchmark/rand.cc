#include "kid/src/kid.h"
#include <iostream>

#include <stdlib.h>
#include <time.h>
using namespace kiisala::kid;

using namespace std;

void rannnnd(){
    uint seed =  time(NULL);
    srand(seed);
    cout << "seed = " << seed << "\t";
    for (auto i = 0; i < 10; i++){
        cout << rand() << "\t";
    }
    cout << endl;
}

int main(){

    IDPool pool(new IDGenerator(IDRangeType::kNumber, 32), true);
    pool.ExpendPool(1);
    for (auto i =0 ; i < 1000 * 1000 * 10; i++){
        // cout << pool.ApplyId() << endl;
        pool.ApplyId();
    }

    return 0;
}