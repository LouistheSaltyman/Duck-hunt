#include "GameScene.h"
#include "Bird.h"
#include "Pumpkin.h"
USING_NS_CC;

GameScene::GameScene()
{


}

GameScene::~GameScene()
{

}


Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;

}
bool GameScene::isGot;
bool GameScene::isLost;
int GameScene::pump_count;
int GameScene::pump2_count;
int GameScene::pump3_count;

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//添加背景图片
	auto bgImage = Sprite::create("always/bg_night.png");
	//设置背景全屏
	float winw = visibleSize.width;
	float winh = visibleSize.height;
	float spx = bgImage->getTextureRect().getMaxX();
	float spy = bgImage->getTextureRect().getMaxY();
	bgImage->setScaleX(winw / spx);
	bgImage->setScaleY(winh / spy);
	bgImage->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(bgImage, 0);

	//载入资料
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("plist/plist_duck_1.plist", "plist/plist_duck_1.png");
	cache->addSpriteFramesWithFile("plist/plist_duck_4.plist", "plist/plist_duck_4.png");

	pump_count = 1;
	pump2_count = 1;
	pump3_count = 1;

	
	addPumpkin();
	addDuck("duck_boss_fly_");
	//addDuck("duck_low_fly_");
	this->scheduleUpdate();
	
	
	return true;
}

void GameScene::BirdMove(Bird* bird)
{
	auto moveBy = MoveBy::create(4, Vec2(Director::getInstance()->getVisibleSize().width, 0));
	auto reverse = moveBy->reverse();
	auto flip = CallFuncN::create(CC_CALLBACK_1(GameScene::birdFlipped, this));
	bird->runAction(RepeatForever::create(Sequence::create(moveBy, flip, reverse, flip, NULL)));

}
void GameScene::birdFlipped(Object* pSender)
{
	
	Bird *sprite = (Bird *)pSender;
	if (sprite->isFlippedX())
	{
		sprite->setFlippedX(false);
	}
	else
	{
		sprite->setFlippedX(true);
	}


}

void GameScene::addDuck(std::string filename)
{
	
	if (GameScene::pump_count == 1 && Pumpkin::pump_count == 1)
	{
		auto bird = Bird::create(filename);
		bird->setTag(4);
		bird->setPosition(0, 200);
		this->addChild(bird);
		//BirdMove(bird);
		//auto catch_Pump = CallFuncN::create(CC_CALLBACK_1(GameScene::birdFlipped, this));
		auto move1 = MoveTo::create(2, Pumpkin::pump->getPosition());
		auto move2 = MoveTo::create(2, Vec2(400, 200));
		bird->runAction(Sequence::createWithTwoActions(move1, move2));
		GameScene::pump_count = 0;
	}
	else if (GameScene::pump2_count == 1 && Pumpkin::pump2_count == 1)
	{
		auto bird = Bird::create(filename);
		bird->setTag(5);
		bird->setPosition(0, 200);
		this->addChild(bird);
		//BirdMove(bird);
		//auto catch_Pump = CallFuncN::create(CC_CALLBACK_1(GameScene::birdFlipped, this));
		auto move1 = MoveTo::create(2, Pumpkin::pump2->getPosition());
		auto move2 = MoveTo::create(2, Vec2(400, 200));
		bird->runAction(Sequence::createWithTwoActions(move1, move2));
		GameScene::pump2_count = 0;
	}
	else if (GameScene::pump3_count == 1 && Pumpkin::pump3_count == 1)
	{
		auto bird = Bird::create(filename);
		bird->setTag(6);
		bird->setPosition(0, 200);
		this->addChild(bird);
		//BirdMove(bird);
		//auto catch_Pump = CallFuncN::create(CC_CALLBACK_1(GameScene::birdFlipped, this));
		auto move1 = MoveTo::create(2, Pumpkin::pump3->getPosition());
		auto move2 = MoveTo::create(2, Vec2(400, 200));
		bird->runAction(Sequence::createWithTwoActions(move1, move2));
		GameScene::pump3_count = 0;
	}
	else
	{
		auto bird = Bird::create(filename);
		bird->setTag(4);
		bird->setPosition(0, 200);
		this->addChild(bird);
		BirdMove(bird);
	}
	

}

void GameScene::addPumpkin()
{
	//加入南瓜
	Pumpkin::pump = Pumpkin::create();
	Pumpkin::pump->setPosition(200, 70);
	this->addChild(Pumpkin::pump, 2);
	auto shadow = Sprite::createWithSpriteFrameName("game_pumpkin_shadow.png");
	shadow->setTag(1);
	shadow->setPosition(Pumpkin::pump->getPositionX(), 50);
	this->addChild(shadow,1);

	Pumpkin::pump2 = Pumpkin::create();
	Pumpkin::pump2->setPosition(150, 70);
	this->addChild(Pumpkin::pump2, 2);
	auto shadow2 = Sprite::createWithSpriteFrameName("game_pumpkin_shadow.png");
	shadow2->setTag(2);
	shadow2->setPosition(Pumpkin::pump2->getPositionX(), 50);
	this->addChild(shadow2, 1);
//	pump->runAction(MoveBy::create(4, Vec2(100, 130)));

	Pumpkin::pump3 = Pumpkin::create();
	Pumpkin::pump3->setPosition(100, 70);
	this->addChild(Pumpkin::pump3, 2);
	auto shadow3 = Sprite::createWithSpriteFrameName("game_pumpkin_shadow.png");
	shadow3->setTag(3);
	shadow3->setPosition(Pumpkin::pump3->getPositionX(), 50);
	this->addChild(shadow3, 1);
	
	
	

}



void GameScene::update(float t)
{
	auto duck = this->getChildByTag(10);
	auto shadow = this->getChildByTag(1);
	auto shadow2 = this->getChildByTag(2);
	auto shadow3 = this->getChildByTag(3);

	shadow->setPositionX(Pumpkin::pump->getPositionX());
	shadow2->setPositionX(Pumpkin::pump2->getPositionX());
	shadow3->setPositionX(Pumpkin::pump3->getPositionX());
	

	if (this->getChildByTag(5))
	{
		
		auto x = this->getChildByTag(5)->getBoundingBox();
		auto y = Pumpkin::pump2->getPosition();
		if (x.containsPoint(y))
		{
			Pumpkin::pump2_count = 1;
		}
		followBird(pump2_count,5);
	}
	
		
		
		
}

void GameScene::followBird(int n,int Item)
{
	if (n == 1)
	{
		auto duck = this->getChildByTag(Item);
		Pumpkin::pump2->setPosition(duck->getPosition()/*duck->getPositionX(),duck->getPositionY()-duck->getContentSize().height*2/3*/);
	}
}

//void GameScene::pumpgoground(bool isLost)
//{
//	if (isLost)
//	{
//		
//		
//	}
//}

