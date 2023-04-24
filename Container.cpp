#include "Container.hpp"

std::vector<Wall> Container::makeWalls(float horizRes, float vertRes)
{
	std::vector<Wall> walls;
	sf::Color wallColor = sf::Color::Blue;
	//Outer Edges
	walls.push_back({ sf::Vector2f(horizRes, 30.0), sf::Vector2f(0, 0), wallColor });  walls.push_back({ sf::Vector2f(horizRes, 30.0), sf::Vector2f(0, vertRes - 30), wallColor }); walls.push_back({ sf::Vector2f(30.0, vertRes / 2 - 32), sf::Vector2f(0, 0), wallColor }); walls.push_back({ sf::Vector2f(30.0, vertRes / 2 - 32), sf::Vector2f(horizRes - 30, 0), wallColor });
	walls.push_back({ sf::Vector2f(30.0, vertRes / 2 - 32), sf::Vector2f(0, vertRes / 2 + 32), wallColor }); walls.push_back({ sf::Vector2f(30.0, vertRes / 2 - 32), sf::Vector2f(horizRes - 30, vertRes / 2 + 32), wallColor });
	//Tunnel Edges
	walls.push_back({ sf::Vector2f(180.0, 160.0), sf::Vector2f(0, vertRes / 2 - 192), wallColor }); walls.push_back({ sf::Vector2f(180.0, 160.0), sf::Vector2f(horizRes - 180, vertRes / 2 - 192), wallColor }); walls.push_back({ sf::Vector2f(180.0, 160.0), sf::Vector2f(0, vertRes / 2 + 32), wallColor }); walls.push_back({ sf::Vector2f(180.0, 160.0), sf::Vector2f(horizRes - 180, vertRes / 2 + 32), wallColor });
	//Ghost Box
	walls.push_back({ sf::Vector2f(30.0, 160.0), sf::Vector2f(horizRes / 2 - 130, vertRes / 2 - 80), wallColor }); walls.push_back({ sf::Vector2f(30.0, 160.0), sf::Vector2f(horizRes / 2 + 100, vertRes / 2 - 80), wallColor }); walls.push_back({ sf::Vector2f(260.0, 30.0), sf::Vector2f(horizRes / 2 - 130, vertRes / 2 + 50), wallColor }); walls.push_back({ sf::Vector2f(260.0, 30.0), sf::Vector2f(horizRes / 2 - 130, vertRes / 2 - 80), wallColor });
	//walls.push_back({ sf::Vector2f(98.0, 30.0), sf::Vector2f(horizRes / 2 + 32, vertRes / 2 - 80), wallColor });
	//Center Walls
	//Sideways T's
	walls.push_back({ sf::Vector2f(87.0, 310.0), sf::Vector2f(horizRes / 2 - 281, vertRes / 2 - 342), wallColor }); walls.push_back({ sf::Vector2f(87.0, 310.0), sf::Vector2f(horizRes / 2 + 194, vertRes / 2 - 342), wallColor }); walls.push_back({ sf::Vector2f(115.0, 48.0), sf::Vector2f(horizRes / 2 - 194, vertRes / 2 - 192), wallColor }); walls.push_back({ sf::Vector2f(115.0, 48.0), sf::Vector2f(horizRes / 2 + 79, vertRes / 2 - 192), wallColor });
	//Normal T's
	walls.push_back({ sf::Vector2f(260.0, 86.0), sf::Vector2f(horizRes / 2 - 130, vertRes / 2 - 342), wallColor }); walls.push_back({ sf::Vector2f(260.0, 48.0), sf::Vector2f(horizRes / 2 - 130, vertRes / 2 + 144), wallColor }); walls.push_back({ sf::Vector2f(30.0, 198.0), sf::Vector2f(horizRes / 2 - 15, vertRes / 2 - 342), wallColor }); walls.push_back({ sf::Vector2f(30.0, 200.0), sf::Vector2f(horizRes / 2 - 15, vertRes / 2 + 144), wallColor });
	//Blocks
	walls.push_back({ sf::Vector2f(87.0, 160.0), sf::Vector2f(horizRes / 2 - 281, vertRes / 2 + 32), wallColor }); walls.push_back({ sf::Vector2f(87.0, 160.0), sf::Vector2f(horizRes / 2 + 194, vertRes / 2 + 32), wallColor });
	//Top Walls
	walls.push_back({ sf::Vector2f(86.0, 86.0), sf::Vector2f(horizRes / 2 - 431, vertRes / 2 - 342), wallColor }); walls.push_back({ sf::Vector2f(86.0, 86.0), sf::Vector2f(horizRes / 2 + 345, vertRes / 2 - 342), wallColor }); walls.push_back({ sf::Vector2f(86.0, 175.0), sf::Vector2f(horizRes / 2 - 431, vertRes / 2 - 581), wallColor }); walls.push_back({ sf::Vector2f(86.0, 175.0), sf::Vector2f(horizRes / 2 + 345, vertRes / 2 - 581), wallColor });
	walls.push_back({ sf::Vector2f(202.0, 175.0), sf::Vector2f(horizRes / 2 - 281, vertRes / 2 - 581), wallColor }); walls.push_back({ sf::Vector2f(202.0, 175.0), sf::Vector2f(horizRes / 2 + 79, vertRes / 2 - 581), wallColor }); walls.push_back({ sf::Vector2f(30.0, 269.0), sf::Vector2f(horizRes / 2 - 15, 0), wallColor });
	//Bottom Walls
	//Blocks
	walls.push_back({ sf::Vector2f(202.0, 88.0), sf::Vector2f(horizRes / 2 - 281, vertRes / 2 + 256), wallColor }); walls.push_back({ sf::Vector2f(202.0, 88.0), sf::Vector2f(horizRes / 2 + 79, vertRes / 2 + 256), wallColor });
	//L's
	walls.push_back({ sf::Vector2f(86.0, 88.0), sf::Vector2f(horizRes / 2 - 431, vertRes / 2 + 256), wallColor }); walls.push_back({ sf::Vector2f(86.0, 88.0), sf::Vector2f(horizRes / 2 + 345, vertRes / 2 + 256), wallColor }); walls.push_back({ sf::Vector2f(30.0, 200.0), sf::Vector2f(horizRes / 2 - 375, vertRes / 2 + 256), wallColor }); walls.push_back({ sf::Vector2f(30.0, 200.0), sf::Vector2f(horizRes / 2 + 345, vertRes / 2 + 256), wallColor });
	//Upside-Down T's
	walls.push_back({ sf::Vector2f(352.0, 61.0), sf::Vector2f(horizRes / 2 - 431, vertRes / 2 + 520), wallColor }); walls.push_back({ sf::Vector2f(352.0, 61.0), sf::Vector2f(horizRes / 2 + 79, vertRes / 2 + 520), wallColor }); walls.push_back({ sf::Vector2f(87.0, 173.0), sf::Vector2f(horizRes / 2 - 281, vertRes / 2 + 408), wallColor }); walls.push_back({ sf::Vector2f(87.0, 173.0), sf::Vector2f(horizRes / 2 + 194, vertRes / 2 + 408), wallColor });
	//Edge Blocks
	walls.push_back({ sf::Vector2f(86.0, 48.0), sf::Vector2f(0, vertRes / 2 + 408), wallColor }); walls.push_back({ sf::Vector2f(86.0, 48.0), sf::Vector2f(horizRes - 86, vertRes / 2 + 408), wallColor });
	//Normal T
	walls.push_back({ sf::Vector2f(260.0, 48.0), sf::Vector2f(horizRes / 2 - 130, vertRes / 2 + 408), wallColor }); walls.push_back({ sf::Vector2f(30.0, 173.0), sf::Vector2f(horizRes / 2 - 15, vertRes / 2 + 408), wallColor });
	return walls;
}

