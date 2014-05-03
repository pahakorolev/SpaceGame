#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ParallaxNodeExtras.h"

USING_NS_CC;

typedef enum {
	KENDREASONWIN,
	KENDREASONLOSE
} EndReason;

class HelloWorld : public Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	virtual void onAcceleration(Acceleration* acc, Event* event);
	float randomValueBetween(float low, float high);
	void setInvisible(Node * node);
	float getTimeTick();
	void onTouchesBegan(const std::vector<Touch*>& touches, Event  *event);
private:
	SpriteBatchNode *_batchNode;
	Sprite *_ship;
	ParallaxNodeExtras *_backgroundNode;
	Sprite *_spaceDust1, *_spaceDust2, *_planetSunrise, *_galaxy, *_spatialAnomaly1, *_spatialAnomaly2;
	float _shipPointsPerSecY;
	Vector<Sprite*> *_asteroids;
	int _nextAsteroid=0;
	float _nextAsteroidSpawn=0;
	Vector<Sprite*> *_shipLasers;
	int _nextShipLaser=0;
	int _lives=0;
	double _gameOverTime;
	bool _gameOver=false;

	void update(float dt);
	void endScene(EndReason endReason);
	void restartTapped(Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
