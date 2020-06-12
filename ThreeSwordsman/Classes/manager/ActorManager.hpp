//
//  ActorManager.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2018/11/20.
//

#ifndef ActorManager_hpp
#define ActorManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <vector>


USING_NS_CC;

namespace ActorManager {
    //角色对象池
    template<class T>
    class ActorPool{
    public:
        ActorPool();
        ~ActorPool();
        //创建对象池
        void initPool(int minPoolLenth,int maxPoolLenth);
        
        //从对象池中获取对象
        T* getActor();
        
        //回收对象到对象池
        void retainActor(T* t);
        
        //清空对象池
        void clearPool();
    private:
        //对象池最少对象
        int minPoolLenth;
        //对象池最大对象
        int maxPoolLenth;
        //存储的对象列表
        Vector<T> poolVector;
    };
    

};


#endif /* ActorManager_hpp */
