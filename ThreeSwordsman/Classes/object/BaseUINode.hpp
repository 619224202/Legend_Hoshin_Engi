//
//  BaseUINode.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/30.
//

#ifndef BaseUINode_hpp
#define BaseUINode_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
typedef std::function<void(cocos2d::Ref*)> Node_ActionCall;
class BaseUINode:cocos2d::Node{
public:
    BaseUINode();
    ~BaseUINode();
    virtual bool init();
    
    void selected();
    void unSelected();
    bool isSelected();
    //选中点击时执行的事件
    virtual void doNodeAction();
    //外部传人时执行的点击事件
    void setNodeAction(Node_ActionCall &actionCall,cocos2d::Ref* psender);
private:
    Node_ActionCall _actionCall;
    bool _bUseAction;
    bool _isSelect;
    Ref* ref;
};

#endif /* BaseUINode_hpp */
