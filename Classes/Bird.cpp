#include "Bird.h"
#include "Pumpkin.h"
#include "GameScene.h"
USING_NS_CC;

Bird::Bird()
{


}

Bird::~Bird()
{


}

Bird *Bird::create(const std::string &fileName)
{
	
	Bird* bird = new Bird();
	char* str = new char[fileName.length() + 5];
	sprintf(str, "%s%d.png", fileName.c_str(), 1);
	Vector<SpriteFrame*> frames(4);
	if (bird && bird->initWithSpriteFrameName(str))
	{ 
		bird->autorelease(); 

		for (int i = 1; i < 5; i++)
		{

			sprintf(str, "%s%d.png", fileName.c_str(), i);
			SpriteFrame* frame = SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
			frames.pushBack(frame);
			
		}

		Animation *splitAnimation = Animation::createWithSpriteFrames(frames, 0.1f);
		bird->runAction(RepeatForever::create(Animate::create(splitAnimation)));
		
		



		return bird; 
	} 
	else 
	{ 
		delete bird;
		bird = NULL;
		return NULL; 
	} 
	
	delete str;



}
void Bird::onEnter()
{
	Sprite::onEnter();
	auto lis = EventListenerTouchOneByOne::create();
	lis->setSwallowTouches(true);
	lis->onTouchBegan = CC_CALLBACK_2(Bird::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(lis, this);


}


bool Bird::onTouchBegan(Touch *touch, Event *event)
{

	auto sprite = event->getCurrentTarget();
	auto n = sprite->getName();
	Size size = sprite->getContentSize();
	Point pos = sprite->getPosition();
	Rect rect = CCRectMake(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
	Point touchPoint = touch->getLocationInView();
	touchPoint = Director::sharedDirector()->convertToGL(touchPoint);
	if (rect.containsPoint(touchPoint))
	{
		sprite->stopAllActions();
		char *str = new char[19];
		Vector<SpriteFrame*> frames(3);

		for (int i = 1; i < 4; i++)
		{

			sprintf(str, "duck_boss_hit_%d.png", i);
			SpriteFrame* frame = SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
			frames.pushBack(frame);

		}

		Animation *hit = Animation::createWithSpriteFrames(frames, 0.1f);
		Animate* hitted = Animate::create(hit);

		
		Vector<SpriteFrame*> dead(8);
		for (int i = 1; i < 9; i++)
		{

			sprintf(str, "duck_death_%d.png", i);
			SpriteFrame* died = SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
			dead.pushBack(died);

		}
		auto deadani = Animation::createWithSpriteFrames(dead, 0.1f);
		Animate* death = Animate::create(deadani);
		auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Bird::spritefadeout, this));
		auto action = Spawn::create(hitted, death, NULL);
		sprite->runAction(Sequence::create(DelayTime::create(0.1),action,actionMoveDone,NULL));
		if (sprite->getTag() == 4)
		{
			Pumpkin::pump->runAction(MoveTo::create(1, Vec2(Pumpkin::pump->getPositionX(), -1000)));
			GameScene::pump_count = 1;
		}
		if (sprite->getTag() == 5)
		{
			Pumpkin::pump2->runAction(MoveTo::create(1, Vec2(Pumpkin::pump2->getPositionX(), -1000)));
			GameScene::pump2_count = 1;
		}
		if (sprite->getTag() == 6)
		{
			Pumpkin::pump3->runAction(MoveTo::create(1, Vec2(Pumpkin::pump3->getPositionX(), -1000)));
			GameScene::pump3_count = 1;
		}
	


	}

	return false;
}

void Bird::spritefadeout(Object* pSender)
{
	Bird *sprite = (Bird *)pSender;
	sprite->removeFromParent();

}