#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;


class BaseLayer : public Layer
{
public:
	CREATE_FUNC(BaseLayer);
	virtual bool init();
	Size visblesize;
	Sprite* gunImage;
	Sprite* gunName;
	MenuItem* previousBtn;
	MenuItem* nextBtn;
	Sprite* right_button_up;
	Sprite* right_buton_down;
	Sprite* left_button_up;
	Sprite* left_button_down;

};


class ShotGun : public BaseLayer
{
public:
	CREATE_FUNC(ShotGun);
	virtual bool init();
	void callback(Ref* pSender);
};

class MiniGun : public BaseLayer
{
public:
	CREATE_FUNC(MiniGun);
	virtual bool init();
	void callback1(Ref* Psender);
	void callback2(Ref* pSender);

};

class MachineGun : public BaseLayer
{
public:
	CREATE_FUNC(MachineGun);
	virtual bool init();
	void callback1(Ref* Psender);
	void callback2(Ref* pSender);

};

class ScatterGun : public BaseLayer
{
public:
	CREATE_FUNC(ScatterGun);
	virtual bool init();
	void callback1(Ref* Psender);
};