//
//  GameTools.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/27.
//

#include "GameTools.hpp"
#include "cocos2d.h"
#include "../EnumConstants.h"
#include <tinyxml2/tinyxml2.h>
#include <stdio.h>
#include "string.h"

USING_NS_CC;
using namespace tinyxml2;
using namespace std;

GameTools* GameTools::toolInstance = nullptr;

GameTools* GameTools::getInstance(){
    if(!toolInstance){
        toolInstance = new GameTools();
    }
    return toolInstance;
}

GameTools::GameTools(){
    _language = TYPE_LANGUAGE::LANGUAGE_ZH;
    //_sceneName = malloc(16);
}

GameTools::~GameTools(){
    delete toolInstance;
    toolInstance = nullptr;
}

void GameTools::loadLanguageWidthScene(const char *sceneName,bool isAdd){
//    char *fileName = (char*)malloc(30*sizeof(char));
    //负值名称
    //memset(_sceneName, '\0', sizeof(_sceneName));
    int lenth = sizeof(sceneName);
    log("name lenth=%d",lenth);
    _sceneName = (char*)malloc(sizeof(lenth));
    strcpy(_sceneName , sceneName);
    if(!isAdd && _textMap.size()>0){
        _textMap.clear();
    }
    char fileName[20] = "language";
    //char* reName;
    if(GameTools::_language==TYPE_LANGUAGE::LANGUAGE_EN){
        strcat(fileName,"_en.xml");
    }else{
        strcat(fileName, "_zh.xml");
    }
    std::string filePath = FileUtils::getInstance()->fullPathFromRelativeFile(fileName,"config/");
    auto document = new tinyxml2::XMLDocument();
    std::string fileData = FileUtils::getInstance()->getStringFromFile(filePath);
    log("data:%s",fileData.c_str());
    document->Parse(fileData.c_str());
    //language
    XMLElement* rootElement=document->RootElement();
    XMLElement* sceneElement = rootElement->FirstChildElement("scene");
    std::string data = sceneElement->Name();
    while(sceneElement){
        log("attribute:%s",sceneElement->Attribute("name"));
        if(strcmp(sceneElement->Attribute("name"), sceneName)==0){
            XMLElement* textElement = sceneElement->FirstChildElement("text");
            while(textElement){
                log("key:%s,value:%s",textElement->Attribute("key"),textElement->GetText());
                _textMap.insert(pair<string,string>(textElement->Attribute("key"),textElement->GetText()));
                textElement = textElement->NextSiblingElement();
            }
            break;
        }
        sceneElement = sceneElement->NextSiblingElement();
    }
    
    delete document;
    document = nullptr;
}

const string GameTools::getValue(const string &key){
    auto iter = _textMap.find(key);
    if(iter!=_textMap.end()){
        //return _textMap[key];
        return iter->second;
    }
    return NULL;
}

void GameTools::createRadioGroup(const std::string &backUrl
                                 , const std::string &crossUrl,const char* groupName
                                 , vector<string> &_nameV
                                 , const fun_radioButtonDo &f_radioDo
                                 , cocos2d::Node *_pnode
                                 , const cocos2d::Rect rect,
                                 Vec2 scaleVec){
    RadioButtonGroup* radioGroup = RadioButtonGroup::create();
    float width = rect.size.width/_nameV.size();
    float centerX = rect.origin.x+width/2;
    float centerY = rect.origin.y+rect.size.height/2;
    log("x=%f,y=%f",centerX,centerY);
    this->f_m_radioDo = f_radioDo;
    for(int i=0;i<_nameV.size();i++){
        RadioButton* radio = RadioButton::create(backUrl, crossUrl,Widget::TextureResType::LOCAL);
        radio->setAnchorPoint(Vec2(0.5,0.5));
        radio->setPosition(Vec2(centerX,centerY));
        radio->setTag(i);
        radio->setScale(scaleVec.x, scaleVec.y);
        radioGroup->addChild(radio);
        radio->addTouchEventListener([&](Ref* ref,Widget::TouchEventType touchEvent){
            switch (touchEvent) {
                case Widget::TouchEventType::ENDED:
                    RadioButton* _radio = static_cast<RadioButton*>(ref);
                    RadioButtonGroup* _group = static_cast<RadioButtonGroup*>(_radio->getParent()) ;
                    for(Node* _node : _group->getChildren()){
                        static_cast<RadioButton*>(_node)->setSelected(false);
                    }
                    _radio->setSelected(true);
                    //node->scheduleOnce(_callFun,0.1);
                    GameTools::funRadionDo(ref);
                    break;
            }
        });
        
        Label* label = Label::createWithSystemFont(_nameV[i], "MarkerFelt-Thin", 18);
        label->setPosition(centerX+radio->getContentSize().width/2+5, centerY);
        label->setAnchorPoint(Vec2(0,0.5));
        label->setTag(100+i);
        _pnode->addChild(label);
        centerX = centerX+width;
    }
    static_cast<RadioButton*>(radioGroup->getChildByTag(0))->setSelected(true);
    radioGroup->setName(groupName);
    _pnode->addChild(radioGroup);
}

void GameTools::funRadionDo(Ref *ref){
    this->f_m_radioDo(ref);
}

