#ifndef KIISALA_KID_POOL_H_
#define KIISALA_KID_POOL_H_

#include <string>
#include <set>
#include <queue>

#include "id.h"

namespace kiisala::kid{
    class IDResult{
    public:
        explicit IDResult(const std::string &str)
            : str_(str), status_(true) {}

        explicit IDResult(bool status, const std::string &str = "")
            : status_(status), str_(str) {}

        bool Valid() const{
            return status_;
        }
        const std::string String(){
            if (status_){
                return str_;
            }else{
                return "";
            }
        }

    private:
        bool status_;
        const std::string str_;
    };
    class IDPool{
    public:
        explicit IDPool(IDGenerator *generator, bool auto_expand = false)
            : generator_(generator) , auto_expand_(auto_expand){}

        const std::string ApplyId();
        // 释放一个id
        void ReleaseId(const std::string &id);
        // 手动增减ID池
        void ExpendPool(int size);
        void ReducePool(int size);
        // 自动增减ID池
        void AutoReduce();
        void AutoExpend();

    private:
        IDGenerator *generator_;
        std::queue<std::string> id_queue_;
        std::set<std::string> ids_;
        bool auto_expand_;
    };
}

#endif //KIISALA_KID_POOL_H_