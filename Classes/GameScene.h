#ifndef  _GAME_SCENE_H_
#define  _GAME_SCENE_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
class GameScene : public CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static CCScene* scene();
	//获取随机数
	static int creates(int x,int y);
	//主角
	CCSprite * sph;
	CCArray  *Godzillas;
	CCArray *bullets;
	

	static CCSprite* gethero();

	//根据参数产生三种不同的敌人
	static CCSprite* Godzilla(int s);

    // implement the "static node()" method manually
    CREATE_FUNC(GameScene);

	//碰撞检测
	void update(float dt);

	//爆炸动画
	void getbaozha(CCSprite *BZ);

	//开枪火花动画
	void gethuohua(CCSprite *HH);

	//随机产生敌人
	void getGodzilla(float dt); 

	//发射子弹
	void getbullet(float dt);

	//回收开枪火花 爆炸动画
	void lost(CCObject *sender);
	

	//触屏事件

    virtual bool ccTouchBegan(CCTouch * touch,CCEvent * event);
    virtual void ccTouchMoved(CCTouch * touch,CCEvent * event);
    virtual void ccTouchEnded(CCTouch * touch,CCEvent * event);

	//生命周期

    virtual void onEnter();
	virtual void onExit();

};
#endif