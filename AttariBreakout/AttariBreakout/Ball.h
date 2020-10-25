#ifndef BALL_H
#define BALL_H
#include<SFML/Graphics.hpp>
#include"Resources.h"
using namespace sf;
class Ball : public Drawable
{
	bool right = false;
	bool left = false;
	bool top = false;
	bool bottom = false;
	bool midY = true;
	bool midX = true;
	float angle = 0.894;
	float speed = 1.0;
	double velocityX = angle;
	double velocityY = angle;
public:
	static Sprite sprite;
	bool aboveBottomBoundry = true;
	Ball();
	void determineDirection();
	void moveBall();
	void setRight(bool);
	void setLeft(bool);
	void setTop(bool);
	void setBottom(bool);
	void setMidX(bool);
	void setMidY(bool);
	bool getRight()const;
	bool getLeft()const;
	bool getTop()const;
	bool getBottom()const;
	bool getMidX()const;
	bool getMidY()const;
	void setAngle(double a);
	double getAngle()const;
	void setSpeed(double s);
	double getSpeed();
	virtual void draw(RenderTarget & target, RenderStates states) const;
	void calcVelocity(double angle);
	void reSetBallposition();
};
#endif // !BALL_H
