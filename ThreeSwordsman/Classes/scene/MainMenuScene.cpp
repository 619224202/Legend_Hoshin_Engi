//
//  MainMenuScene.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2018/9/1.
//

#include "MainMenuScene.hpp"
#include "ShowHelpScene.hpp"
#include "../config/PConfig.hpp"

USING_NS_CC;

using namespace cocos2d;

Scene* MainMenuLayer::createScene(){
    Scene* scene = Scene::create();
    
    //首页
    auto layer = MainMenuLayer::create();
    SetGameScale(layer);
    scene->addChild(layer,1,1);
    
    //帮助页面放入到首页层中
    auto helpLayer = ShowHelp::create();
    //SetGameScale(helpLayer);
    layer->addChild(helpLayer,2,2);
    helpLayer->setVisible(false);
    return scene;
}

bool MainMenuLayer::init(){
    if(!Scene::init()){
        return false;
    }
    //首页层
    Layer* mainLayer = Layer::create();
    SetGameScale(mainLayer);
    this->addChild(mainLayer,0,1);
    //首页层详细情况
    Sprite* bgSprite = Sprite::create("bj/beijing.png");
    mainLayer->addChild(bgSprite,0,1);
    bgSprite->setAnchorPoint(Vec2(0,0));
    
    MenuItemImage* menuItemImg1 = MenuItemImage::create("bj/start.png", "bj/start.png", CC_CALLBACK_1(MainMenuLayer::startGame,this));
    menuItemImg1->setPosition(Vec2(SHOW_SIZE_W+110, 300));
    auto moveTo1 = EaseOut::create( MoveTo::create(1.0f, Vec2(160,300)),3);
    menuItemImg1->runAction(moveTo1);
    
    MenuItemImage* menuItemImg2 = MenuItemImage::create("bj/scores.png","bj/scores.png",CC_CALLBACK_1(MainMenuLayer::showScore, this));
    menuItemImg2->setPosition(Vec2(SHOW_SIZE_W+70, 190));
    auto moveTo2 = EaseOut::create(MoveTo::create(1.0f, Vec2(160,190)),3);
    menuItemImg2->runAction(Sequence::create(DelayTime::create(0.5f),moveTo2, NULL));
    
    MenuItemImage* menuItemImg3 = MenuItemImage::create("bj/help.png","bj/help.png",CC_CALLBACK_1(MainMenuLayer::showHelp, this));
    menuItemImg3->setPosition(Vec2(SHOW_SIZE_W+70, 120));
    auto moveTo3 = EaseOut::create(MoveTo::create(1.0f, Vec2(160,120)),3);
    menuItemImg3->runAction(Sequence::create(DelayTime::create(1.0f),moveTo3, NULL));
    
    MenuItemImage* menuItemImg4 = MenuItemImage::create("bj/set.png","bj/set.png",CC_CALLBACK_1(MainMenuLayer::setGame, this));
    menuItemImg4->setPosition(Vec2(SHOW_SIZE_W+50, 60));
    auto moveTo4 = EaseOut::create(MoveTo::create(1.0f, Vec2(160,60)),3);
    menuItemImg4->runAction(Sequence::create(DelayTime::create(1.5f),moveTo4, NULL));
    
    Menu* menu = Menu::create(menuItemImg1,menuItemImg2,menuItemImg3,menuItemImg4, NULL);
    menu->setVisible(true);
    menu->setPosition(Vec2(0,0));
    menu->setAnchorPoint(Vec2(0,0));
    mainLayer->addChild(menu,2,2);
    
    //帮助层
    auto helpLayer = ShowHelp::create();
    //SetGameScale(helpLayer);
    this->addChild(helpLayer,2,2);
    helpLayer->setScale(0);
    helpLayer->setVisible(false);
    
    return true;
}

void MainMenuLayer::showMain(cocos2d::Ref *pSender){
    log("Disappear......");
    this->getChildByTag(1)->setVisible(true);
    if(getChildByTag(2)){
        auto callF=[&](){
            this->getChildByTag(2)->setVisible(false);
        };
        ActionInstant* callFun = CallFunc::create(callF);
        ((ShowHelp*)getChildByTag(2))->Disappear(callFun);
    }
}

void MainMenuLayer::startGame(cocos2d::Ref *pSender){
    log("beginGame");
}



void MainMenuLayer::showHelp(cocos2d::Ref *pSender){
    log("ShowHelp");
    getChildByTag(2)->setVisible(true);
    auto callF =[&](){
        this->getChildByTag(1)->setVisible(false);
    };
    ActionInstant* callFun = CallFunc::create(callF);
    ((ShowHelp *)(getChildByTag(2)))->Appear(callFun);
    
//    Scene* showHelpScene = ShowHelp::createScene();
//    Director::getInstance()->replaceScene(showHelpScene);
}


void MainMenuLayer::showScore(cocos2d::Ref *pSender){
    log("showScore");
}

void MainMenuLayer::setGame(cocos2d::Ref *pSender){
    log("setGame");
}
