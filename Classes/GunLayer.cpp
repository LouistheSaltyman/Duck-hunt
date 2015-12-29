#include "GunLayer.h"

bool BaseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("plist/plist_equip_2.plist", "plist/plist_equip_2.png");
	cache->addSpriteFramesWithFile("plist/plist_equip_1.plist", "plist/plist_equip_1.png");
	cache->addSpriteFramesWithFile("plist/plist_equip_3.plist", "plist/plist_equip_3.png");
	
	visblesize = Director::sharedDirector()->getVisibleSize();
	right_button_up = Sprite::createWithSpriteFrameName("equip_arrow_right_up.png");
	right_buton_down = Sprite::createWithSpriteFrameName("equip_arrow_right_down.png");
	left_button_up = Sprite::createWithSpriteFrameName("equip_arrow_left_up.png");
	left_button_down = Sprite::createWithSpriteFrameName("equip_arrow_left_down.png");
	gunImage = NULL;
	gunName = NULL;
	previousBtn = NULL;
	nextBtn = NULL;
	return true;
}

bool ShotGun::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	gunImage = Sprite::createWithSpriteFrameName("equip_gun_shot.png");
	gunName = Sprite::createWithSpriteFrameName("equip_gun_shot_name.png");
	auto backButton = Sprite::createWithSpriteFrameName("equip_arraw_transparent_left.png");
	nextBtn = MenuItemSprite::create(right_button_up, right_buton_down, CC_CALLBACK_1(ShotGun::callback, this));
	auto menu = Menu::create(nextBtn,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	gunImage->setPosition(visblesize.width/3, visblesize.height/2);
	gunName->setPosition(visblesize.width*2 / 3, gunImage->getPositionY() + gunImage->getContentSize().height / 1.5);
	nextBtn->setPosition(visblesize.width/2+gunImage->getContentSize().width, visblesize.height/2);
	backButton->setPosition(visblesize.width / 2 - gunImage->getContentSize().width, visblesize.height / 2);
	this->addChild(gunImage);
	this->addChild(gunName);
	this->addChild(backButton);


	return true;
}

void ShotGun::callback(Ref* pSender)
{
	
	static_cast<LayerMultiplex*>(_parent)->switchTo(1);
}

bool MiniGun::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	gunImage = Sprite::createWithSpriteFrameName("equip_gun_mini.png");
	gunName = Sprite::createWithSpriteFrameName("equip_gun_mini_name.png");
	previousBtn = MenuItemSprite::create(left_button_up,left_button_down, CC_CALLBACK_1(MiniGun::callback1, this));
	nextBtn = MenuItemSprite::create(right_button_up, right_buton_down, CC_CALLBACK_1(MiniGun::callback2, this));

	auto menu = Menu::create(nextBtn,previousBtn, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	gunImage->setPosition(visblesize.width / 3, visblesize.height / 2);
	gunName->setPosition(visblesize.width * 2 / 3, gunImage->getPositionY() + gunImage->getContentSize().height / 1.5);
	nextBtn->setPosition(visblesize.width / 2 + gunImage->getContentSize().width, visblesize.height / 2);
	previousBtn->setPosition(visblesize.width / 2 - gunImage->getContentSize().width, visblesize.height / 2);
	this->addChild(gunImage);
	this->addChild(gunName);
	

	return true;
}
void MiniGun::callback1(Ref* Psender)
{

	static_cast<LayerMultiplex*>(_parent)->switchTo(0);
}

void MiniGun::callback2(Ref* pSender)
{

	static_cast<LayerMultiplex*>(_parent)->switchTo(2);
}

bool MachineGun::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	gunImage = Sprite::createWithSpriteFrameName("equip_gun_machine.png");
	gunName = Sprite::createWithSpriteFrameName("equip_gun_machine_name.png");
	previousBtn = MenuItemSprite::create(left_button_up, left_button_down, CC_CALLBACK_1(MachineGun::callback1, this));
	nextBtn = MenuItemSprite::create(right_button_up, right_buton_down, CC_CALLBACK_1(MachineGun::callback2, this));

	auto menu = Menu::create(nextBtn, previousBtn, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	gunImage->setPosition(visblesize.width / 3, visblesize.height / 2);
	gunName->setPosition(visblesize.width * 2 / 3, gunImage->getPositionY() + gunImage->getContentSize().height / 1.5);
	nextBtn->setPosition(visblesize.width / 2 + gunImage->getContentSize().width, visblesize.height / 2);
	previousBtn->setPosition(visblesize.width / 2 - gunImage->getContentSize().width, visblesize.height / 2);
	this->addChild(gunImage);
	this->addChild(gunName);


	return true;
}

void MachineGun::callback1(Ref* pSender)
{
	static_cast<LayerMultiplex*>(_parent)->switchTo(1);
}
void MachineGun::callback2(Ref* pSender)
{
	static_cast<LayerMultiplex*>(_parent)->switchTo(3);
}

bool ScatterGun::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	gunImage = Sprite::createWithSpriteFrameName("equip_gun_flame.png");
	gunName = Sprite::createWithSpriteFrameName("equip_gun_scatter_name.png");
	previousBtn = MenuItemSprite::create(left_button_up, left_button_down, CC_CALLBACK_1(ScatterGun::callback1, this));
	

	auto menu = Menu::create(previousBtn, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	auto nextButton = Sprite::createWithSpriteFrameName("equip_arraw_transparent_right.png");
	gunImage->setPosition(visblesize.width / 3, visblesize.height / 2);
	gunName->setPosition(visblesize.width * 2 / 3, gunImage->getPositionY() + gunImage->getContentSize().height / 1.5);
	nextButton->setPosition(visblesize.width / 2 + gunImage->getContentSize().width, visblesize.height / 2);
	previousBtn->setPosition(visblesize.width / 2 - gunImage->getContentSize().width, visblesize.height / 2);
	this->addChild(nextButton);
	this->addChild(gunImage);
	this->addChild(gunName);


	return true;
}

void ScatterGun::callback1(Ref* pSender)
{
	static_cast<LayerMultiplex*>(_parent)->switchTo(2);
}
