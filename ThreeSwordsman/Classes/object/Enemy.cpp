#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy(EnemyInfo enemyInfo){
    this->enemyInfo = enemyInfo;
    this->_nowHp = this->enemyInfo._maxHp;
    this->_nowMp = this->enemyInfo._maxMp;
    this->_nowAtk = this->enemyInfo._atk;
    this->_nowDef = this->enemyInfo._def;
    //如果移动速度大于0
    if(((this->enemyInfo._moveType|TYPE_MOVE::TYPE_MOVE_HORIZONTAL)!=0) && ((this->enemyInfo._moveType|TYPE_MOVE::TYPE_MOVE_VERTICAL)==0)){
        this->_moveSpeedX = this->enemyInfo._moveSpeed;
        this->_moveSpeedY = 0;
    }else if(((this->enemyInfo._moveType|TYPE_MOVE::TYPE_MOVE_HORIZONTAL)==0) && ((this->enemyInfo._moveType|TYPE_MOVE::TYPE_MOVE_VERTICAL)!=0)){
        this->_moveSpeedY = this->enemyInfo._moveSpeed;
        this->_moveSpeedX = 0;
    }else{      //后期具体计算
        this->_moveSpeedX = 0;
        this->_moveSpeedY = 0;
    }
}

Enemy::~Enemy(){
    
}

bool Enemy::init() {
	if (!Node::init()) {
		return false;
	}
	initWithFile("map/Player.png");
    return true;
}

void Enemy::update(){
    
}

void Enemy::doAtk(){
    
}

void Enemy::doAppear(){
    
}

void Enemy::doDead(){
    
}

void Enemy::move(){
    
}

void Enemy::scanning(){
    
}

void Enemy::AI(){
    
}
