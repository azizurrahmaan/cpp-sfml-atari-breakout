#include"Ball.h"
#include<math.h>
#include<iostream>
Sprite Ball::sprite;
Ball::Ball()
{
	sprite.setTexture(Resources::ball);
	sprite.setScale(Vector2f(0.01, 0.01));
	sprite.setPosition(Vector2f(Resources::windowWidth/2, Resources::windowHeight-41));
}
void Ball::determineDirection()
{
	if (sprite.getPosition().x < 0)
	{
		//std::cout << "\nif (sprite.getPosition().x < 0)\n";
		right = true;
		left = false;
		midX = false;
	}
	else if (sprite.getPosition().x > Resources::windowWidth - 20)
	{
		//std::cout << "\if (sprite.getPosition().x > Resources::windowWidth - 20)\n";
		right = false;
		left = true;
		midX = false;
	}
	if (sprite.getPosition().y < 35)
	{
		//std::cout << "\nif (sprite.getPosition().y < 0)\n";
		bottom = true;
		top = false;
		midY = false;
	}
	else if (sprite.getPosition().y > Resources::windowHeight)
	{
		//std::cout << "\nif (sprite.getPosition().y > Resources::windowHeight)\n";
		//top = true;
		//bottom = false;
		//midY = false;
		aboveBottomBoundry = false;
		//break;
	}
}
void Ball::moveBall()
{
	if (left)
	{
		if (bottom)
		{
			sprite.move(Vector2f(-velocityX*speed, velocityY*speed));
		}
		else if (top)
		{
			sprite.move(Vector2f(-velocityX * speed, -velocityY * speed));
		}
		else if (midY)
		{
			sprite.move(Vector2f(-velocityX * speed, -velocityY * speed));
		}
	}
	else if (right)
	{
		if (bottom)
		{
			sprite.move(Vector2f(velocityX*speed, velocityY*speed));
		}
		else if (top)
		{
			sprite.move(Vector2f(velocityX*speed, -velocityY * speed));
		}
		else if (midY)
		{
			sprite.move(Vector2f(velocityX*speed, -velocityY * speed));
		}
	}
	else if (midX)
	{
		sprite.move(Vector2f(-velocityX * speed, -velocityY * speed));
		left = true;
		//left = false;
		right = false;
		top = true;
		bottom = false;
	}
}
void Ball::setLeft(bool flag)
{
	left = flag;
}
void Ball::setRight(bool flag)
{
	right = flag;
}
void Ball::setBottom(bool flag)
{
	bottom = flag;
}
void Ball::setTop(bool flag)
{
	top = flag;
}
void Ball::setMidY(bool flag)
{
	midY = flag;
}
void Ball::setMidX(bool flag)
{
	midX = flag;
}
bool Ball::getMidY()const
{
	return midY;
}
bool Ball::getMidX()const
{
	return midX;
}
bool Ball::getBottom()const
{
	return bottom;
}
bool Ball::getRight()const
{
	return right;
}
bool Ball::getLeft()const
{
	return left;
}
bool Ball::getTop()const
{
	return top;
}
void Ball::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(sprite, states);

}
void Ball::setAngle(double a)
{
	angle = a;
}
double Ball::getAngle()const
{
	return angle;
}
void Ball::calcVelocity(double angle)
{
	velocityX = speed * cos(angle);
	velocityY = speed * sin(angle);
	std::cout << "\n"<< velocityX << ", " << velocityY <<"\n";
}
void Ball::reSetBallposition()
{
	sprite.setPosition(Vector2f(Resources::windowWidth / 2, Resources::windowHeight - 41));
	aboveBottomBoundry = true;
	bottom=false;
	top=true;
	left=false;
	right=true;
}
void Ball::setSpeed(double s)
{
	if (s >= 0)
		speed = s;
}
double Ball::getSpeed()
{
	return speed;
}