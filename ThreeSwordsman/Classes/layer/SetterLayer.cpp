//
//  SetterLayer.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/30.
//

#include "SetterLayer.hpp"
#include "../config/PConfig.hpp"
#include "../config/tools/GameTools.hpp"
#include "ui/CocosGUI.h"
#include "HomePageLayer.hpp"

using namespace cocos2d::ui;

bool SetterLayer::init(){
    if(!Node::init()){
        return false;
    }
    _soundPersent = 20;
    GameTools* gameTools = GameTools::getInstance();
    gameTools->loadLanguageWidthScene("setter",true);
    //背景层
    LayerColor* layer = LayerColor::create(Color4B(25, 25, 25, 255));
    layer->setIgnoreAnchorPointForPosition(false);
    layer->setAnchorPoint(Vec2(0.5,0.5));
    layer->setPosition(Vec2(WINSIZE_W/6,WINSIZE_H*2/5));
    layer->setContentSize(Size(WINSIZE_W/3,WINSIZE_H*4/5));
    this->addChild(layer);
    //标题
    Label* titleLabel =Label::createWithSystemFont(GameTools::getInstance()->getValue("setTitle"),"MarkerFelt-Thin", 24);
    titleLabel->setAnchorPoint(Vec2(0.5,1));
    titleLabel->setPosition(Vec2(WINSIZE_W/6,WINSIZE_H*4/5-5));
    titleLabel->setVisible(true);
    this->addChild(titleLabel);
    //画线
    DrawNode* drawNode = DrawNode::create();
    drawNode->setLineWidth(10);
    drawNode->drawRect(Vec2(WINSIZE_W/3,WINSIZE_H*4/5), Vec2(0,0), Color4F(0.52f, 0.52f, 0.52f, 1.0f));
    drawNode->setLineWidth(3);
    drawNode->drawLine(Vec2(0,WINSIZE_H*4/5-40), Vec2(WINSIZE_W/3,WINSIZE_H*4/5-40), Color4F(0.52f, 0.52f, 0.52f, 1.0f));
    drawNode->drawLine(Vec2(0,WINSIZE_H*3/5-30), Vec2(WINSIZE_W/3,WINSIZE_H*3/5-30), Color4F(0.52f, 0.52f, 0.52f, 1.0f));
    drawNode->drawLine(Vec2(0,WINSIZE_H*2/5-20), Vec2(WINSIZE_W/3,WINSIZE_H*2/5-20), Color4F(0.52f, 0.52f, 0.52f, 1.0f));
    drawNode->drawLine(Vec2(0,WINSIZE_H*1/5-10), Vec2(WINSIZE_W/3,WINSIZE_H*1/5-10), Color4F(0.52f, 0.52f, 0.52f, 1.0f));
    drawNode->setVisible(true);
    
    initOpenSound();
    initChangeSound();
    initTextSpeed();
    initLanguage();
    //进度条
    
    this->addChild(drawNode);
    this->setContentSize(Size(WINSIZE_W/3,WINSIZE_H*4/5));
    
    this->setIgnoreAnchorPointForPosition(false);
    this->setAnchorPoint(Vec2(0.5,0.5));
    this->setPosition(WINSIZE_W/2,WINSIZE_H/2);
    
    this->setScale(0);
   
    
    
    
    return true;
}

void SetterLayer::show(){
    CallFunc* callFun = CallFunc::create(CC_CALLBACK_0(SetterLayer::endAction,this));
    this->runAction(Sequence::create(ScaleTo::create(0.3, 1.0,1.0),callFun, NULL));
}


void SetterLayer::endAction(){
    if(getParent()){
        Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(getParent());
    }
    EventListenerKeyboard* keyPressedListener = EventListenerKeyboard::create();
    keyPressedListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode,Event* event){
        this->doKeyPressed(keyCode,event);
    };
    Director::getInstance()->getEventDispatcher()
    ->addEventListenerWithSceneGraphPriority(keyPressedListener, this);
    
}

