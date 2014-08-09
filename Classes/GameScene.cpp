#include "HelloWorldScene.h"
#include "GameScene.h"


USING_NS_CC;

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

int GameScene::creates(int x,int y)
{
	int randomId=(int)(x+(CCRANDOM_0_1()*(y-x+1)));
	return randomId;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	Godzillas=CCArray::createWithCapacity(50);
	Godzillas->retain();
	bullets=CCArray::createWithCapacity(50);
	bullets->retain();
    CCSprite* pSprite = CCSprite::create("gamescene.png");
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(mysize.width/2 + origin.x, mysize.height/2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

	sph=GameScene::gethero();
	this->addChild(sph,0,1);
 
    schedule(schedule_selector(GameScene::getGodzilla),3); 
    schedule(schedule_selector(GameScene::getbullet),2);
  
    scheduleUpdate();
    
    return true;
}

void GameScene::getGodzilla(float dt)
{
	 CCSprite *sp1=GameScene::Godzilla(GameScene::creates(1,3));
   sp1->setPosition(ccp(480,GameScene::creates(50,290)));
   Godzillas->addObject(sp1);

   this->addChild(sp1);
}
void GameScene::getbullet(float dt)
{    
	CCPoint pon =sph->getPosition();
	CCSprite* pSprite = CCSprite::create("bullet_7_01.png");
	bullets->addObject(pSprite);
	pSprite->setPosition(ccp(100,pon.y));
	CCActionInterval * run=CCMoveTo::create(2,ccp(500,pon.y));
	CCAction *sequneceAction = CCSequence::create( CCRepeat::create(run,1), NULL); 
	pSprite->runAction(sequneceAction);
	this->GameScene::gethuohua(pSprite);
    this->addChild(pSprite);	
}

CCSprite* GameScene::gethero()
{
	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();
	//创建主角
	 CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("主角_0.plist");
	CCSprite *sph1=CCSprite::createWithSpriteFrameName("skeleton-shoot0.png");
    //创建帧数组
    char str[50];
    CCArray * animatearrayh=CCArray::createWithCapacity(3);
    for(int i=0;i<9;i++){
			sprintf(str,"skeleton-shoot%i.png",i);
    CCSpriteFrame * frameh=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
    animatearrayh->addObject(frameh);
}
    //创建CCAnimation对象
    CCAnimation * mah=CCAnimation::createWithSpriteFrames(animatearrayh,0.2f);
    mah->setLoops(-1);
   //创建CCFiniteTimeAction对象
    CCFiniteTimeAction * anh=CCAnimate::create(mah);
   sph1->runAction(anh);
   sph1->setPosition(ccp(40,mysize.height/2));
 
	return sph1;
}
CCSprite* GameScene::Godzilla(int s)
{
	 //创建哥斯拉，使用第一张图
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("敌人_0.plist");

	CCSprite * sp=CCSprite::create();
    //创建帧数组
    char str[50];
    CCArray * animatearray=CCArray::createWithCapacity(3);
    for(int i=1;i<11;i++){
		switch (s)
	{
	case 1:
		{
			 sp=CCSprite::createWithSpriteFrameName("image_3_1_001.png");
			 if(i<10){sprintf(str,"image_3_1_00%i.png",i);}
			 else{sprintf(str,"image_3_1_0%i.png",i);}
		}
		break;
    case 2:
		{
			sp=CCSprite::createWithSpriteFrameName("image_3_2_001.png");
			 if(i<10){sprintf(str,"image_3_2_00%i.png",i);}
			 else{sprintf(str,"image_3_2_0%i.png",i);}
		}
		break;
	case 3:
		{
			sp=CCSprite::createWithSpriteFrameName("image_3_3_001.png");
			 if(i<10){sprintf(str,"image_3_3_00%i.png",i);}
			 else{sprintf(str,"image_3_3_0%i.png",i);}
		}
		break;
	default:
		break;
	}
    CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
    animatearray->addObject(frame);
}
    //创建CCAnimation对象
    CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.2f);
    ma->setLoops(-1);
   //创建CCFiniteTimeAction对象
	CCFiniteTimeAction * an=CCAnimate::create(ma);

   CCActionInterval * run=CCMoveTo::create(15.0f,ccp(-50,GameScene::creates(50,290)));

   CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
   sp->runAction(spw);
   
   return sp;
}
void GameScene::getbaozha(CCSprite *BZ)
 {
  CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("爆炸_0.plist");
	CCSprite *sph1=CCSprite::createWithSpriteFrameName("baozha_000.png");
    //创建帧数组
    char str[50];
    CCArray * animatearrayh=CCArray::createWithCapacity(3);
    for(int i=0;i<30;i++){
		if(i<10){sprintf(str,"baozha_00%i.png",i);}
		else{sprintf(str,"baozha_0%i.png",i);}
    CCSpriteFrame * frameh=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
    animatearrayh->addObject(frameh);
}
    //创建CCAnimation对象
    CCAnimation * mah=CCAnimation::createWithSpriteFrames(animatearrayh,0.2f);
    mah->setLoops(1);
   //创建CCFiniteTimeAction对象
    CCFiniteTimeAction * anh=CCAnimate::create(mah);
	//CCAction *sequneceAction = CCSequence::create(anh,CCCallFunc::create(this, callfunc_selector(GameScene::lost)), NULL);
   sph1->runAction(anh);
   CCPoint point=BZ->getPosition();
   sph1->setPosition(ccp(point.x,point.y));
	this->addChild(sph1);
 }	
