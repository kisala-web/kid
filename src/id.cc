#include "id.h"
#include <random>
#include <iostream>
using std::string;

namespace kiisala::kid{

    const string IDGenerator::GetRandomString(){
        const char *array;
        int size;
        switch (range_){
            case IDRangeType::kNumber:{
                array = numbers;
                size = sizeof(numbers);
                break;
            }
            case IDRangeType::kLowerCase:{
                array = lowers;
                size = sizeof(lowers);
                break;
            }
            case IDRangeType::kUpperCase:{
                array = uppers;
                size = sizeof(uppers);
                break;
            }
            case IDRangeType::kNumLower:{
                array = lowers_numbers;
                size = sizeof(lowers_numbers);
                break;
            }
            case IDRangeType::kNumUpper:{
                array = uppers_numbers;
                size = sizeof(uppers_numbers);
                break;
            }
            case IDRangeType::kAlpha:{
                array = alphas;
                size = sizeof(alphas);
                break;
            }
            case IDRangeType::kNumAlpha:{
                array = number_alphas;
                size = sizeof(number_alphas);
                break;
            }
        }

        
        char chars[length_+1];
        // 将随机数种子初始化移动到构造函数中  
        // std::cout << "111" << std::endl;
        for (auto i = 0; i < length_; i++){
            
            int index = rand() % size;
            chars[i] = array[index]; // 建议预分配地址
        }
        chars[length_] = '\0';

        return string(chars);
    }

}