#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "cocos2d.h"
#include "../config/EnumConstants.h"

USING_NS_CC;

struct EnemyInfo
{
	//血量
	int _maxHp;
	//能量
	int _maxMp;
	//攻击力
	int _atk;
	//防御力
	int _def;
	//暴击
	float _critical;
	//攻击type	远程或近战或魔法
	int _atkType;
	//携带经验值
	int _carryExp;
	//携带金币数量
	int _carryCoin;
	//携带道具id
	int* _carryPropIds;
	//攻击扫描范围 -1为全地图,0为进入地图后,范围为圆半径
	float _atkScanningRadius;
	//攻击范围,范围为圆半径
	float _atkRadius;
    //攻击间隔,毫秒
    int _atkInterval;
    //移动状态,只能站立，只能纵向移动，只能横向移动。斜着移动（即都存在），例如飞行轨迹
    int _moveType;
    //移动速度,为固定，以角色中心点到中心点的角度来计算横向速度和纵向速度
    int _moveSpeed;
    
    //怪物名字
    char* _name;
};

class Enemy : public cocos2d::Sprite
{
public:
    Enemy(EnemyInfo enemyInfo);
    ~Enemy();
	//初始化
	virtual bool init();
	//更新数据
	virtual void update();
	//扫描，怪物执行扫描操作
    void scanning();
    //移动
    void move();
    //攻击
    void doAtk();
    //死亡
    void doDead();
    //生成
    void doAppear();
    //AI
    void AI();
private:
	EnemyInfo enemyInfo;
	//当前血量
	int _nowHp;
	//最大能量,理论上是无限的
	int _nowMp;
	//当前攻击力
	int _nowAtk;
	//当前防御力
	int _nowDef;
	//x方向移动速度
	int _moveSpeedX;
	//y方向移动速度
	int _moveSpeedY;
};
#endif // !_ENEMY_H_
