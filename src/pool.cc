#include "pool.h"

#include <iostream>

using std::string;

namespace kiisala::kid{

const string IDPool::ApplyId(){
    // 计算剩余容量
    
    if (id_queue_.size() == 0){
        if (auto_expand_) {
            // 自动扩容
            try{
                AutoExpend();
                const string id = id_queue_.front();
                id_queue_.pop();
                return id;
            }catch (std::exception &e){
                throw e;
            }
        }else {
            return "不存在空闲ID";
        }
        
    }else{

        const string id = id_queue_.front();
        id_queue_.pop();
        return id;
    }

}

void IDPool::ReleaseId(const std::string &id){
    ids_.emplace(id);
    id_queue_.push(id);
}

void IDPool::AutoExpend(){
    unsigned int size = ids_.size()+1;
    unsigned int max_size = generator_->MaxSize() - ids_.size();
    size = size > max_size? max_size : size;
    if (size < 1){
        throw std::exception();
    }
    ExpendPool(size);

}
void IDPool::AutoReduce(){
}


void IDPool::ExpendPool(int size){
    for (auto i = 0 ; i < size; i++){
        
        bool ok = false;
        do {

            // std::cout << "222" << std::endl;
            string id = generator_->GetRandomString();
            // std::cerr << id << std::endl;
            auto old_size = ids_.size();
            ids_.emplace(id);
            auto new_size = ids_.size();
            if (new_size - old_size == 1){
                id_queue_.push(id);
                ok = true;
            }
        }while(!ok);
                    
                    
    }
}


} //namespace kiisala::kid