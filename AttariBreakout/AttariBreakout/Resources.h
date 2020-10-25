#ifndef RESOURCES_H
#define RESOURCES_H
#include<SFML\Graphics.hpp>
using namespace sf;
class Resources
{
public:
	static Texture ball;
	static Texture bar;
	static Texture bricks;
	static const int windowHeight = 578;
	static const int windowWidth = 1159;
	static void loadTextures();
};
#endif // !RESOURCES_H
