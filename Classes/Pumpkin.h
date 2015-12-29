#ifndef _PUMPKIN_
#define _PUMPKIN_
#include "cocos2d.h"
USING_NS_CC;
class Pumpkin : public cocos2d::Sprite
{
public:
	static Sprite* pump;
	static Sprite* pump2;
	static Sprite* pump3;

	static int pump_count;
	static int pump2_count;
	static int pump3_count;

	Pumpkin();

	~Pumpkin();

	static Sprite *create();
	
	
};


#endif _PUMPKIN_ // _PUMPKIN_