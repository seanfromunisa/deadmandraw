#include "Player.h"

Player::Player()
{
	std::string names[] = { "Luffy", "Zoro", "Nami", "Usopp", "Sanji", "Chopper", "Robin", "Franky", "Brook", "Jinbe" };
	std::string name = names[rand() % 10];
}
