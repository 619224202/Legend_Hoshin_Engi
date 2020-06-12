//
//  RectNode.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/26.
//

#ifndef RectNode_hpp
#define RectNode_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
namespace Shape {
    class RectNode: public cocos2d::Node{
    public:
        RectNode();
        ~RectNode();
        static RectNode* create(Point beginPoint,Point endPoint,Color4B color4B);
        bool init(Point beginPoint,Point endPoint,Color4B color4B);
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
        void setFillColor(bool bFill,Color4B fillColor);
        void setLineWidth(int lineWidth);
    private:
        Point _beginPoint;
        Point _endPoint;
        Color4B _drawColor;
        Color4B _fillColor;
        bool _bFill;
        int _lineWidth;
    };
    
    class CircleNode: public cocos2d::Node{
    public:
        static CircleNode* create(Point centerPoint,int radius,Color4B color4B);
        bool init(Point centerPoint,int radius,Color4B color4B);
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    private:
        Point _centerPoint;
        int _radius;
        Color4B _color4B;
    };
}




#endif /* RectNode_hpp */
