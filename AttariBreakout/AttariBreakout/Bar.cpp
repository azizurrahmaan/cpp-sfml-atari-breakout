#include"Bar.h"
Sprite Bar::sprite;
Bar::Bar()
{
	sprite.setTexture(Resources::bar);
	sprite.setScale(Vector2f(1.5,1));
	sprite.setPosition(Vector2f(Resources::windowWidth / 2 - 100, Resources::windowHeight - 20));
}
void Bar::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(sprite, states);
}
void Bar::setPosition(double posX)
{
	if (posX+sprite.getGlobalBounds().width >= Resources::windowWidth)
		posX = Resources::windowWidth - sprite.getGlobalBounds().width - 1;
	sprite.setPosition(Vector2f(posX, Resources::windowHeight - 20));
}
void Bar::setMidX(int m)
{
	if (m >= 0)
		midX = m;
}
int Bar::getMidX()
{
	return midX;
}