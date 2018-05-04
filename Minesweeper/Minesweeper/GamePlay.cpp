﻿#include "GamePlay.h"


GamePlay::GamePlay(sf::RenderWindow* window)
{
	this->mWindow = window;
	sf::Texture background;
	background.loadFromFile("Assets/drawable/Backgrounds/Play_Background.png");
	sf::Sprite Background(background);

	this->start();

		
}
void GamePlay::start() {
	
	this->Node9.loadFromFile(PathImage + "Play/Node.png");
	this->Node0.loadFromFile(PathImage + "Play/0.png");
	this->Node1.loadFromFile(PathImage + "Play/1.png");
	this->Node2.loadFromFile(PathImage + "Play/2.png");
	this->Node3.loadFromFile(PathImage + "Play/3.png");
	this->Node4.loadFromFile(PathImage + "Play/4.png");
	this->Node5.loadFromFile(PathImage + "Play/5.png");
	this->Node6.loadFromFile(PathImage + "Play/6.png");
	this->Node7.loadFromFile(PathImage + "Play/7.png");
	this->Node8.loadFromFile(PathImage + "Play/8.png");

	this->simle.loadFromFile(PathImage + "Play/ClickSmile.png");
	this->Flag.loadFromFile(PathImage + "Play/Flag.png");

	this->Mine.loadFromFile(PathImage + "Play/Mine.png");

	

	this->Simle.setTexture(this->simle);
	this->Simle.setOrigin(16, 16);
	this->Simle.setPosition(200, 50);





	for (int i = 0; i < 12; i++)
	{
		node[i][0].kinds = 0;
		node[i][11].kinds = 0;
	}

	for (int j = 0; j < 8; j++)
	{
		node[0][j].kinds = 0;
		node[7][j].kinds = 0;
	}

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 6; j++)
			if ((rand() % 5 - 3) == -1)
			{
				node[i][j].kinds = -1;
				node[i][j].LastLayer.setTexture(Mine);
			}
			else {
				node[i][j].kinds = NULL;
				node[i][j].LastLayer.setTexture(Node0);
			}

	for (int i = 1; i <= 10; i++)
				for (int j = 1; j <= 6; j++)
				{
					node[i][j].setData(Node9);
					node[i][j].x = i * 32 + 8;// +40;
					node[i][j].y = j * 32 + 68;// +100;
					node[i][j].FirstLayer.setPosition(node[i][j].x, node[i][j].y);
					node[i][j].LastLayer.setPosition(node[i][j].x, node[i][j].y);
					if (node[i][j].kinds == NULL)
					{
						if ((i >= 1) && (i <= 10) && (j >= 1) && (j <= 6))
						{
							int count = 0;
							if (node[i - 1][j].kinds == -1)count++;
							if (node[i + 1][j].kinds == -1)count++;
							if (node[i][j - 1].kinds == -1)count++;
							if (node[i][j + 1].kinds == -1)count++;
							if (node[i - 1][j - 1].kinds == -1)count++;
							if (node[i - 1][j + 1].kinds == -1)count++;
							if (node[i + 1][j - 1].kinds == -1)count++;
							if (node[i + 1][j + 1].kinds == -1)count++;
							node[i][j].kinds = count;
							switch (node[i][j].kinds)
							{
							case 0:
								node[i][j].LastLayer.setTexture(Node0);
								break;
							case 1:
								node[i][j].LastLayer.setTexture(Node1);
								break;
							case 2:
								node[i][j].LastLayer.setTexture(Node2);
								break;
							case 3:
								node[i][j].LastLayer.setTexture(Node3);
								break;
							case 4:
								node[i][j].LastLayer.setTexture(Node4);
								break;
							case 5:
								node[i][j].LastLayer.setTexture(Node5);
								break;
							case 6:
								node[i][j].LastLayer.setTexture(Node6);
								break;
							case 7:
								node[i][j].LastLayer.setTexture(Node7);
								break;
							case 8:
								node[i][j].LastLayer.setTexture(Node8);
								break;
							}
						}
					}
				}

	
}

void GamePlay::update() {
	
	
}



void GamePlay::draw() {
	
	
}
