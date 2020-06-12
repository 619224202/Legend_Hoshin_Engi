//
//  PConfig.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2018/9/18.
//

#ifndef PConfig_hpp
#define PConfig_hpp


#ifndef WINSIZE
#define WINSIZE         Director::getInstance()->getWinSize()
#define WINSIZE_W      (WINSIZE.width)
#define WINSIZE_H      (WINSIZE.height)
#define SHOW_SIZE_W     480
#define SHOW_SIZE_H     320
#define CScale_X        (WINSIZE_W/SHOW_SIZE_W)
#define CScale_Y        (WINSIZE_H/SHOW_SIZE_H)

#define ISFREE false

#define SetGameScale(object) \
    object->setAnchorPoint(Vec2(0.0f, 0.0f)); \
    object->setScaleX(CScale_X);\
    object->setScaleY(CScale_Y);
#endif

#define USE_KEYBORD true


#include <stdio.h>
#include "EnumConstants.h"

class PConfig{
public: //设置
    static TEXT_SPEED _e_text_speed;     //文本显示速度
    static bool _b_sound_open;          //声音是否开启
    static int _i_sound_per;            //声音百分比
    static TYPE_LANGUAGE _e_type_langu; //声音设置
    
    
};



#endif /* PConfig_hpp */
