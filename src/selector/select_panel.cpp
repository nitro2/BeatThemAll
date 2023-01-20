#include "select_panel.hpp"

namespace select_panelNS
{
	void tokenize(std::string const& str, const char delim, std::vector<std::string>& out)
	{
		std::stringstream ss(str);
		std::string s;
		while (std::getline(ss, s, delim))
		{
			out.push_back(s);
		}
	}
	void getCharacterAvatarConfigInfo(std::vector<std::string>& characterAvatarPaths,
		std::vector<std::vector<int>>& characterAvatarCropRects)
	{
		// read character avatar from file
		std::ifstream characterFile("../src/selector/character.txt");
		if (!characterFile.is_open())
		{
			std::cout << "Open character.txt failed.\n";
		}
		std::string s;
		while (std::getline(characterFile, s))
		{
			std::vector<std::string> words;
			tokenize(s, ' ', words);
			characterAvatarPaths.push_back(words[0]);
			std::vector<int> temp;
			
			temp.push_back(std::stoi(words[1]));
			temp.push_back(std::stoi(words[2]));
			temp.push_back(std::stoi(words[3]));
			temp.push_back(std::stoi(words[4]));
			characterAvatarCropRects.push_back(temp);
		}
		characterFile.close();
	}
}

using namespace select_panelNS;// This allows the helper classes and functions
                       // to be used in the .cpp file without explicit use
                       // of the namespace.

SelectPanel::SelectPanel(float x, float y) : mTransform {x, y}
{
	setPanelSizeAndAddAvatars();
	addSelector();
	moveEntryInit();
}

SelectPanel::~SelectPanel()
{

}

void SelectPanel::selfCentering(float x, float y)
{
	float deltaX{ (x - mTransform.getWidth() / 2) - mTransform.getX()};
float deltaY{ (y - mTransform.getHeight() / 2) - mTransform.getY() };
mTransform.selfCenteringX(x);
mTransform.selfCenteringY(y);
for (size_t i = 0; i < avatarList.size(); i++)
{
	avatarList[i]->setX(avatarList[i]->getX() + deltaX);
	avatarList[i]->setY(avatarList[i]->getY() + deltaY);
}
selector1->setX(selector1->getX() + deltaX);
selector1->setY(selector1->getY() + deltaY);

selector2->setX(selector2->getX() + deltaX);
selector2->setY(selector2->getY() + deltaY);
}

void SelectPanel::moveEntryInit()
{
	// add entries in order of priority - go down
	moveEntryX.push_back(0);
	float space = GAP_DISTANCE + AVATAR_SIZE;
	moveEntryX.push_back(-space / 2);
	moveEntryX.push_back(space / 2);
	moveEntryX.push_back(-space);
	moveEntryX.push_back(space);

}

std::pair<float, float> SelectPanel::checkValidMove(std::string direction, float originX, float originY)
{
	float entryX = originX;
	float entryY = originY;
	float space = GAP_DISTANCE + AVATAR_SIZE;
	if (direction == "left")
	{
		entryX -= space;
		for (size_t i = 0; i < avatarList.size(); i++)
		{
			float avatarX{ avatarList[i]->getX() };
			float avatarY{ avatarList[i]->getY() };
			if (rectVsRect(entryX, entryY, AVATAR_SIZE, AVATAR_SIZE, avatarX, avatarY, AVATAR_SIZE, AVATAR_SIZE))
			{
				return std::make_pair(avatarX, avatarY);
			}
		}
	}
	else if (direction == "right")
	{
		entryX += space;
		for (size_t i = 0; i < avatarList.size(); i++)
		{
			float avatarX{ avatarList[i]->getX() };
			float avatarY{ avatarList[i]->getY() };
			if (rectVsRect(entryX, entryY, AVATAR_SIZE, AVATAR_SIZE, avatarX, avatarY, AVATAR_SIZE, AVATAR_SIZE))
			{
				return std::make_pair(avatarX, avatarY);
			}
		}
	}
	else if (direction == "up")
	{
		for (size_t i = 0; i < moveEntryX.size(); i++)
		{
			for (size_t j = 0; j < avatarList.size(); j++)
			{
				float avatarX{ avatarList[j]->getX() };
				float avatarY{ avatarList[j]->getY() };
				if (rectVsRect(entryX + moveEntryX[i], entryY - space, AVATAR_SIZE, AVATAR_SIZE,
					avatarX, avatarY, AVATAR_SIZE, AVATAR_SIZE))
				{
					return std::make_pair(avatarX, avatarY);
				}
			}
		}
	}
	else if (direction == "down")
	{
		for (size_t i = 0; i < moveEntryX.size(); i++)
		{
			for (size_t j = 0; j < avatarList.size(); j++)
			{
				float avatarX{ avatarList[j]->getX() };
				float avatarY{ avatarList[j]->getY() };
				if (rectVsRect(entryX + moveEntryX[i], entryY + space, AVATAR_SIZE, AVATAR_SIZE,
					avatarX, avatarY, AVATAR_SIZE, AVATAR_SIZE))
				{
					return std::make_pair(avatarX, avatarY);
				}
			}
		}
	}
	return std::make_pair(0, 0);
}

