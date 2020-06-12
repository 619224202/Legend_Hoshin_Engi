//
//  HomePageScene.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/23.
//

#ifndef HomePageScene_hpp
#define HomePageScene_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class HomePageScene:public cocos2d::Scene{
public:
    //创建scene
    static cocos2d::Scene* createScene();
    //初始化
    virtual bool init();
    
    void showSetter();
    
    void showHpMenu();
    
    CREATE_FUNC(HomePageScene);
};

#endif /* HomePageScene_hpp */
