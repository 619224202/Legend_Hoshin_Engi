//
//  HomePageLayer.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/23.
//

#ifndef HomePageLayer_hpp
#define HomePageLayer_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class HomePageLayer:public cocos2d::LayerColor{
public:
    static cocos2d::LayerColor* createLayer();
    
    HomePageLayer();
    
    ~HomePageLayer();
    //创建layer
    virtual bool init();
    
    virtual void pause(void);
    
    virtual void resume(void);
    
    //创建menu
    void initMenu();
    //选项操作
    void doClick(cocos2d::Ref* ref);
    //设置按键操作
    void doKeypressed(EventKeyboard::KeyCode keyCode,Event* enent);
    //按键释放
    void doKeyReleased(EventKeyboard::KeyCode keyCode,Event* enent);
    //设置触摸操作
    void doTouched();
    
    void menuItemSelect(int _menuIndex);
    
    void showExit();
    
    CREATE_FUNC(HomePageLayer);
    
private:
    MenuItem* menuItem[4];
    int menuIndex;
    int menuLenth;
    bool _isCanDo;
};


#endif /* HomePageLayer_hpp */
