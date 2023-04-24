#include "Pacman.hpp"
#include "Wall.hpp"
#include "Pellet.hpp"
#include "Ghost.hpp"
#include "Container.hpp"

//******************************************************
//To-Do
//Win and lose condition: Figure out how to find font file to display text
//Power Pellets: Inherited from pellet, make ghosts able to be eaten
//Use polymorphism somewhere
//Test class with 5 test cases
//Make the Ghost AI not suck
//Multiple levels with faster movement and shorter power pellet length
//Multiple lives
//Point system/extra lives from points
//Display points and life count on screen with font file
//Fruits
//Main menu
//Clean up code/organize into functions
//Make video
int main()
{ //This is all the stuff that creates the window for the game
	int horizRes = 1050, vertRes = 1350;
	sf::RenderWindow window(sf::VideoMode(horizRes, vertRes), "Pac-Man");
	sf::Event event; // this event is able to capture anything that goes on in the window. Key presses, mouse movement, etc.

	//Pacman n' Gang
	Pacman pacman(30.0, sf::Vector2f(horizRes / 2 - 30, vertRes / 2 + 348), sf::Color::Yellow, .4);
	Ghost blinky(sf::Vector2f(60.0, 60.0), sf::Vector2f(horizRes / 2 - 29, vertRes / 2 - 142), sf::Color::Red, .375,0);
	std::vector<Ghost> ghosts = { blinky };
	/*
	Ghost blinky(sf::Vector2f(60.0, 60.0), sf::Vector2f(horizRes / 2 - 29, vertRes / 2 - 142), sf::Color::Red, .375), 
		pinky(sf::Vector2f(60.0, 60.0), sf::Vector2f(horizRes / 2 - 95, vertRes / 2 - 30), sf::Color::Magenta, .325),
		inky(sf::Vector2f(60.0, 60.0), sf::Vector2f(horizRes / 2 - 30, vertRes / 2 - 30), sf::Color::Cyan, .275), 
		clyde(sf::Vector2f(60.0, 60.0), sf::Vector2f(horizRes / 2 + 35, vertRes / 2 - 30), sf::Color(255, 165, 0), .225);
	std::vector<Ghost> ghosts = { blinky, pinky, inky, clyde };
	*/
	Container c1;
	//Walls
	std::vector<Wall> walls = c1.makeWalls(horizRes, vertRes);
	//Pellets
	std::vector<Pellet> pellets = c1.makePellets(horizRes, vertRes);

	//Game Loop
	while (window.isOpen())
	{
		
		while (window.pollEvent(event))//PollEvent will save the events that go on in the window in this variable "event"
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (pacman.getDead() == false)
			{
				pacman.move(0, -pacman.getSpeed());
				for (int i = 0; i < walls.size(); i++)
				{
					if (pacman.getGlobalBounds().intersects(walls[i].getGlobalBounds()))
					{
						pacman.move(0, pacman.getSpeed());
						break;
					}
				}
			}
		}
		//Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (pacman.getDead() == false)
			{
				pacman.move(-pacman.getSpeed(), 0);
				for (int i = 0; i < walls.size(); i++)
				{
					if (pacman.getGlobalBounds().intersects(walls[i].getGlobalBounds()))
					{
						pacman.move(pacman.getSpeed(), 0);
						break;
					}
				}
			}
		}
		//Down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (pacman.getDead() == false)
			{
				pacman.move(0, pacman.getSpeed());
				for (int i = 0; i < walls.size(); i++)
				{
					if (pacman.getGlobalBounds().intersects(walls[i].getGlobalBounds()))
					{
						pacman.move(0, -pacman.getSpeed());
						break;
					}
				}
			}
		}
		//Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (pacman.getDead() == false)
			{
				pacman.move(pacman.getSpeed(), 0);
				for (int i = 0; i < walls.size(); i++)
				{
					if (pacman.getGlobalBounds().intersects(walls[i].getGlobalBounds()))
					{
						pacman.move(-pacman.getSpeed(), 0);
						break;
					}
				}
			}
		}
		//Ghost AI
		
		for (int i = 0; i < ghosts.size(); i++)
		{
			if (ghosts[i].getPosition().x > horizRes / 2 + 100 || ghosts[i].getPosition().x < horizRes / 2 - 100 || ghosts[i].getPosition().y > vertRes / 2 + 80 || ghosts[i].getPosition().y < vertRes / 2 - 80)
			{
				
				//Checks which direction ghosts can move
				bool canMoveUp = true, canMoveLeft = true, canMoveDown = true, canMoveRight = true;
				for (int j = 0; j < walls.size(); j++)
				{
					ghosts[i].move(0, -2);
					if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
					{
						canMoveUp = false;
					}
					ghosts[i].move(0, 2);
					ghosts[i].move(-2, 0);
					if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
					{
						canMoveLeft = false;
					}
					ghosts[i].move(2, 0);
					ghosts[i].move(0, 2);
					if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
					{
						canMoveDown = false;
					}
					ghosts[i].move(0, -2);
					ghosts[i].move(2, 0);
					if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
					{
						canMoveRight = false;
					}
					ghosts[i].move(-2, 0);
					
				}
				
				//Calculates which direction moves closest to pacman
				float upScore, leftScore, downScore, rightScore;
				upScore = sqrt(pow(ghosts[i].getPosition().x - pacman.getPosition().x, 2) + pow((ghosts[i].getPosition().y - ghosts[i].getSpeed()) - pacman.getPosition().y, 2));
				leftScore = sqrt(pow((ghosts[i].getPosition().x - ghosts[i].getSpeed()) - pacman.getPosition().x, 2) + pow(ghosts[i].getPosition().y - pacman.getPosition().y, 2));
				downScore = sqrt(pow(ghosts[i].getPosition().x - pacman.getPosition().x, 2) + pow((ghosts[i].getPosition().y + ghosts[i].getSpeed()) - pacman.getPosition().y, 2));
				rightScore = sqrt(pow((ghosts[i].getPosition().x + ghosts[i].getSpeed()) - pacman.getPosition().x, 2) + pow(ghosts[i].getPosition().y - pacman.getPosition().y, 2));
				std::vector<float> directionScores = { upScore, leftScore, downScore, rightScore };
				float lowestScore = pow(horizRes, 2) + pow(vertRes, 2);
				for (int k = 0; k < directionScores.size(); k++)
				{
					if (directionScores[k] < lowestScore)
					{
						lowestScore = directionScores[k];
					}
				}
				sf::Vector2f targetTile(100, 100);
				sf::Vector2f distance = targetTile - ghosts[i].getPosition();
				const float threshold = 5;
				if (std::abs(distance.x) < threshold && std::abs(distance.y) < threshold)
				{
					// ghost has reached target position

				}
				/*
				else 
				{
					// sprite has not yet reached target position, update its position
					float speed = 1.0f; // adjust the speed of the sprite as needed
					sf::Vector2f movement = distance / std::sqrt(distance.x * distance.x + distance.y * distance.y) * speed;
					ghosts[i].move(movement);
				}
				*/
				//If up is best move
				if (upScore == lowestScore)
				{
					//std::cout << "wants up, ";
					if (canMoveUp == true)
					{
						//std::cout << "up" << std::endl;
						ghosts[i].move(0, -ghosts[i].getSpeed());
						
					}
					//If up is blocked
					else
					{
						//But can move left and right
						if (canMoveLeft && canMoveRight)
						{
							float pixels = 0.0;
							bool pathFound = false;
							ghosts[i].move(0, -6);
							//Search area for alternate path expands until path is found
							while (!pathFound)
							{
								ghosts[i].move(-pixels, 0);
								for (int j = 0; j < walls.size(); j++)
								{
									//If up path is found to the left
									if (!(ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds())))
									{
										//std::cout << "left path found" << std::endl;
										pathFound = true;
										ghosts[i].move(-ghosts[i].getSpeed(), 0);
										break;
									}
									//If wall to the left, go right
									ghosts[i].move(0, 6);
									if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
									{
										//std::cout << "right bc wall" << std::endl;
										pathFound = true;
										ghosts[i].move(ghosts[i].getSpeed(), 0);
										break;
									}
									ghosts[i].move(0, -6);
								}
								ghosts[i].move(pixels, 0);
								if (!pathFound)
								{
									ghosts[i].move(pixels, 0);
									for (int j = 0; j < walls.size(); j++)
									{
										//If up path is found to the right
										if (!(ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds())))
										{
											//std::cout << "right path found" << std::endl;
											pathFound = true;
											ghosts[i].move(ghosts[i].getSpeed(), 0);
											break;
										}
										//If wall to the right, go left
										ghosts[i].move(0, 6);
										if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
										{
											//std::cout << "left bc wall" << std::endl;
											pathFound = true;
											ghosts[i].move(-ghosts[i].getSpeed(), 0);
											break;
										}
										ghosts[i].move(0, -6);
									}
									ghosts[i].move(-pixels, 0);
								}
								pixels++;
							}
							ghosts[i].move(0, 6);
						}
						//Can only move left
						else if (canMoveLeft)
						{
							//std::cout << "left" << std::endl;
							ghosts[i].move(-ghosts[i].getSpeed(), 0);
						}
						//Can only move right
						else if (canMoveRight)
						{
							//std::cout << "right" << std::endl;
							ghosts[i].move(ghosts[i].getSpeed(), 0);
						}
					}
				}
				//If left is best move
				else if (leftScore == lowestScore)
				{
					//std::cout << "wants left, ";
					if (canMoveLeft == true)
					{
						//std::cout << "left" << std::endl;
						ghosts[i].move(-ghosts[i].getSpeed(), 0);
					}
					else
					{
						if (canMoveUp && canMoveDown)
						{
							float pixels = 0.0;
							bool pathFound = false;
							ghosts[i].move(-6, 0);
							while (!pathFound)
							{
								ghosts[i].move(0, -pixels);
								for (int j = 0; j < walls.size(); j++)
								{
									if (!(ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds())))
									{
										//std::cout << "up path found" << std::endl;
										pathFound = true;
										ghosts[i].move(0, -ghosts[i].getSpeed());
										break;
									}
									ghosts[i].move(6, 0);
									if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
									{
										//std::cout << "down bc wall" << std::endl;
										pathFound = true;
										ghosts[i].move(0, ghosts[i].getSpeed());
										break;
									}
									ghosts[i].move(-6, 0);
								}
								ghosts[i].move(0, pixels);
								if (!pathFound)
								{
									ghosts[i].move(0, pixels);
									for (int j = 0; j < walls.size(); j++)
									{
										if (!(ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds())))
										{
											//std::cout << "down path found" << std::endl;
											pathFound = true;
											ghosts[i].move(0, ghosts[i].getSpeed());
											break;
										}
										ghosts[i].move(6, 0);
										if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
										{
											//std::cout << "up bc wall" << std::endl;
											pathFound = true;
											ghosts[i].move(0, -ghosts[i].getSpeed());
											break;
										}
										ghosts[i].move(-6, 0);
									}
									ghosts[i].move(0, -pixels);
								}
								pixels++;
							}
							ghosts[i].move(6, 0);
						}
						else if (canMoveUp)
						{
							//std::cout << "up" << std::endl;
							ghosts[i].move(0, -ghosts[i].getSpeed());
						}
						else if (canMoveDown)
						{
							//std::cout << "down" << std::endl;
							ghosts[i].move(0, ghosts[i].getSpeed());
						}
					}
				}
				//If down is best move
				else if (downScore == lowestScore)
				{
					//std::cout << "wants down, ";
					if (canMoveDown == true)
					{
						//std::cout << "down" << std::endl;
						ghosts[i].move(0, ghosts[i].getSpeed());
						
					}
					else
					{
						if (canMoveLeft && canMoveRight)
						{
							float pixels = 0.0;
							bool pathFound = false;
							ghosts[i].move(0, 6);
							while (!pathFound)
							{
								ghosts[i].move(-pixels, 0);
								for (int j = 0; j < walls.size(); j++)
								{
									if (!(ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds())))
									{
										//std::cout << "left path found" << std::endl;
										pathFound = true;
										ghosts[i].move(-ghosts[i].getSpeed(), 0);
										break;
									}
									ghosts[i].move(0, -6);
									if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
									{
										//std::cout << "right bc wall" << std::endl;
										pathFound = true;
										ghosts[i].move(ghosts[i].getSpeed(), 0);
										break;
									}
									ghosts[i].move(0, 6);
								}
								ghosts[i].move(pixels, 0);
								if (!pathFound)
								{
									ghosts[i].move(pixels, 0);
									for (int j = 0; j < walls.size(); j++)
									{
										if (!(ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds())))
										{
											//std::cout << "right path found" << std::endl;
											pathFound = true;
											ghosts[i].move(ghosts[i].getSpeed(), 0);
											break;
										}
										ghosts[i].move(0, -6);
										if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
										{
											//std::cout << "left bc wall" << std::endl;
											pathFound = true;
											ghosts[i].move(-ghosts[i].getSpeed(), 0);
											break;
										}
										ghosts[i].move(0, 6);
									}
									ghosts[i].move(-pixels, 0);
								}
								pixels++;
							}
							ghosts[i].move(0, -6);
						}
						else if (canMoveLeft)
						{
							//std::cout << "left" << std::endl;
							ghosts[i].move(-ghosts[i].getSpeed(), 0);
						}
						else if (canMoveRight)
						{
							//std::cout << "right" << std::endl;
							ghosts[i].move(ghosts[i].getSpeed(), 0);
						}
					}
				}
				//If right is best move
				else if (rightScore == lowestScore)
				{
					//std::cout << "wants right, ";
					if (canMoveRight == true)
					{
						//std::cout << "right" << std::endl;
						ghosts[i].move(ghosts[i].getSpeed(), 0);
					}
					else
					{
						if (canMoveUp && canMoveDown)
						{
							float pixels = 0.0;
							bool pathFound = false;
							ghosts[i].move(6, 0);
							while (!pathFound)
							{
								ghosts[i].move(0, -pixels);
								for (int j = 0; j < walls.size(); j++)
								{
									if (!(ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds())))
									{
										//std::cout << "up path found" << std::endl;
										pathFound = true;
										ghosts[i].move(0, -ghosts[i].getSpeed());
										break;
									}
									ghosts[i].move(-6, 0);
									if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
									{
										//std::cout << "down bc wall" << std::endl;
										pathFound = true;
										ghosts[i].move(0, ghosts[i].getSpeed());
										break;
									}
									ghosts[i].move(6, 0);
								}
								ghosts[i].move(0, pixels);
								if (!pathFound)
								{
									ghosts[i].move(0, pixels);
									for (int j = 0; j < walls.size(); j++)
									{
										if (!(ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds())))
										{
											//std::cout << "down path found" << std::endl;
											pathFound = true;
											ghosts[i].move(0, ghosts[i].getSpeed());
											break;
										}
										ghosts[i].move(-6, 0);
										if (ghosts[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
										{
											//std::cout << "up bc wall" << std::endl;
											pathFound = true;
											ghosts[i].move(0, -ghosts[i].getSpeed());
											break;
										}
										ghosts[i].move(6, 0);
									}
									ghosts[i].move(0, -pixels);
								}
								pixels++;
							}
							ghosts[i].move(-6, 0);
						}
						else if (canMoveUp)
						{
							//std::cout << "up" << std::endl;
							ghosts[i].move(0, -ghosts[i].getSpeed());
						}
						else if (canMoveDown)
						{
							//std::cout << "down" << std::endl;
							ghosts[i].move(0, ghosts[i].getSpeed());
						}
					}
				}
			}
			//Moves ghosts out of box when last ghost moves far enough away
			else
			{
				if (ghosts[i - 1].getPosition().x > horizRes / 2 + 200 || ghosts[i - 1].getPosition().x < horizRes / 2 - 200 || ghosts[i - 1].getPosition().y > vertRes / 2 + 200 || ghosts[i - 1].getPosition().y < vertRes / 2 - 300)
				{
					ghosts[i].setPosition(horizRes / 2 - 29, vertRes / 2 - 142);
				}
			}
		}
		
		//Eat pellet
		for (int i = 0; i < pellets.size(); i++)
		{
			if (pacman.getGlobalBounds().intersects(pellets[i].getGlobalBounds()))
			{
				pellets[i].setEaten(true);
			}
		}
		//Die
		for (int i = 0; i < ghosts.size(); i++)
		{
			if (pacman.getGlobalBounds().intersects(ghosts[i].getGlobalBounds()))
			{
				pacman.setDead(true);
			}
		}
		//Tunnel
		if (pacman.getPosition().x < -30)
		{
			pacman.setPosition(1050, pacman.getPosition().y);
		}
		if (pacman.getPosition().x > 1050)
		{
			pacman.setPosition(-30, pacman.getPosition().y);
		}
		
		window.clear();//Tell window to clear frame from screen
		//Between .clear() and .display() is where the rendering/drawing of the game must happen
		//Draw walls
		for (int i = 0; i < walls.size(); i++)
		{
			window.draw(walls[i]);
		}
		//Draw pellets
		int pelletsLeft = 0;
		for (int i = 0; i < pellets.size(); i++)
		{
			if (pellets[i].getEaten() == false)
			{
				window.draw(pellets[i]);
				pelletsLeft++;
			}
		}
		//Draw pacman
		if (pacman.getDead() == false)
		{
			window.draw(pacman);
		}
		//Draw ghosts
		for (int i = 0; i < ghosts.size(); i++)
		{
			window.draw(ghosts[i]);
		}
		//Win Condition: Find a way for project to find font file
		/*
		if (pelletsLeft == 0)
		{
			sf::Text text;
			sf::Font font;
			font.loadFromFile("munro.ttf");
			text.setFont(font);
			text.setString("You win!");
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::White);
			window.draw(text);
		}
		*/
		window.display(); //Tell app that window is done drawing and display to screen
	}
	return 0;
}
