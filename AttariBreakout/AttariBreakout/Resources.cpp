#include"Resources.h"
Texture Resources::ball;
Texture Resources::bar;
Texture Resources::bricks;
void Resources::loadTextures()
{
	ball.loadFromFile("graphics/ball.png");
	bar.loadFromFile("graphics/bar.png");
	bricks.loadFromFile("graphics/smallBrick.png");
}