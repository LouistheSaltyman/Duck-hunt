#include "Pumpkin.h"
USING_NS_CC;

Sprite* Pumpkin::pump;
Sprite* Pumpkin::pump2;
Sprite* Pumpkin::pump3;
int Pumpkin::pump_count;
int Pumpkin::pump2_count;
int Pumpkin::pump3_count;

Pumpkin::Pumpkin()
{


}

Pumpkin::~Pumpkin()
{


}

Sprite *Pumpkin::create()
{
	
	pump_count = 1;
	pump2_count = 1;
	pump3_count = 1;
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("plist/plist_game_1.plist", "plist/plist_game_1.png");
	pump = Pumpkin::createWithSpriteFrameName("game_pumpkin.png");

	return pump;
}

