#ifndef _MENUSCENE_
#define _MENUSCENE_
#include "cocos2d.h"
USING_NS_CC;

class MenuScene : public cocos2d::Layer
{
	
public:

	MenuScene();

	~MenuScene();

	CREATE_FUNC(MenuScene);

	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuBackCallback(Ref* pSender);

	void menuBackCallback1(Ref* pSender);







};
#endif _MENUSCENE_ // _MENUSCENE_