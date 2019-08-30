#ifndef KIISALA_KID_ID_H_
#define KIISALA_KID_ID_H_

#include <string>
#include <stdlib.h>
#include <time.h>

namespace kiisala{

namespace kid{
    constexpr char numbers[] = {
        '0','1','2','3','4','5','6','7','8','9'
    };
    constexpr char lowers[] = {
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    constexpr char uppers[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };
    constexpr char alphas[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    constexpr char lowers_numbers[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    constexpr char uppers_numbers[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };
    constexpr char number_alphas[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };    

enum IDRangeType{
    kNumber = 1 << 0,
    kLowerCase = 1 << 1,
    kUpperCase = 1 << 2,
    kNumLower = kNumber + kLowerCase,
    kNumUpper = kNumber + kUpperCase,
    kAlpha = kLowerCase + kUpperCase,
    kNumAlpha = kNumber + kLowerCase + kUpperCase,
};

/**
 * @brief ID生成库
 * 
 * 能够自由设定产生数的范围, 大小写字母及数字能够随意组合.
 * 
 * 注意, 在使用大小写字母和数字的时候, 其ID生成最大范围在字符串长度为10时, 就基本上接近了uint64的最大值,
 * 因此, 对于一些较大的范围, MaxSize()可能存在失效的问题.
 * 
 */
class IDGenerator{
public:
    IDGenerator(IDRangeType range, uint8_t length) 
        : range_(range), length_(length) {
            int size = 0;
            switch (range_){
            case IDRangeType::kNumber:{
                size = sizeof(numbers);
                break;
            }
            case IDRangeType::kLowerCase:{
                size = sizeof(lowers);
                break;
            }
            case IDRangeType::kUpperCase:{
                size = sizeof(uppers);
                break;
            }
            case IDRangeType::kNumLower:{
                size = sizeof(lowers_numbers);
                break;
            }
            case IDRangeType::kNumUpper:{
                size = sizeof(uppers_numbers);
                break;
            }
            case IDRangeType::kAlpha:{
                size = sizeof(alphas);
                break;
            }
            case IDRangeType::kNumAlpha:{
                size = sizeof(number_alphas);
                break;
            }
           
        }
         max_size_ = 1;
        for (auto i = 0; i < length; i++){
            max_size_ *= size;
        }
        srand((unsigned int)time(NULL));
    }

    virtual const std::string GetRandomString();
    const unsigned long long MaxSize() const{
        return max_size_;
    }
private:
    IDRangeType range_;
    const uint8_t length_;
    unsigned long long max_size_;
};

}


}


#endif //KIISALA_KID_ID_H_