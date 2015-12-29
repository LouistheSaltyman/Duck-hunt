#ifndef _BIRD_
#define _BIRD_
#include "cocos2d.h"
USING_NS_CC;
class Bird : public cocos2d::Sprite
{

public:
	Bird();

	~Bird();

	static Bird *create(const std::string &fileName);

	virtual void onEnter();
	
	bool onTouchBegan(Touch *touch, Event *event);

	void spritefadeout(Object* pSender);
};






#endif _BIRD_ // _BIRD_