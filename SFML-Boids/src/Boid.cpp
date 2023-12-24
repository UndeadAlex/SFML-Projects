#include "Boid.h"
#include "GameConstants.h"

Boid::Boid()
{
	mPosition = sf::Vector2f(0.0f, 0.0f);
	mVelocity = sf::Vector2f(0.0f, 0.0f);
}

Boid::Boid(sf::Vector2f position) : mPosition(position)
{
	mVelocity = sf::Vector2f(0.0f, 0.0f);
}

Boid::Boid(sf::Vector2f position, sf::Vector2f velocity) : mPosition(position), mVelocity(velocity)
{
}

Boid::~Boid()
{

}

void Boid::Init()
{
	mCircleShape.setRadius(15.0f);
	mCircleShape.setPosition(mPosition);
}

void Boid::Update(sf::Time& pDeltaTime, const std::vector<Boid>& otherBoids)
{
	float dt = pDeltaTime.asSeconds();

	float turnFactor = 5.0f;
	if (mPosition.x < 50)
		mVelocity.x = mVelocity.x + turnFactor;
	if (mPosition.x > GameConstants::gWindowWidth - 50)
		mVelocity.x = mVelocity.x - turnFactor;
	if (mPosition.y > GameConstants::gWindowHeight - 50)
		mVelocity.y = mVelocity.y - turnFactor;
	if (mPosition.y < 50)
		mVelocity.y = mVelocity.y + turnFactor;

	mPosition += mVelocity * dt;
	checkScreenBounds();

	sf::Vector2f circleCentre(mCircleShape.getRadius(), mCircleShape.getRadius());
	mCircleShape.setPosition(mPosition - circleCentre);
}

void Boid::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(mCircleShape);
}

bool Boid::checkScreenBounds()
{
	// Width Bounds
	if (mPosition.x > GameConstants::gWindowWidth) 
	{ 
		mPosition.x = 0; 
		return true; 
	}
	else if (mPosition.x < 0) 
	{
		mPosition.x = GameConstants::gWindowWidth; 
		return true;
	}

	// Height Bounds
	if (mPosition.y > GameConstants::gWindowHeight) 
	{ 
		mPosition.y = 0; 
		return true;
	}
	else if (mPosition.y < 0) 
	{ 
		mPosition.y = GameConstants::gWindowHeight; 
		return true;
	}


	return false;
}
