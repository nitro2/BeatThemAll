#pragma once
#ifndef SELECT_PANEL_HPP
#define SELECT_PANEL_HPP

#define MAX_AVATAR_NUMBER_ON_A_ROW 3
#define GAP_DISTANCE 48
#define AVATAR_SIZE 96

#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include "transform.hpp"
#include "avatar.hpp"
#include "selector.hpp"
#include "select_debug.hpp"
#include "collision_detection.hpp"

class SelectPanel
{
public:
	// leave the default constructor for the compiler
	SelectPanel() = default;
	// parameterized constructor
	SelectPanel(float x, float y);
	// destructor
	~SelectPanel();

	void update(float dt);
	void draw(sf::RenderWindow& window);

	void selfCentering(float x, float y);
	void moveSelector(std::string direction, std::shared_ptr<Selector> selector);
	std::shared_ptr<Selector> selector1, selector2;
	std::pair<float, float> checkValidMove(std::string direction, float originX, float originY);
private:
	Transform mTransform;
	std::vector<std::shared_ptr<Avatar>> avatarList;
	std::vector<float> moveEntryX;
	void moveEntryInit();
	void setPanelSizeAndAddAvatars();
	void addSelector();
};

#endif // !SELECT_PANEL_HPP
