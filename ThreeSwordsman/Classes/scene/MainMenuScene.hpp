//
//  MainMenuScene.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2018/9/1.
//

#ifndef MainMenuScene_hpp
#define MainMenuScene_hpp

#include <stdio.h>
#include "PConfig.hpp"

using namespace cocos2d;

class MainMenuLayer:public cocos2d::Scene{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void showMain(cocos2d::Ref* pSender);
    void startGame(cocos2d::Ref* pSender);
    void showHelp(cocos2d::Ref* pSender);
    void showScore(cocos2d::Ref* pSender);
    void setGame(cocos2d::Ref* pSender);
    
    CREATE_FUNC(MainMenuLayer);
};


#endif /* MainMenuScene_hpp */
