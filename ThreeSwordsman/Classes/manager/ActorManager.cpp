//
//  ActorManager.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2018/11/20.
//

#include "ActorManager.hpp"

using namespace ActorManager;

template <class T>
//默认长度为1-10;
ActorPool<T>::ActorPool(){
    minPoolLenth = 1;
    maxPoolLenth = 10;
}
template <class T>
ActorPool<T>::~ActorPool(){
    for(auto iter = poolVector.begin();iter!=poolVector.end();iter++){
        (*iter)->release();
    }
    poolVector.clear();
}

template <class T>
void ActorPool<T>::initPool(int minPoolLenth
                       , int maxPoolLenth){
    this->minPoolLenth = minPoolLenth;
    this->maxPoolLenth = maxPoolLenth;
    for(int i=0;i<minPoolLenth;i++){
        auto ref = new T();
        ref->autorelease();
        ref->retain();
        poolVector.pushBack(ref);
    }
}

template <class T>
T* ActorPool<T>::getActor(){
    if(poolVector.empty()){
        initPool(1, 10);
    }
    auto ref = poolVector.back();
    
    poolVector.popBack();
    return ref;
}

//将对象放回到c对象池中
template <class T>
void ActorPool<T>::retainActor(T* t){
    if(!t){
        assert(false);
        return;
    }
    if(poolVector.size()>=1.5*maxPoolLenth){
        for(int i=0;i<maxPoolLenth/2;i++){
            auto backObj = poolVector.back();
            backObj->release();
            poolVector.popBack();
            delete backObj;
        }
    }
    t->retain();
    poolVector.pushBack(t);
}
