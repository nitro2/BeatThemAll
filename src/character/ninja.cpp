#include "character.hpp"

Ninja::Ninja()
{
    this->loadImage(ImageState::Idle, CFG_NINJA_IMG_IDLE_PATH, CFG_NINJA_IMG_IDLE_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Attack, CFG_NINJA_IMG_ATTACK_PATH, CFG_NINJA_IMG_ATTACK_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Dead, CFG_NINJA_IMG_DEAD_PATH, CFG_NINJA_IMG_DEAD_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Hit, CFG_NINJA_IMG_HIT_PATH, CFG_NINJA_IMG_HIT_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Walk, CFG_NINJA_IMG_WALK_PATH, CFG_NINJA_IMG_WALK_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Jump, CFG_NINJA_IMG_JUMP_PATH, CFG_NINJA_IMG_JUMP_FRAMES, CFG_NINJA_IMG_SWITCH_TIME * 3);
    this->attack = CFG_NINJA_STAT_ATTACK;
    this->defend = CFG_NINJA_STAT_DEFEND;
    this->health = CFG_NINJA_STAT_HEALTH;
    this->scale = CFG_NINJA_IMG_SCALE;
    this->setState(ImageState::Idle);
}
Ninja::~Ninja(){};
