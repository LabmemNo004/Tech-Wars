#include "HelloWorldScene.h"
#include"Inputfieldbox.h"
#include<string>
#include"Ball/BallTest.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visible_size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create background layer
	Sprite *bg = Sprite::create("menu/background_start.jpg");
	bg->setPosition(Vec2(origin.x + visible_size.width / 2,
		origin.y + visible_size.height / 2));
	this->addChild(bg);
	
	//create start button
	Sprite *startSpriteNormal = Sprite::create("menu/start01.png");
	Sprite *startSpriteSelected = Sprite::create("menu/start02.png");

	MenuItemSprite *startMenuItem = MenuItemSprite::create(startSpriteNormal,
		startSpriteSelected,
		CC_CALLBACK_1(HelloWorld::getGameScene, this));

	startMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(400, 550)));

	//create setting button
	MenuItemImage *settingMenuItem = MenuItemImage::create(
		"menu/setting01.png",
		"menu/setting02.png",
		CC_CALLBACK_1(HelloWorld::getSettingScene, this));

	settingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(640, 550)));

	//create quit button
	MenuItemImage *quitMenuItem = MenuItemImage::create(
		"menu/quit01.png",
		"menu/quit02.png",
		CC_CALLBACK_1(HelloWorld::quitGame, this));

	quitMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(880, 550)));

    //create button layer
	Menu* mu = Menu::create(startMenuItem, settingMenuItem, quitMenuItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);

    return true;
}

void HelloWorld::getGameScene(cocos2d::Object *pSender)
{
	auto sc = Inputfield::createScene();
	auto reScene = TransitionShrinkGrow::create(0.7f, sc);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/click.wav");
	}
}

void HelloWorld::getSettingScene(cocos2d::Object *pSender)
{
	auto sc = Setting::createScene();
	auto reScene = TransitionShrinkGrow::create(0.7f, sc);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/click.wav");
	}
}

void HelloWorld::quitGame(Object *pSender)
{
	//Close the cocos2d-x game scene and quit the application

	Director::getInstance()->end();
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/click.wav");
	}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);

}


void HelloWorld::onEnter()
{
	Scene::onEnter();
	log("HelloWorld onEnter");
}
//开始播放
void HelloWorld::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();
	log("HelloWorld onEnterTransitionDidFinish");

	if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY)) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/music.mp3", true);
	}
}
void HelloWorld::onExit()
{
	Scene::onExit();
	log("HelloWorld onExit");
}

void HelloWorld::onExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();
	log("HelloWorld onExitTransitionDidStart");
}
//停止播放
void HelloWorld::cleanup()
{
	Scene::cleanup();
	log("HelloWorld cleanup");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/music.mp3");
}
