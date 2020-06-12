//
//  ShowHelpScene.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2018/9/20.
//

#ifndef ShowHelpScene_hpp
#define ShowHelpScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class ShowHelp:public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void Appear(cocos2d::ActionInstant* func=NULL);
    void Disappear(cocos2d::ActionInstant* func=NULL);
    
    void bgActionOverCallBack();
    
    CREATE_FUNC(ShowHelp);
    
private:
    int h_pageIndex;
};

#endif /* ShowHelpScene_hpp */