void GameScene::gethuohua(CCSprite *HH)
{
	 CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("开枪火花_0.plist");
	CCSprite *sp1=CCSprite::createWithSpriteFrameName("shootFireAction04-play0.png");
    //创建帧数组
    char str[50];
    CCArray * animatearrayh=CCArray::createWithCapacity(3);
    for(int i=0;i<9;i++){
			sprintf(str,"shootFireAction04-play%i.png",i);
    CCSpriteFrame * frameh=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
    animatearrayh->addObject(frameh);
}
    //创建CCAnimation对象
    CCAnimation * mah=CCAnimation::createWithSpriteFrames(animatearrayh,0.2f);
    mah->setLoops(1);
   //创建CCFiniteTimeAction对象
    CCFiniteTimeAction * anh=CCAnimate::create(mah);
	//CCFiniteTimeAction  *sequneceAction = CCSequence::create(anh,CCCallFunc::create(this, SEL_CallFunc(GameScene::lost)), NULL);
   sp1->runAction(anh);
   CCPoint point=HH->getPosition();
   sp1->setPosition(ccp(point.x,point.y));
	this->addChild(sp1);
}
void GameScene::update(float dt)
{
	CCObject *obj;
	CCObject *obj1;
	CCARRAY_FOREACH(bullets,obj)
	{
		CCARRAY_FOREACH(Godzillas,obj1)
	{
		CCSprite *sp3=(CCSprite *)obj;
		CCSprite *sp4=(CCSprite *)obj1;
		if(sp4->boundingBox().intersectsRect(sp3->boundingBox())){
				bullets->removeObject(sp3);
				this->removeChild(sp3);
				Godzillas->removeObject(sp4);
				this->GameScene::getbaozha(sp4);
				this->removeChild(sp4);
 
		}
		else{
	 if (sp3->getPositionX()>480)
	 {
		 bullets->removeObject(sp3);
		  this->removeChild(sp3);
	 }
	 if (sp4->getPositionX()<-49)
	 {
		 Godzillas->removeObject(sp4);
		 this->removeChild(sp4);
	 }
		}
	}
	}
	
}
void GameScene::lost(CCObject *sender)
{

}


bool GameScene::ccTouchBegan(CCTouch * ctouch,CCEvent * event){


return true;

}

void GameScene::ccTouchMoved(CCTouch * ctouch,CCEvent * event){

CCPoint point=ctouch->getLocation();

CCSprite * sp=(CCSprite *)this->getChildByTag(1);

CCPoint point1=CCPoint::CCPoint(40,point.y);

sp->setPosition(point1);

}

void GameScene::ccTouchEnded(CCTouch * ctouch,CCEvent * event){


}
void GameScene::onEnter(){

//开启触屏监听

CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);

CCLayer::onEnter();

}

void GameScene::onExit(){

//关闭触屏监听

CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);

CCLayer::onExit();

}



