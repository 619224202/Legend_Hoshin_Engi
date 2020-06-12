//
//  HomePageLayer.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/23.
//

#include "HomePageLayer.hpp"
#include "../config/PConfig.hpp"
#include "../config/EnumConstants.h"
#include "../object/RectNode.hpp"
#include "../config/tools/GameTools.hpp"
#include "SetterLayer.hpp"

using namespace Shape;

HomePageLayer::HomePageLayer(){
    LayerColor();
    menuIndex = 0;
}

HomePageLayer::~HomePageLayer(){
    int menuLenth = sizeof(menuItem)/sizeof(menuItem[0]);
    for (int i=0; i<menuLenth; i++) {
        menuItem[i] = nullptr;
    }
}

LayerColor* HomePageLayer::createLayer(){
    //LayerColor* layer = HomePageLayer::create(Color4B(64, 64, 64, 255));
    HomePageLayer * layer = new (std::nothrow) HomePageLayer();
    if(layer && layer->init() && layer->initWithColor(Color4B(64, 64, 64, 255)) )
    {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return layer;
}



bool HomePageLayer::init(){
    if(!LayerColor::init()){
        return false;
    }
    CCLOG("layer init");
    _isCanDo = false;
    GameTools* gameTools = GameTools::getInstance();
    gameTools->loadLanguageWidthScene("homepage");
    //构建题目
    Label* titleLabel = Label::createWithTTF(gameTools->getValue("title"), "fonts/Marker_Felt.ttf", 80);
    titleLabel->setTextColor(Color4B(196,196,196,255));
    titleLabel->setContentSize(Size(180, 72));
    titleLabel->setPosition(WINSIZE_W/2, WINSIZE_H);
    //titleLabel->setOpacity(0);
    this->addChild(titleLabel);
    
    
    FadeIn* fadeIn = FadeIn::create(2.0);
    ActionInterval* titleAction = Spawn::create(fadeIn,MoveTo::create(2.0f, Vec2(WINSIZE_W/2,WINSIZE_H*5/8)), NULL);
    titleLabel->runAction(Sequence::create(titleAction,CallFunc::create(CC_CALLBACK_0(HomePageLayer::initMenu, this)),NULL));
    MenuItemFont::setFontSize(16);
    std::string menuName[4]={gameTools->getValue("menu0"),gameTools->getValue("menu1"),
        gameTools->getValue("menu2"),gameTools->getValue("menu3")};
    for (int i=0; i<4; i++) {
       // MenuItemFont::setFontName(<#const std::string &name#>)
        menuItem[i] = MenuItemFont::create(menuName[i], CC_CALLBACK_1(HomePageLayer::doClick, this));
        static_cast<MenuItemFont*>(menuItem[i])->setFontName("黑体");
        //static_cast<MenuItemFont*>(menuItem[i])->setFontSize(12);
        menuItem[i]->setPosition(0,-22*i);
        menuItem[i]->setAnchorPoint(Vec2(0.5,0));
        if(menuIndex==i){
            menuItem[i]->setColor(Color3B(255, 255, 255));
        }else{
            menuItem[i]->setColor(Color3B(180, 180, 180));
        }
        menuItem[i]->setTag(MAIN_MENU_BUTTON::BUTTON_START_GAME+i);
    }
    Menu* menu = Menu::create(menuItem[0],menuItem[1],menuItem[2],menuItem[3], NULL);
    menu->setName("menu");
    menu->setVisible(false);
    menu->setAnchorPoint(Vec2(0.5,0));
    menu->setPosition(Vec2(WINSIZE_W/2, WINSIZE_H/4));
    
    menuLenth = sizeof(menuItem)/sizeof(menuItem[0]);
    this->addChild(menu);
    
    
    
    //绑定按键方法
    EventListenerKeyboard* keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode,Event* enent){
        this->doKeypressed(keyCode, enent);
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyListener, this);
    
    EventListenerKeyboard* keyRelesedListener = EventListenerKeyboard::create();
    keyRelesedListener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode,Event* event){
        this->doKeyReleased(keyCode, event);
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyRelesedListener, this);
    
    return true;
}

void HomePageLayer::initMenu(){
    Node* node=getChildByName("menu");
    node->setVisible(true);
    _isCanDo = true;
    CCLOG("node x=%f,y=%f",node->getPositionX(),node->getPositionY());
}

void HomePageLayer::doClick(cocos2d::Ref* ref){
    if(!_isCanDo){
        return;
    }
    MenuItemFont* fontItem =static_cast<MenuItemFont*>(ref);
    int tag = fontItem->getTag();
    menuItemSelect(tag-MAIN_MENU_BUTTON::BUTTON_START_GAME);
    switch (tag) {
        case MAIN_MENU_BUTTON::BUTTON_START_GAME:
            log("start Game");
            break;
        case MAIN_MENU_BUTTON::BUTTON_CONTINUE_GAME:
            log("continue Game");
            
            break;
        case MAIN_MENU_BUTTON::BUTTON_SETTER:
        {
            SetterLayer* setterLayer = SetterLayer::create();
            this->addChild(setterLayer);
            setterLayer->show();
        }
            break;
        case MAIN_MENU_BUTTON::BUTTON_EXIT:
#if (CC_TARGET_PLATFORM==CC_PLATFORM_MAC)
            exit(0);
#else if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
            showExit();
#endif
            break;
        default:
            break;
    }
}

void HomePageLayer::doKeypressed(EventKeyboard::KeyCode keyCode,Event* enent){
    if(!_isCanDo){
        return;
    }
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_DPAD_UP:
        case EventKeyboard::KeyCode::KEY_W:
            if(menuIndex==0){
                menuItemSelect(3);
            }else{
                menuItemSelect(menuIndex-1);
            }
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_DPAD_DOWN:
        case EventKeyboard::KeyCode::KEY_S:
            if(menuIndex==3){
                menuItemSelect(0);
            }else{
                menuItemSelect(menuIndex+1);
            }
            break;
        case EventKeyboard::KeyCode::KEY_ENTER:
        case EventKeyboard::KeyCode::KEY_DPAD_CENTER:
            doClick(menuItem[menuIndex]);
            break;
        default:
            break;
    }
}

void HomePageLayer::doKeyReleased(EventKeyboard::KeyCode keyCode, Event *enent){
    log("keyReleased %d",keyCode);
}

void HomePageLayer::doTouched(){
    
}

void HomePageLayer::menuItemSelect(int _menuIndex){
    if(_menuIndex==this->menuIndex){
        return;
    }
    this->menuIndex = _menuIndex;
    for (int i=0;i<menuLenth;i++) {
        menuItem[i]->unselected();
        menuItem[i]->setColor(Color3B(180, 180, 180));
    }
    menuItem[menuIndex]->setColor(Color3B(255, 255, 255));
    this->menuItem[menuIndex]->selected();
}

void HomePageLayer::showExit(){
    LayerColor* layerColor = LayerColor::create(Color4B(65,178,24,255), 150, 120);
    layerColor->setPosition(Vec2(WINSIZE_W/2,WINSIZE_H/2));
    layerColor->setAnchorPoint(Vec2(0.5,0.5));
   // Label* textLabel = Label::createWithTTF("是否退出游戏", <#const std::string &fontFilePath#>, <#float fontSize#>);
}

void HomePageLayer::pause(void){
    log("HomePageLayer::pause");
     //Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(this);
}

void HomePageLayer::resume(void){
    log("HomePageLayer::resume");
    Director::getInstance()->getEventDispatcher()->resumeEventListenersForTarget(this);
}
