#include"Bricks.h"
#include<iostream>
Sprite Bricks::sprite[5][13];
Bricks::Bricks()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			sprite[i][j].setTexture(Resources::bricks);
		}
	}
}
void Bricks::draw(RenderTarget & target, RenderStates states) const
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			target.draw(sprite[i][j],states);
		}
	}
}
int Bricks::remove(int i, int j)
{
	if (i < 0 && i >= 5 && j < 0 && j >= 13)
		return 0;

	static int removedBricks = 0;
	
	sprite[i][j].setPosition(-1000, -1000);
	std::cout << removedBricks << std::endl;

	return ++removedBricks;
}