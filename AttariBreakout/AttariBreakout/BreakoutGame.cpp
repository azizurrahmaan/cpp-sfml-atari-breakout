#include"BreakoutGame.h"
#include<iostream>
using namespace std;
bool BreakoutGame::isWin()
{
	return totalBricks == bricksRemoved;
}
void BreakoutGame::start()
{

	int maxX = 1159;// 1082;
	int maxY = 578;
	int xOrigin = maxX / 2;
	int yOrigin = maxY - 8;

	totalBricks = 65;
	bricksRemoved = 0;

	Resources::loadTextures();
	VideoMode vm(Resources::windowWidth, Resources::windowHeight);

	RenderWindow window(vm, "Atari Breakout");

	Bar bar;
	Ball ball;
	Bricks bricks;

	int i = 0, j = 0;
	//window.setMouseCursorVisible(false);
	double bounceAngle;
	unsigned long long int iterator = 0;
	ballLives = 3;
	while (window.isOpen() && ball.aboveBottomBoundry)
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::MouseMoved && startGame)
			{
				bar.setPosition(e.mouseMove.x);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();
		if (Keyboard::isKeyPressed(Keyboard::Space))
			startGame = true;

		if (iterator > 0 && startGame)
		{
			ball.moveBall();
			ball.determineDirection();
			detectBrickCollision(ball, bricks);

			if (isWin())
			{
				displayScore(window, "You Win", totalBricks * 10);

				sleep(seconds(3));

				break;
			}

			if (!ball.aboveBottomBoundry)
			{
				if (ballLives == 0)
				{
					sleep(seconds(1.5));

					displayScore(window, "You Lose", bricksRemoved * 10);

					sleep(seconds(3));

					break;
				}
				else if(ballLives > 0)
				{
					sleep(seconds(1));
					ballLives--;
					ball.reSetBallposition();
				}
			}
			ball.setSpeed(ball.getSpeed()+(bricksRemoved / totalBricks));


			if (ball.sprite.getGlobalBounds().intersects(bar.sprite.getGlobalBounds()))
			{
				int midBar = bar.sprite.getPosition().x + (bar.sprite.getGlobalBounds().width / 2);
				int midBall = ball.sprite.getPosition().x + (ball.sprite.getGlobalBounds().width / 2);
				if (midBall - midBar == 0)
				{
					//std::cout << "centre\n";
				}
				else
				{
					std::cout << (midBall - midBar) / bar.sprite.getGlobalBounds().width << std::endl;

					bounceAngle = ((midBall - midBar) / bar.sprite.getGlobalBounds().width) * 75;

					//ball.calcVelocity(bounceAngle);
				}
				setBallDirection(ball, bar);
			}



			window.clear(Color(34, 34, 34, 255));

			displayScoreBoard(window);

			window.draw(ball);

			window.draw(bar);

			window.draw(bricks);
		}
		if (iterator == 0 || !startGame)
		{
			int X = 3, Y = 100;
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 13; j++)
				{
					if (i % 2 != 0 && j % 2 == 0)
						bricks.sprite[i][j].setScale(1, 1);
					if (i % 2 == 0 && j % 2 != 0)
						bricks.sprite[i][j].setScale(1, 1);
					bricks.sprite[i][j].setPosition(Vector2f(X, Y));

					X += bricks.sprite[i][j].getGlobalBounds().width + 3;
				}
				Y += bricks.sprite[i][j].getGlobalBounds().height + 3;
				X = 3;
			}
			window.clear(Color(34, 34, 34, 255));

			displayScoreBoard(window);

			window.draw(ball);

			window.draw(bar);

			window.draw(bricks);
		}
		/*for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 13; j++)
			{
				window.draw(bricks.sprite[i][j]);
			}
		}*/
		window.display();
		iterator++;
	}
}
void BreakoutGame::detectBrickCollision(Ball & ball,Bricks & bricks)
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (ball.sprite.getGlobalBounds().intersects(bricks.sprite[i][j].getGlobalBounds()))
			{
				if (ball.getRight() && ball.getTop())
				{
					if ((int)(ball.sprite.getPosition().y - (bricks.sprite[i][j].getPosition().y + bricks.sprite[i][j].getGlobalBounds().height)) == 0)
					{
						ball.setTop(false);
						ball.setBottom(true);
						bricksRemoved = bricks.remove(i, j);
					}
					else if ((int)(bricks.sprite[i][j].getPosition().x - (ball.sprite.getPosition().x + ball.sprite.getGlobalBounds().width)) == 0)
					{
						ball.setRight(false);
						ball.setLeft(true);
						bricksRemoved = bricks.remove(i, j);
					}
				}
				else if (ball.getRight() && ball.getBottom())
				{
					if ((int)(bricks.sprite[i][j].getPosition().x - (ball.sprite.getPosition().x + ball.sprite.getGlobalBounds().width)) == 0)
					{
						ball.setRight(false);
						ball.setLeft(true);
						bricksRemoved = bricks.remove(i, j);
					}
					else if ((int)(bricks.sprite[i][j].getPosition().y - (ball.sprite.getPosition().y + ball.sprite.getGlobalBounds().height)) == 0)
					{
						ball.setBottom(false);
						ball.setTop(true);
						bricksRemoved = bricks.remove(i, j);
					}
				}
				else if (ball.getLeft() && ball.getTop())
				{
					if ((int)(ball.sprite.getPosition().y - (bricks.sprite[i][j].getPosition().y + bricks.sprite[i][j].getGlobalBounds().height)) == 0)
					{
						ball.setTop(false);
						ball.setBottom(true);
						bricksRemoved = bricks.remove(i, j);
					}
					else if ((int)(ball.sprite.getPosition().x - (bricks.sprite[i][j].getPosition().x + bricks.sprite[i][j].getGlobalBounds().width)))
					{
						ball.setLeft(false);
						ball.setRight(true);
						bricksRemoved = bricks.remove(i, j);
					}
				}
				else if (ball.getLeft() && ball.getBottom())
				{
					if ((int)(bricks.sprite[i][j].getPosition().y - (ball.sprite.getPosition().y + ball.sprite.getGlobalBounds().height)) == 0)
					{
						ball.setBottom(false);
						ball.setTop(true);
						bricksRemoved = bricks.remove(i, j);
					}
					else if ((int)(ball.sprite.getPosition().x - (bricks.sprite[i][j].getPosition().x + bricks.sprite[i][j].getGlobalBounds().width)))
					{
						ball.setLeft(false);
						ball.setRight(true);
						bricksRemoved = bricks.remove(i, j);
					}
				}
			}
		}
	}
}
void BreakoutGame::setBallDirection(Ball & ball, Bar & bar)
{
	if (ball.getLeft() && ball.getBottom())
	{
		if ((int)(bar.sprite.getPosition().y - (ball.sprite.getPosition().y + ball.sprite.getGlobalBounds().height)) == 0)
		{
			ball.setBottom(false);
			ball.setTop(true);
		}
		else if ((int)(ball.sprite.getPosition().x - (bar.sprite.getPosition().x + bar.sprite.getGlobalBounds().width)))
		{
			ball.setLeft(false);
			ball.setRight(true);
		}
	}
	if (ball.getRight() && ball.getBottom())
	{
		if ((int)(bar.sprite.getPosition().x - (ball.sprite.getPosition().x + ball.sprite.getGlobalBounds().width)) == 0)
		{
			ball.setRight(false);
			ball.setLeft(true);
		}
		else if ((int)(bar.sprite.getPosition().y - (ball.sprite.getPosition().y + ball.sprite.getGlobalBounds().height)) == 0)
		{
			ball.setBottom(false);
			ball.setTop(true);
		}
	}
}
void BreakoutGame::displayScore(RenderWindow & window,string msg,int score)
{
	RectangleShape rectangle;

	rectangle.setSize(Vector2f(350, 200));

	rectangle.setPosition(Vector2f(400, 190));

	window.clear(Color(34, 34, 34, 255));

	Font font;
	font.loadFromFile("fonts/segoeuil.ttf");

	Text text, text1;

	text.setFont(font);
	text1.setFont(font);

	text.setString(msg);


	//int score = totalBricks * 10;
	text1.setString(to_string(score));

	text.setCharacterSize(40);
	text1.setCharacterSize(40);

	text.setFillColor(sf::Color::Green);
	text1.setFillColor(sf::Color::Green);

	text.setStyle(Text::Bold);
	text1.setStyle(Text::Bold);

	text.setPosition(Vector2f(500, 245));
	text1.setPosition(Vector2f(545, 295));

	window.draw(rectangle);
	window.draw(text);
	window.draw(text1);
	window.display();

}
void BreakoutGame::displayScoreBoard(RenderWindow & window)
{
	RectangleShape rectangle;
	rectangle.setSize(Vector2f(1190,35));

	rectangle.setFillColor(Color(204, 115, 14, 255));

	//rectangle.setPosition(Vector2f(100, 50));

	window.clear(Color(34, 34, 34, 255));

	Font font;
	font.loadFromFile("fonts/segoeuil.ttf");

	Text text, text1;

	text.setFont(font);
	text1.setFont(font);

	text.setString(to_string(ballLives));


	//int score = totalBricks * 10;
	text1.setString(to_string(bricksRemoved*10));

	text.setCharacterSize(20);
	text1.setCharacterSize(20);

	text.setFillColor(sf::Color::Black);
	text1.setFillColor(sf::Color::Black);

	text.setStyle(Text::Bold);
	text1.setStyle(Text::Bold);

	text.setPosition(Vector2f(20,5));
	text1.setPosition(Vector2f(1110, 5));


	Text text2, text3;

	text2.setFont(font);
	text3.setFont(font);

	text2.setString("x");


	//int score = totalBricks * 10;
	text3.setString("Score : ");

	text2.setCharacterSize(20);
	text3.setCharacterSize(20);

	text2.setFillColor(sf::Color::Black);
	text3.setFillColor(sf::Color::Black);

	text2.setStyle(Text::Bold);
	text3.setStyle(Text::Bold);

	text2.setPosition(Vector2f(5, 5));
	text3.setPosition(Vector2f(1010, 5));

	window.draw(rectangle);
	window.draw(text);
	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
}