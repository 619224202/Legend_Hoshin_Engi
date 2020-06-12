//
//  RectNode.cpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/26.
//

#include "RectNode.hpp"
using namespace Shape;

RectNode* RectNode::create(Point beginPoint, Point endPoint, Color4B color4B){
    RectNode* rectNode = new (std::nothrow)RectNode();
    if(rectNode && rectNode->init(beginPoint, endPoint, color4B)){
        rectNode->autorelease();
        return rectNode;
    }
    CC_SAFE_DELETE(rectNode);
    return rectNode;
}

RectNode::RectNode(){
    _bFill = false;
    _lineWidth = 1;
}

RectNode::~RectNode(){
    _beginPoint = nullptr;
    _endPoint = nullptr;
    _bFill = false;
}

bool RectNode::init(Point beginPoint, Point endPoint, Color4B color4B){
    if(!Node::init()){
        return false;
    }
    this->_beginPoint = beginPoint;
    this->_endPoint = endPoint;
    this->_drawColor = color4B;
    return true;
}

void RectNode::setFillColor(bool bFill,Color4B fillColor){
    this->_fillColor = fillColor;
    this->_bFill = bFill;
}

void RectNode::setLineWidth(int lineWidth){
    this->_lineWidth = lineWidth;
}

void RectNode::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags){
    Node::draw(renderer, transform, flags);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(_lineWidth);
    Point volPoint[4] = {Vec2(_beginPoint.x,_beginPoint.y),Vec2(_endPoint.x,_beginPoint.y),
        Vec2(_beginPoint.x,_endPoint.y),Vec2(_endPoint.x,_endPoint.y)};
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    if(_bFill){
        glColor4ub(_fillColor.r, _fillColor.g,_fillColor.b,_fillColor.a);
        glVertexPointer(2, GL_FLOAT, 0, volPoint);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }
    glColor4b(_drawColor.r, _drawColor.g, _drawColor.b, _drawColor.a);
    glVertexPointer(2, GL_FLOAT, 0, volPoint);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}

CircleNode* CircleNode::create(Point centerPoint
                               , int radius
                               , Color4B color4B){
    CircleNode* node = new (std::nothrow)CircleNode();
    if(node && node->init(centerPoint, radius, color4B)){
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return node;
}

bool CircleNode::init(Point centerPoint, int radius, Color4B color4B){
    if(!Node::init()){
        return false;
    }
    return true;
}

void CircleNode::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags){
    
}
