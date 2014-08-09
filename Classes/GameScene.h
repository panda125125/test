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
	//��ȡ�����
	static int creates(int x,int y);
	//����
	CCSprite * sph;
	CCArray  *Godzillas;
	CCArray *bullets;
	

	static CCSprite* gethero();

	//���ݲ����������ֲ�ͬ�ĵ���
	static CCSprite* Godzilla(int s);

    // implement the "static node()" method manually
    CREATE_FUNC(GameScene);

	//��ײ���
	void update(float dt);

	//��ը����
	void getbaozha(CCSprite *BZ);

	//��ǹ�𻨶���
	void gethuohua(CCSprite *HH);

	//�����������
	void getGodzilla(float dt); 

	//�����ӵ�
	void getbullet(float dt);

	//���տ�ǹ�� ��ը����
	void lost(CCObject *sender);
	

	//�����¼�

    virtual bool ccTouchBegan(CCTouch * touch,CCEvent * event);
    virtual void ccTouchMoved(CCTouch * touch,CCEvent * event);
    virtual void ccTouchEnded(CCTouch * touch,CCEvent * event);

	//��������

    virtual void onEnter();
	virtual void onExit();

};
#endif