#ifndef BRICKS_H
#define BRICKS_H
#include<SFML/Graphics.hpp>
#include"Resources.h"
using namespace sf;
class Bricks:public Drawable
{
public:
	static Sprite sprite[5][13];
	Bricks();
	virtual void draw(RenderTarget & target, RenderStates states) const;
	int remove(int i, int j);
};
#endif // !BRICKS_H
