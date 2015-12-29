#include "MainPage.h"
#include "HelpScene.h"
#include "MenuScene.h"
USING_NS_CC;



Scene* MainPage::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainPage::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool MainPage::init()
{

	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//添加背景
	auto bg_image = Sprite::create("cover/cover_bg.png");
	bg_image->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	this->addChild(bg_image,0);
	//设置背景全屏
	float winw = visibleSize.width;
	float winh = visibleSize.height;
	float spx = bg_image->getTextureRect().getMaxX();
	float spy = bg_image->getTextureRect().getMaxY();
	bg_image->setScaleX(winw / spx);
	bg_image->setScaleY(winh / spy);

	//将plist文件载入数据
	SpriteBatchNode* spritebatch = SpriteBatchNode::create("plist/plist_cover.png");
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("plist/plist_cover.plist");
	//添加play告示牌
	auto cover_Play = MenuItemSprite::create(Sprite::createWithSpriteFrameName( "cover_button_up.png"),Sprite::createWithSpriteFrameName("cover_button_down.png"),CC_CALLBACK_1(MainPage::menuCallback1, this));
	cover_Play->setPosition(visibleSize.width-visibleSize.width/15 - cover_Play->getContentSize().width/2, visibleSize.height/2 + cover_Play->getContentSize().height/2);
	//添加play
	auto play_label = Sprite::createWithSpriteFrameName("cover_play.png");
	play_label->setPosition(cover_Play->getPosition());
	this->addChild(play_label,2);
	//添加help告示牌
	auto cover_Help = MenuItemSprite::create(Sprite::createWithSpriteFrameName("cover_button_up.png"), Sprite::createWithSpriteFrameName("cover_button_down.png"), CC_CALLBACK_1(MainPage::menuCallback, this));
	cover_Help->setPosition(visibleSize.width - visibleSize.width / 15 - cover_Play->getContentSize().width / 2, cover_Play->getPosition().y - cover_Play->getContentSize().height - 20);
	//添加help
	auto help_label = Sprite::createWithSpriteFrameName("cover_help.png");
	help_label->setPosition(cover_Help->getPosition());
	this->addChild(help_label, 2);
	//添加more告示牌
	auto cover_More = MenuItemSprite::create(Sprite::createWithSpriteFrameName("cover_button_up.png"), Sprite::createWithSpriteFrameName("cover_button_down.png"), CC_CALLBACK_1(MainPage::menuCallback, this));
	cover_More->setPosition(visibleSize.width - visibleSize.width / 15 - cover_Play->getContentSize().width / 2, cover_Help->getPosition().y - cover_Help->getContentSize().height - 20);
	//添加more
	auto more_label = Sprite::createWithSpriteFrameName("cover_more.png");
	more_label->setPosition(cover_More->getPosition());
	this->addChild(more_label, 2);
	//添加音乐与音量告示牌
	auto cover_music = MenuItemSprite::create(Sprite::createWithSpriteFrameName("cover_button_music_up.png"), Sprite::createWithSpriteFrameName("cover_button_music_down.png"), CC_CALLBACK_1(MainPage::menuCallback, this));
	cover_music->setAnchorPoint(Vec2(0, 1));
	cover_music->setPosition(visibleSize.width/16,visibleSize.height);
	auto cover_volume = MenuItemSprite::create(Sprite::createWithSpriteFrameName("cover_button_music_up.png"), Sprite::createWithSpriteFrameName("cover_button_music_down.png"), CC_CALLBACK_1(MainPage::menuCallback, this));
	cover_volume->setAnchorPoint(Vec2(0, 1));
	cover_volume->setPosition(cover_music->getPosition().x + cover_music->getContentSize().width + 10, visibleSize.height);
	//添加音乐与声音icon
	
	// create menu, it's an autorelease object
	auto menu = Menu::create(cover_Play, cover_Help, cover_More, cover_music, cover_volume, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void MainPage::menuCallback(Ref* pSender)
{
	Director::sharedDirector()->pushScene(HelpScene::createScene());
}

void MainPage::menuCallback1(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(MenuScene::createScene());

}