std::vector<Pellet> Container::makePellets(float horizRes, float vertRes)
{
	std::vector<Pellet> pellets;
	sf::Color pelletColor = sf::Color::White;
	float pelletRadius = 5.0;
	//Left Column
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 568), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 518), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 468), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 418), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 368), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 318), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 268), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 218), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 168), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 118), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 68), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 - 18), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 32), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 82), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 132), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 182), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 232), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 282), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 332), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 382), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 432), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 318, vertRes / 2 + 482), pelletColor });
	//Right Column
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 568), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 518), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 468), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 418), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 368), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 318), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 268), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 218), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 168), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 118), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 68), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 - 18), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 32), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 82), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 132), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 182), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 232), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 282), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 332), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 382), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 432), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 308, vertRes / 2 + 482), pelletColor });
	//Bottom Row
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 455, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 405, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 355, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 305, vertRes - 67), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 255, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 205, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 155, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 105, vertRes - 67), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 55, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 5, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 45, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 95, vertRes - 67), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 145, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 195, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 245, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 295, vertRes - 67), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 345, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 395, vertRes - 67), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 445, vertRes - 67), pelletColor });
	//Top Row
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 418, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 368, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 268, vertRes / 2 - 618), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 218, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 118, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 68, vertRes / 2 - 618), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 58, vertRes / 2 - 618), pelletColor });  pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 108, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 208, vertRes / 2 - 618), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 258, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 358, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 408, vertRes / 2 - 618), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 458, vertRes / 2 - 618), pelletColor });
	//Second-to-Top Row
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 418, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 368, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 268, vertRes / 2 - 379), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 218, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 118, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 68, vertRes / 2 - 379), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 5, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 58, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 108, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 - 379), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 208, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 258, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 358, vertRes / 2 - 379), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 408, vertRes / 2 - 379), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 458, vertRes / 2 - 379), pelletColor });
	//Row Below Center
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 418, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 368, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 268, vertRes / 2 + 219), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 218, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 118, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 68, vertRes / 2 + 219), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 58, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 108, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 208, vertRes / 2 + 219), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 258, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 358, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 408, vertRes / 2 + 219), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 458, vertRes / 2 + 219), pelletColor });
	//Spawn Row
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 268, vertRes / 2 + 371), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 218, vertRes / 2 + 371), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 + 371), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 118, vertRes / 2 + 371), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 68, vertRes / 2 + 371), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 58, vertRes / 2 + 371), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 108, vertRes / 2 + 371), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 + 371), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 208, vertRes / 2 + 371), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 258, vertRes / 2 + 371), pelletColor });
	//Misc. Top
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 - 568), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 - 429), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 52, vertRes / 2 - 558), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 52, vertRes / 2 - 498), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 52, vertRes / 2 - 438), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 42, vertRes / 2 - 558), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 42, vertRes / 2 - 498), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 42, vertRes / 2 - 438), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes - 67, vertRes / 2 - 568), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes - 67, vertRes / 2 - 429), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 418, vertRes / 2 - 229), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 368, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 358, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 408, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 458, vertRes / 2 - 229), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 118, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 68, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 58, vertRes / 2 - 229), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 108, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 - 229), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 - 329), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 - 279), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 - 329), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 - 279), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 - 329), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 - 279), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes - 67, vertRes / 2 - 329), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes - 67, vertRes / 2 - 279), pelletColor });
	//Misc. Bottom
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 418, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 368, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 358, vertRes / 2 + 482), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 408, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 458, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 118, vertRes / 2 + 482), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 68, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 58, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 108, vertRes / 2 + 482), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 + 482), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 + 269), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes / 2 + 319), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 52, vertRes / 2 + 269), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 52, vertRes / 2 + 319), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 42, vertRes / 2 + 269), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 42, vertRes / 2 + 319), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 458, vertRes / 2 + 269), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 458, vertRes / 2 + 319), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 412, vertRes / 2 + 382), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 412, vertRes / 2 + 432), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 402, vertRes / 2 + 382), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 402, vertRes / 2 + 432), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 168, vertRes / 2 + 432), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 158, vertRes / 2 + 432), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 468, vertRes - 130), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 458, vertRes - 130), pelletColor });
	pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 - 52, vertRes - 130), pelletColor }); pellets.push_back({ pelletRadius, sf::Vector2f(horizRes / 2 + 42, vertRes - 130), pelletColor });
	return pellets;
}