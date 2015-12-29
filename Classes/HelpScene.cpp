#include "HelpScene.h"

USING_NS_CC;

HelpScene::HelpScene()
{

}

HelpScene::~HelpScene()
{

}


Scene* HelpScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelpScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool HelpScene::init()
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

	//加载 help scene
	//将plist文件载入数据
	SpriteBatchNode* spritebatch = SpriteBatchNode::create("plist/plist_cover.png");
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("plist/plist_cover.plist");

	auto helpScene = Sprite::createWithSpriteFrameName("help.png");
	helpScene->setPosition(visibleSize.width / 2, visibleSize.height);
	helpScene->setTag(1);
	this->addChild(helpScene);
	helpScene->runAction(MoveTo::create(0.2, Vec2(visibleSize.width / 2, visibleSize.height / 2)));

	//对部分图片侦听
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelpScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);





	return true;
}

bool HelpScene::onTouchBegan(Touch *touch, Event *event)
{
	auto sprite = this->getChildByTag(1);
	Size size = sprite->getContentSize();
	Point pos = sprite->getPosition();
	Rect rect = CCRectMake(pos.x + size.width / 2 -30, pos.y + size.height / 2 - 30, 20, 20);
	Point touchPoint = touch->getLocationInView();
	touchPoint = Director::sharedDirector()->convertToGL(touchPoint);
	if (rect.containsPoint(touchPoint))
	{
		Director::sharedDirector()->popScene();
	}

	return false;
}
