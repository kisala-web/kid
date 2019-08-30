#ifndef UUID_H_
#define UUID_H_

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "../src/id.h"

class UUIDGeneral : public kiisala::kid::IDGenerator{
public:    
    UUIDGeneral() : IDGenerator(kiisala::kid::kAlpha, 32) {}
    const std::string  GetRandomString() override{
        return boost::uuids::to_string(genera());
    }
private:
    boost::uuids::random_generator genera = boost::uuids::random_generator();
};


#endif //UUID_H_

#include "kid/src/pool.h"

#include <iostream>
#include <string>
#include <set>
using namespace std;
using namespace kiisala::kid;

int main(){
    IDPool pool(new UUIDGeneral(), true);
    pool.ExpendPool(1);
    for (auto i =0 ; i < 1000 * 1000 * 10; i++){
        // cout << pool.ApplyId() << endl;
        pool.ApplyId();
    }
    // cout << genera() << endl;
}