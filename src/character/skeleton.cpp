#include "skeleton.hpp"

Skeleton::Skeleton()
{
    this->characterIdleFrameNum = 11;
    std::string filename = "assets/skeleton/Sprite_Sheets/Skeleton_Idle.png";
    this->loadImage(filename);
    this->attack = 10;
    this->defend = 5;
    this->health = 120;
}

Skeleton::~Skeleton()
{
}