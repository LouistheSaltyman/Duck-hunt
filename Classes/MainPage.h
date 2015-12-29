#ifndef _MAINPAGE_
#define _MAINPAGE_

#include "cocos2d.h"

class MainPage : public cocos2d::Layer
{
public:
	CREATE_FUNC(MainPage);


	static cocos2d::Scene* createScene();


	virtual bool init();


	void menuCallback(Ref* pSender);


	void menuCallback1(Ref* pSender);
};
#endif//_MAINPAGE_