#pragma once

enum MAIN_MENU_BUTTON{
    BUTTON_START_GAME       = 20,               //开始游戏按钮
    BUTTON_CONTINUE_GAME    ,               //继续游戏按钮
    BUTTON_SETTER           ,               //设置
    BUTTON_EXIT             ,               //r退出
};

enum TYPE_ATK
{
	TYPE_ATK_NO,					//无攻击
	TYPE_ATK_CLOSE_COMBAT,			//近战
	TYPE_ATK_REMOTE_ATTACK,			//远程攻击
	TYPE_ATK_MAGIC_ATTACK,			//魔法攻击
};

enum TYPE_MOVE{
    TYPE_MOVE_STAND = 2,                //站立不动
    TYPE_MOVE_HORIZONTAL = 4,           //横向
    TYPE_MOVE_VERTICAL = 8,             //纵向
    TYPE_MOVE_TELEPORT = 16,             //瞬移
};

enum TYPE_LANGUAGE{
    LANGUAGE_EN = 1,                    //英文
    LANGUAGE_ZH = 2,                    //中文
    
};

//设置界面
enum SETTER{
    SETTER_OPENSOUND,                   //声音开启关闭
    SETTER_SOUND,                       //声音大小设置
    SETTER_TEXTSPEED,                   //对话文字速度设置
    SETTER_LANGUAGE,                    //中英文设置
};

enum TEXT_SPEED{
    TEXT_SPEED_QUICK,                   //文本速度 快
    TEXT_SPEED_NORMAL,                  //文本速度 一般
    TEXT_SPEED_SLOW                     //文本速度 快
};

