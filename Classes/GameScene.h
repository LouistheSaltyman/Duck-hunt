#ifndef _GAMESCENE_
#define _GAMESCENE_
#include "cocos2d.h"
#include "Bird.h"
USING_NS_CC;


class GameScene : public cocos2d::Layer
{
public:
	
	static bool isGot;
	static bool isLost;
	static int pump_count;
	static int pump2_count;
	static int pump3_count;
	GameScene();

	~GameScene();

	CREATE_FUNC(GameScene);

	static cocos2d::Scene* createScene();

	virtual bool init();

	void BirdMove(Bird* bird);

	void birdFlipped(Object* pSender);

	void addDuck(std::string filename);

	void addPumpkin();

	void update(float t);

	void followBird(int n, int Item);

	/*void pumpgoground(bool isLost);*/

};

#endif _GAMESCENE_ // _GAMESCENE_