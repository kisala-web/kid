#ifndef KIISALA_KID_KID_H_
#define KIISALA_KID_KID_H_

#include "id.h"
#include "pool.h"

namespace kiisala{

namespace kid{

    /**
     * @brief id池 提供完备的id池功能
     * 
     *  功能:
     *      1. 从id池申请id
     *      2. 将不使用的id返回给id池
     *      3. 自动调整容量(设置启用或者关闭)
     *      4. 手动调整容量
     *      5. 定制id池扩容和减容(提供从文件加载预先分配的id, 将id保存到文件中)
     * 
     */
    class KidPool;


}

}

#endif //KIISALA_KID_KID_H_