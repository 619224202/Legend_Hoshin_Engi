//
//  ShowHelpScene.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2018/9/20.
//

#include "ShowHelpScene.hpp"
#include "MainMenuScene.hpp"

using namespace cocos2d;

//创建场景
Scene* ShowHelp::createScene(){
    Scene* scene = Scene::create();
    auto helpLayer = ShowHelp::create();
    scene->addChild(helpLayer);
    return scene;
}

bool ShowHelp::init(){
    if(!Layer::init()){
        return false;
    }
    Size winSize = Director::getInstance()->getWinSize();
    Vec2 origonSize = Director::getInstance()->getVisibleOrigin();
    Sprite* bgSprite = Sprite::create("bj/helpbeijing.png");
    bgSprite->setPosition(Vec2(origonSize.x+winSize.width/2,origonSize.y+winSize.height/2));
    this->addChild(bgSprite,0,1);
    
    MenuItemImage* close = MenuItemImage::create("bj/Exit.png", "bj/Exit.png", [&](Ref* sender){
       // this->Disappear();
        CCLog("CLOSE");
        ((MainMenuLayer*)(this->getParent()))->showMain(this);
    });
    
    close->setAnchorPoint(Vec2(1,1));
    close->setPosition(Vec2(origonSize.x+winSize.width/2,origonSize.y+winSize.height/2));
    Menu* menu = Menu::create(close, NULL);
    menu->setVisible(true);
    this->addChild(menu,1,2);
    
    //火焰粒子
//    ParticleSystem* partical = ParticleFire::create();
//
//    partical->setPosition(Vec2(origonSize.x+winSize.width/2,origonSize.y+winSize.height/2));
//    addChild(partical,2,5);
    
    //粒子文件
    ParticleSystem* partical = ParticleSystemQuad::create("bj/fire.plist");
    partical->setPosition(Vec2(origonSize.x+winSize.width/2,origonSize.y+winSize.height/2));
    addChild(partical,2,5);
    
   // this->setScale(0);
    return true;
}

void ShowHelp::Appear(ActionInstant* func){
    ScaleTo* bgScale = ScaleTo::create(1.0f, 1.0);
    auto bgRotate = RotateBy::create(1.0f, 1800.f);
    //ActionInstant *func =CallFunc::create(CC_CALLBACK_0(ShowHelp::bgActionOverCallBack, this));
    this->runAction(Sequence::create(Spawn::create(bgScale,bgRotate,NULL),func, NULL));
    CCLOG("appear");
}

void ShowHelp::Disappear(ActionInstant* func){
    ScaleTo* bgScale = ScaleTo::create(1.0f, 0);
    auto bgRotate = RotateBy::create(1.0f, -1800.f)  ;
   // ActionInstant *func =CallFunc::create(CC_CALLBACK_0(ShowHelp::bgActionOverCallBack, this));
    this->runAction(Sequence::create(Spawn::create(bgScale,bgRotate,NULL),func, NULL));
    CCLOG("Disappear");
}


void ShowHelp::bgActionOverCallBack(){
    CCLOG("背景动画完成");
}
