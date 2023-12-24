#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameConstants
{
	constexpr int gWindowWidth = 1280;
	constexpr int gWindowHeight = 720;

	// set the origin of the text to the centre of it
	static void centreTextOrigin(sf::Text& pText)
	{
		pText.setOrigin(pText.getGlobalBounds().width / 2, 0);
	}

	static sf::Vector2f roundVector2f(const sf::Vector2f pVector2f)
	{
		return sf::Vector2f(std::round(pVector2f.x), std::round(pVector2f.y));
	}

	static sf::Font getFFFForwardFont()
	{
		sf::Font font;
		font.loadFromFile("assets/fonts/FFFFORWA.TTF");
		return font;
	}
}

#endif