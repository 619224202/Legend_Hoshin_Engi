//
//  SelectorLoadingBar.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/7/7.
//

#include "SelectorLoadingBar.hpp"

SelectorLoadingBar* SelectorLoadingBar::createWithAll(char *underBarName
                                                      , char *loadingBarName
                                                      , char *touchButtonName
                                                      , char *labelName){
    SelectorLoadingBar* _nodeBar = new (std::nothrow)SelectorLoadingBar();
    if(_nodeBar &&
       _nodeBar->init(underBarName,loadingBarName,touchButtonName,labelName)){
        _nodeBar->autorelease();
        return _nodeBar;
    }else{
        delete  _nodeBar;
        _nodeBar = nullptr;
        return nullptr;
    }
}


SelectorLoadingBar* SelectorLoadingBar::createWithOutUnder(char *loadingBarName
                                                           , char *touchButtonName
                                                           , char *labelName){
    return SelectorLoadingBar::createWithAll(nullptr, loadingBarName
                                      , touchButtonName
                                      , labelName
                                      );
}

SelectorLoadingBar* SelectorLoadingBar::createWithOutLabel(char *underBarName
                                       , char *loadingBarName
                                       , char *touchButtonName){
    return SelectorLoadingBar::createWithAll(underBarName
                                             , loadingBarName
                                             , touchButtonName
                                             , nullptr);
}

SelectorLoadingBar* SelectorLoadingBar::createWithOutUL(char *loadingBarName
                                                        , char *touchButtonName){
    return SelectorLoadingBar::createWithAll(nullptr
                                             , loadingBarName
                                             , touchButtonName
                                             , nullptr);
}

bool SelectorLoadingBar::init(char *underBarName
                              , char *loadingBarName
                              , char *touchButtonName
                              , char *labelName){
    if(!Node::init()){
        return false;
    }
    if(underBarName){
        Sprite* sprite = Sprite::create(underBarName);
        sprite->setAnchorPoint(Vec2(0,0.5));
        sprite->setTag(1);
        this->addChild(sprite);
    }
    _loadingBar = LoadingBar::create(loadingBarName);
    _loadingBar->setAnchorPoint(Vec2(0,0.5));
    _loadingBar->setTag(2);
    _loadingBar->setPercent(0);
    _loadingBar->addTouchEventListener([&](Ref* ref,Widget::TouchEventType touchEventType){
        Point beginPoint;
        switch (touchEventType) {
            case Widget::TouchEventType::BEGAN:
            {
                Vec2 beginVec2=_loadingBar->getTouchBeganPosition();
                
                log("begin X=%f,y=%f",beginVec2.x,beginVec2.y);
            }
                break;
            case Widget::TouchEventType::MOVED:
            {
                Vec2 beginVec2=_loadingBar->getTouchMovePosition();
                
                log("move X=%f,y=%f",beginVec2.x,beginVec2.y);
            }
                break;
            case Widget::TouchEventType::ENDED:
            {
                Vec2 beginVec2=_loadingBar->getTouchEndPosition();
                
                log("end X=%f,y=%f",beginVec2.x,beginVec2.y);
            }
                break;
            case Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
        }
    });
    return true;
}

void SelectorLoadingBar::setNodeAction(SEL_CallFuncN &callFunN,Ref* ref){
    
}

void SelectorLoadingBar::chargeLoadingBar(int addLoading){
    
}
