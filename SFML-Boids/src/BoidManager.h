#ifndef BOID_MANAGER_H
#define BOID_MANAGER_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include "Boid.h"

class BoidManager
{
public:
	BoidManager();
	virtual ~BoidManager();

	void Update(sf::Time& worldTime);
	void Render(sf::RenderWindow& renderWindow);

	void CreateBoid(sf::Vector2f position, sf::Vector2f velocity = { 0.0f,0.0f });
	int GetBoidCount() {};
private:
	
	std::vector<Boid> mBoids;
};
#endif // BOID_MANAGER_H