void SetterLayer::initOpenSound(){
    //开启声音
    Label* musicLabel = Label::createWithSystemFont(GameTools::getInstance()->getValue("setter1"), "MarkerFelt-Thin", 18);
    musicLabel->setPosition(5, WINSIZE_H*4/5-45);
    musicLabel->setAnchorPoint(Vec2(0,1));
    this->addChild(musicLabel);
    //开启
    RadioButtonGroup* soundRadioGroup = RadioButtonGroup::create();
    openSoundRadio = RadioButton::create("ui/CheckBoxButton2Off.png", "ui/CheckBoxButton2On.png",Widget::TextureResType::LOCAL);
    openSoundRadio->setPosition(Vec2(WINSIZE_W/12,WINSIZE_H*7/10-35));
    openSoundRadio->setAnchorPoint(Vec2(0.5,0.5));
    soundRadioGroup->addChild(openSoundRadio);
    Label* openLabel = Label::createWithSystemFont("开启", "MarkerFelt-Thin", 18);
    openLabel->setPosition(WINSIZE_W/12+30, WINSIZE_H*7/10-35);
    openLabel->setAnchorPoint(Vec2(0,0.5));
    openLabel->setTag(101);
    this->addChild(openLabel);
    
    closeSoundRadio = RadioButton::create("ui/CheckBoxButton2Off.png", "ui/CheckBoxButton2On.png",Widget::TextureResType::LOCAL);
    closeSoundRadio->setPosition(Vec2(WINSIZE_W/4,WINSIZE_H*7/10-35));
    closeSoundRadio->setAnchorPoint(Vec2(0.5,0.5));
    soundRadioGroup->addChild(closeSoundRadio);
    this->addChild(soundRadioGroup);
    Label* closeLabel = Label::createWithSystemFont("关闭", "MarkerFelt-Thin", 18);
    closeLabel->setPosition(WINSIZE_W/4+30, WINSIZE_H*7/10-35);
    closeLabel->setAnchorPoint(Vec2(0,0.5));
    closeLabel->setTag(102);
    this->addChild(closeLabel);
    openSoundRadio->setSelected(true);
    
    openSoundRadio->addTouchEventListener([&](Ref* ref,Widget::TouchEventType type){
        switch(type){
            case Widget::TouchEventType::BEGAN:
                break;
            case Widget::TouchEventType::ENDED:
                log("openSelect");
                closeSoundRadio->setSelected(false);
                break;
        }
    });
    closeSoundRadio->addTouchEventListener([&](Ref* ref,Widget::TouchEventType type){
        switch(type){
            case Widget::TouchEventType::BEGAN:
                break;
            case Widget::TouchEventType::ENDED:
                openSoundRadio->setSelected(false);
                break;
        }
    });
}

void SetterLayer::initChangeSound(){
    
    __String* str = __String::createWithFormat("%s  :   %d",GameTools::getInstance()->getValue("setter2").c_str(),_soundPersent);
    Label *label = Label::createWithSystemFont(str->getCString(), "MarkerFelt-Thin", 18);
    label->setPosition(5, WINSIZE_H*3/5-35);
    label->setAnchorPoint(Vec2(0,1));
    label->setTag(21);
    this->addChild(label);
    
    
    Slider* _soundSlider = Slider::create();
    _soundSlider->setTag(22);
    _soundSlider->setPercent(25);
    _soundSlider->setPosition(Vec2(WINSIZE_W/6,WINSIZE_H/2-25));
    _soundSlider->setAnchorPoint(Vec2(0.5,0.5));
    _soundSlider->setScale(1, 1.5);
//    _soundSlider->setScale(1);
    _soundSlider->loadProgressBarTexture("ui/sliderProgress.png");
    _soundSlider->loadBarTexture("ui/slider_bar.png");
    const Slider::ccSliderCallback _sliderCall = [&](Ref* ref,Slider::EventType eventType){
        SetterLayer::changeVoice(ref);
    };
    _soundSlider->addEventListener(_sliderCall);
    this->addChild(_soundSlider);
    _soundSlider->setTouchEnabled(true);
    _soundSlider->setVisible(true);
}