void SelectPanel::moveSelector(std::string direction, std::shared_ptr<Selector> selector)
{
	std::pair<float, float> dest = checkValidMove(direction, selector->getX(), selector->getY());
	if (dest.first == 0 || dest.second == 0) return;
	selector->setX(dest.first);
	selector->setY(dest.second);
	selector->pullSpring(0.5f);
}

void SelectPanel::addSelector()
{
	selector1 = std::make_shared<Selector>(mTransform.getX() + GAP_DISTANCE, 
		mTransform.getY() + GAP_DISTANCE, AVATAR_SIZE, AVATAR_SIZE);
	selector2 = std::make_shared<Selector>(mTransform.getX() + GAP_DISTANCE*2 + AVATAR_SIZE,
		mTransform.getY() + GAP_DISTANCE, AVATAR_SIZE, AVATAR_SIZE);
}

void SelectPanel::setPanelSizeAndAddAvatars()
{
	std::vector<std::string> characterAvatarPaths;
	std::vector<std::vector<int>> characterAvatarCropRects;
	getCharacterAvatarConfigInfo(characterAvatarPaths, characterAvatarCropRects);
	
	int characterNum = characterAvatarPaths.size();
	int rowNum = std::ceil(1.0f * characterNum / MAX_AVATAR_NUMBER_ON_A_ROW);
	int colNum{ 0 };
	int count{ 0 };
	if (characterNum < MAX_AVATAR_NUMBER_ON_A_ROW)
	{
		colNum = characterNum;
	}
	else
	{
		colNum = MAX_AVATAR_NUMBER_ON_A_ROW;
	}
	// calculate the size so that the panel can fit avatars
	mTransform.setWidth(colNum * AVATAR_SIZE + (colNum + 1) * GAP_DISTANCE);
	mTransform.setHeight(rowNum * AVATAR_SIZE + (rowNum + 1) * GAP_DISTANCE);
	//
	int currRow = 0;
	while (characterNum > 0)
	{
		float startX{};
		float startY{};
		if (characterNum >= MAX_AVATAR_NUMBER_ON_A_ROW)
		{
			startX = mTransform.getX() + GAP_DISTANCE;
			startY = mTransform.getY() + GAP_DISTANCE;
			for (int i = 0; i < MAX_AVATAR_NUMBER_ON_A_ROW; i++)
			{
				avatarList.push_back(std::make_shared<Avatar>(startX + i * (GAP_DISTANCE + AVATAR_SIZE),
					startY + currRow * (GAP_DISTANCE + AVATAR_SIZE),
					characterAvatarPaths[count],
					sf::IntRect(characterAvatarCropRects[count][0],
								characterAvatarCropRects[count][1],
								characterAvatarCropRects[count][2],
								characterAvatarCropRects[count][3])));
				count++;
			}
			characterNum -= MAX_AVATAR_NUMBER_ON_A_ROW;
			currRow++;
		}
		else
		{
			startX = mTransform.getX()
				+ ( mTransform.getWidth()
				- (characterNum * AVATAR_SIZE + (characterNum + 1) * GAP_DISTANCE) ) /2 
				+ GAP_DISTANCE;
			startY = mTransform.getY() 
				+ GAP_DISTANCE;
			for (int i = 0; i < characterNum; i++)
			{
				avatarList.push_back(std::make_shared<Avatar>(startX + i * (GAP_DISTANCE + AVATAR_SIZE),
					startY + currRow * (GAP_DISTANCE + AVATAR_SIZE),
					characterAvatarPaths[count], 
					sf::IntRect(characterAvatarCropRects[count][0],
								characterAvatarCropRects[count][1],
								characterAvatarCropRects[count][2],
								characterAvatarCropRects[count][3])));
				count++;
			}
			characterNum = 0;
		}
	}
}

void SelectPanel::update(float dt)
{
	for (size_t i = 0; i < avatarList.size(); i++)
	{
		avatarList[i]->update(dt);
	}
	selector1->update(dt);
	selector2->update(dt);
}

void SelectPanel::draw(sf::RenderWindow& window)
{
	drawDebugRectangle(mTransform, window, sf::Color(150, 150, 150));
	for (size_t i = 0; i < avatarList.size(); i++)
	{
		avatarList[i]->draw(window);
	}
	selector1->draw(window);
	selector2->draw(window);
}