//
//  HomePageScene.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/23.
//

#include "HomePageScene.hpp"
#include "../layer/HomePageLayer.hpp"

cocos2d::Scene* HomePageScene::createScene(){
    Scene* scene =  HomePageScene::create();
    CCLOG("create scene");
    return scene;
}

bool HomePageScene::init(){
     CCLOG("init Scene");
    if(!Scene::init()){
        return false;
    }
    LayerColor* layer = HomePageLayer::createLayer();
   
    this->addChild(layer);
    return true;
}

void HomePageScene::showHpMenu(){
    
}

void HomePageScene::showSetter(){
    
}
