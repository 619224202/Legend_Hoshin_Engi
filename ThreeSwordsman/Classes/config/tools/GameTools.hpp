//
//  GameTools.hpp
//  ThreeSwordsman
//
//  Created by 王露 on 2019/6/27.
//

#ifndef GameTools_hpp
#define GameTools_hpp

#include <stdio.h>
#include <map>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <vector>
typedef std::function<void(cocos2d::Ref* ref)> fun_radioButtonDo;

using namespace std;
USING_NS_CC;
using namespace cocos2d::ui;
class GameTools{
public:
    static GameTools* getInstance();
    ~GameTools();
    /**
     加载对应的sceneName的文字对象存储在map<string,string>中，
     若isAdd为true，则在map中增加该项，否则先清空map里的键值对，然后添加进去
     **/
    void loadLanguageWidthScene(const char *sceneName,bool isAdd = false);
    
    void createRadioGroup(const std::string& backUrl,const std::string& crossUrl,const char* groupName,vector<string>& _nameV,const fun_radioButtonDo &f_radioDo,Node* node,const Rect rect,Vec2 vec);
    
    /**
     在map中获取对应键值对的value信息
     **/
    const string getValue(const string& key);
private:
    static GameTools* toolInstance;
    GameTools();
    void funRadionDo(Ref* ref);
private:
    int _language;
    char* _sceneName;
    map<string,string> _textMap;
    fun_radioButtonDo f_m_radioDo;
};

#endif /* GameTools_hpp */