void SetterLayer::initTextSpeed(){
    Label* label = Label::createWithSystemFont(GameTools::getInstance()->getValue("setter3"), "MarkerFelt-Thin", 18);
    label->setPosition(5, WINSIZE_H*2/5-25);
    label->setAnchorPoint(Vec2(0,1));
    this->addChild(label);
    
    char* _name[3]={"慢","中","快"};
    vector<string> _nameV;
    for (int i=0; i<3; i++) {
        _nameV.push_back(_name[i]);
    }
    Rect rect;
    rect.origin = Vec2(0,WINSIZE_H*1/5-10);
    rect.size = Size(WINSIZE_W/3, WINSIZE_H/5);
    GameTools::getInstance()->createRadioGroup("ui/RadioButtonOff.png", "ui/RadioButtonOn.png","textSpeed", _nameV, CC_CALLBACK_1(SetterLayer::changeTextSpeed,this), this, rect, Vec2(1,1));
    
}

void SetterLayer::initLanguage(){
    Label* label = Label::createWithSystemFont(GameTools::getInstance()->getValue("setter4"), "MarkerFelt-Thin", 18);
    label->setPosition(5, WINSIZE_H*1/5-15);
    label->setAnchorPoint(Vec2(0,1));
    this->addChild(label);
    
    char* _name[2]={"英文","中文"};
    vector<string> _nameV;
    for(int i=0;i<2;i++){
        _nameV.push_back(_name[i]);
    }
    Rect rect;
    rect.origin = Vec2(0,0);
    rect.size = Size(WINSIZE_W/3,WINSIZE_H/5);
    GameTools::getInstance()->createRadioGroup("ui/RadioButtonOff.png", "ui/RadioButtonOn.png","language", _nameV, CC_CALLBACK_1(SetterLayer::changeLanguage,this), this, rect, Vec2(1,1));
}

void SetterLayer::changeVoice(Ref *ref){
    _soundPersent = static_cast<Slider*>(ref)->getPercent();
    log("soundPersent=%d",_soundPersent);
    
    __String* perStr = __String::createWithFormat("%s  :   %d",GameTools::getInstance()->getValue("setter2").c_str(),_soundPersent);
    Label* perLabel = static_cast<Label*>(getChildByTag(21)) ;
    perLabel->setString(perStr->getCString());
}

void SetterLayer::changeTextSpeed(Ref *ref){
    RadioButton* _radioButton = static_cast<RadioButton*>(ref);
    log("radioRag=%d",_radioButton->getTag());
}

void SetterLayer::changeLanguage(Ref *ref){
    RadioButton* _radioButton = static_cast<RadioButton*>(ref);
    log("radioRag=%d",_radioButton->getTag());
}

void SetterLayer::doKeyPressed(EventKeyboard::KeyCode keyCode
                               , Event *event){
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DPAD_CENTER:
        case EventKeyboard::KeyCode::KEY_ENTER:
            break;
        case EventKeyboard::KeyCode::KEY_DPAD_DOWN:
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            break;
        case EventKeyboard::KeyCode::KEY_DPAD_UP:
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            log("up");
            break;
        case EventKeyboard::KeyCode::KEY_DPAD_LEFT:
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_DPAD_RIGHT:
            break;
        case EventKeyboard::KeyCode::KEY_BACK:
        case EventKeyboard::KeyCode::KEY_RETURN:
        {
            Director::getInstance()->getEventDispatcher()
            ->removeEventListenersForTarget(this);
            if(getParent()){
                Director::getInstance()->getEventDispatcher()->resumeEventListenersForTarget(getParent());
            }
            CallFunc* callFun = CallFunc::create(CC_CALLBACK_0(SetterLayer::removeFromParent,this));
            this->runAction(Sequence::create(ScaleTo::create(0.5, 0,0),callFun, NULL));
        }
            break;
        case EventKeyboard::KeyCode::KEY_1:
            
        default:
            break;
    }
}
