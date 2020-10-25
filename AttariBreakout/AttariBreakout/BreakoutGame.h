#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H
#include"Ball.h"
#include"Bar.h"
#include"Bricks.h"
#include<string>
using namespace std;
class BreakoutGame
{
	bool startGame=false;
	int totalBricks;
	int bricksRemoved;
	int ballLives = 3;
	void detectBrickCollision(Ball&,Bricks&);
	void setBallDirection(Ball&, Bar&);
	bool isWin();
	void displayScore(RenderWindow & window, string msg,int score);
	void displayScoreBoard(RenderWindow & window);
public:
	//BreakoutGame();
	void start();
};
#endif // !BREAKOUT_GAME_H
