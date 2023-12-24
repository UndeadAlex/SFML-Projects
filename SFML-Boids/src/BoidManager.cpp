#include "BoidManager.h"

BoidManager::BoidManager()
{

}

BoidManager::~BoidManager()
{

}

void BoidManager::Update(sf::Time& worldTime)
{
	for (int i = 0; i < mBoids.size(); i++)
	{
		mBoids[i].Update(worldTime, mBoids);
	}
}

void BoidManager::Render(sf::RenderWindow& renderWindow)
{
	for (int i = 0; i < mBoids.size(); i++)
	{
		mBoids[i].Render(renderWindow);
	}
}

void BoidManager::CreateBoid(sf::Vector2f position, sf::Vector2f velocity /*= { 0.0f,0.0f }*/)
{
	Boid tmpBoid(position, velocity);
	tmpBoid.Init();

	mBoids.push_back(tmpBoid);
}
