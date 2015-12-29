#ifndef _HELPSCENE_
#define _HELPSCENE_
#include "cocos2d.h"
USING_NS_CC;

class HelpScene : public cocos2d::Layer
{

private:

public:

	HelpScene();

	~HelpScene();
	
	CREATE_FUNC(HelpScene);

	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCallback(Ref* pSender);

	virtual bool onTouchBegan(Touch *touch, Event *event);

};



#endif //_HELPSCENE