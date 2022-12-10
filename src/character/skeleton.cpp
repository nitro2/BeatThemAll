#include "skeleton.hpp"

Skeleton::Skeleton()
{
    std::cout << __FUNCTION__ << " at line " << __LINE__ << std::endl;
    this->characterIdleFrameNum = 11;
    std::string filename = "assets/skeleton/Skeleton/Sprite_Sheets/Skeleton_Idle.png";
    this->characterTexture.loadFromFile(filename);
    this->setTexture(this->characterTexture);
    this->setTextureRect(sf::IntRect(0, 0, this->characterTexture.getSize().x / this->characterIdleFrameNum,
                                     this->characterTexture.getSize().y));
}

Skeleton::~Skeleton()
{
}