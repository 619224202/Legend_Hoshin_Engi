//
//  BaseUINode.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/30.
//

#include "BaseUINode.hpp"

BaseUINode::BaseUINode(){
    _actionCall = nullptr;
    _bUseAction = false;
    _isSelect = false;
}

BaseUINode::~BaseUINode(){
    
}

bool BaseUINode::init(){
    if(!Node::init()){
        return false;
    }
    return true;
}

void BaseUINode::selected(){
    this->_isSelect = true;
}

void BaseUINode::unSelected(){
    this->_isSelect = false;
}

bool BaseUINode::isSelected(){
    return _isSelect;
}

void BaseUINode::doNodeAction(){
    if(_bUseAction){
        _actionCall(ref);
        return;
    }
    if(isSelected()){
        log("do click");
    }
}

void BaseUINode::setNodeAction(Node_ActionCall &actionCall
                               , cocos2d::Ref *psender){
    this->_actionCall = actionCall;
    this->ref = psender;
}
