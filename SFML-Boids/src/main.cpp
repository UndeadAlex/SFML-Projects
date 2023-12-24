//--INCLUDES--//

#include "GameConstants.h"
#include "GameRandom.h"

#include <SFML/Graphics.hpp>
#include "BoidManager.h"

int main()
{
	using namespace sf;

	// create the main window, prevent it from being resized
	RenderWindow mainWindow(VideoMode(GameConstants::gWindowWidth, GameConstants::gWindowHeight), "Template Project", sf::Style::Titlebar | sf::Style::Close);

	// set framerate
	mainWindow.setFramerateLimit(144);

	// clock for timing
	Clock clock;

	/*Boid boid(400.0f, 400.0f, 100.0f, 0.0f);
	boid.Init();*/

	BoidManager boidManager;
	for (int i = 0; i < 15; i++)
	{
		boidManager.CreateBoid(GameRandom::randVector2f({GameConstants::gWindowWidth,GameConstants::gWindowHeight}), GameRandom::randVector2f({10,10}, {20,20}));
	}

	// start the game loop
	while (mainWindow.isOpen())
	{
		// Handle Timing
		Time dt = clock.restart();

		Event event;
		while (mainWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				mainWindow.close();
			}
		}

		mainWindow.clear();

		boidManager.Update(dt);
		boidManager.Render(mainWindow);

		mainWindow.display();
	}

	return 0;
}