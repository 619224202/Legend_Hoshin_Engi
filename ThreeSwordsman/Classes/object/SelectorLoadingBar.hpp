//
//  SelectorLoadingBar.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/7/7.
//

#ifndef SelectorLoadingBar_hpp
#define SelectorLoadingBar_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

using namespace cocos2d::ui;

class SelectorLoadingBar:public Node{
public:
    static SelectorLoadingBar* createWithOutUnder(char *loadingBarName,char *touchButtonName,
                                                  char *labelName);
    static SelectorLoadingBar* createWithOutLabel(char *underBarName,char *loadingBarName,
                                             char *touchButtonName);
    static SelectorLoadingBar* createWithAll(char *underBarName,char *loadingBarName,
                                             char *touchButtonName,char *labelName);
    static SelectorLoadingBar* createWithOutUL(char *loadingBarName,char *touchButtonName);
    bool init(char *underBarName,char *loadingBarName,
              char *touchButtonName,char *labelName);
    void setNodeAction(SEL_CallFuncN &selCallFun,Ref* ref);
    void chargeLoadingBar(int addLoading);
private:
    //百分比展示
    LoadingBar *_loadingBar;
    //拖动
    Sprite *_touchButton;
    
    SEL_CallFuncN _selCallFunN;
    Ref* ref;
};

#endif /* SelectorLoadingBar_hpp */
