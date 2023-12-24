#ifndef BOID_H
#define BOID_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

class Boid
{
public:
	Boid();
	Boid(sf::Vector2f position);
	Boid(sf::Vector2f position, sf::Vector2f velocity);
	virtual ~Boid();

	void Init();
	void Update(sf::Time& pDeltaTime, const std::vector<Boid>& otherBoids);
	void Render(sf::RenderWindow& renderWindow);

	bool checkScreenBounds();

private:
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;

	sf::CircleShape mCircleShape;

	int mTeam = 0;
};

#endif // BOID_H

