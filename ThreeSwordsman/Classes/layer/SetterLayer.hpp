//
//  SetterLayer.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/30.
//

#ifndef SetterLayer_hpp
#define SetterLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;

class SetterLayer:public cocos2d::Layer{
public:
    //初始化
    virtual bool init();
    
    void initOpenSound();
    void initChangeSound();
    void initTextSpeed();
    void initLanguage();
    
    void endAction();
    void show();
    //
//    void doKeyPressed(EventKeyboard::KeyCode keyCode,Event* event);
//    void doTouched();
//    void openSound();
    void changeVoice(Ref* ref);
    void changeTextSpeed(Ref* ref);
    void changeLanguage(Ref* ref);
    CREATE_FUNC(SetterLayer);
    
    void doKeyPressed(EventKeyboard::KeyCode keyCode,Event* event);
    
private:
    RadioButton* openSoundRadio;
    RadioButton* closeSoundRadio;
    int _soundPersent;
    
};

#endif /* SetterLayer_hpp */
