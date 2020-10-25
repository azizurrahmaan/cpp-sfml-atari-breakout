#ifndef BAR_H
#define BAR_H
#include<SFML\Graphics.hpp>
#include"Resources.h"
using namespace sf;
class Bar:public Drawable
{
	int midX;
public:
	static Sprite sprite;
	Bar();
	void setMidX(int);
	int getMidX();
	void setPosition(double pos);
	virtual void draw(RenderTarget & target, RenderStates states) const;
};
#endif // !BAR_H
