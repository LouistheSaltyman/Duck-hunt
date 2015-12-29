#include "MenuScene.h"
#include "GameScene.h"
#include "MainPage.h"
#include "GunLayer.h"
USING_NS_CC;
using namespace ui;

MenuScene::MenuScene()
{


}

MenuScene::~MenuScene()
{

}


Scene* MenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;

}

bool MenuScene::init()
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
	//将plist文件载入数据
	SpriteBatchNode* spritebatch = SpriteBatchNode::create("plist/plist_equip_1.png");
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("plist/plist_equip_1.plist");

	//添加选枪背景
	auto equipBg = Sprite::createWithSpriteFrameName("equip_bg.png");
	equipBg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(equipBg);
		//添加back按钮
		auto back_Button = MenuItemSprite::create(Sprite::createWithSpriteFrameName("equip_button_up.png"), Sprite::createWithSpriteFrameName("equip_button_down.png"), CC_CALLBACK_1(MenuScene::menuBackCallback,this));
		//back_Button->setAnchorPoint(Vec2(0,1));
		back_Button->setPosition(bgImage->getPositionX() - equipBg->getContentSize().width / 3, bgImage->getPositionY() - equipBg->getContentSize().height / 2);
		//添加back文字
		auto back_Text = Sprite::createWithSpriteFrameName("equip_btn_back.png");
		back_Text->setPosition(back_Button->getPosition());
		this->addChild(back_Text,2);

		//添加start按钮
		auto start_Button = MenuItemSprite::create(Sprite::createWithSpriteFrameName("equip_button_up.png"), Sprite::createWithSpriteFrameName("equip_button_down.png"), CC_CALLBACK_1(MenuScene::menuBackCallback1, this));
		//back_Start->setAnchorPoint(Vec2(0, 1));
		start_Button->setPosition(bgImage->getPositionX() + equipBg->getContentSize().width / 3, bgImage->getPositionY() - equipBg->getContentSize().height / 2);
		//添加start文字
		auto start_Text = Sprite::createWithSpriteFrameName("equip_btn_start.png");
		start_Text->setPosition(start_Button->getPosition());
		this->addChild(start_Text, 2);

		// create menu, it's an autorelease object
		auto menu = Menu::create(back_Button, start_Button, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 1);


		//Gun Layer
		auto shotGun = ShotGun::create();
		auto miniGun = MiniGun::create();
		auto machineGun = MachineGun::create();
		auto scatterGun = ScatterGun::create();


		auto layerMultiplex = LayerMultiplex::create(shotGun, miniGun, machineGun, scatterGun, nullptr);
		addChild(layerMultiplex, 0);

	return true;
}

void MenuScene::menuBackCallback(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(MainPage::createScene());
}


void MenuScene::menuBackCallback1(Ref* pSender)
{

	Director::sharedDirector()->replaceScene(GameScene::createScene());

}