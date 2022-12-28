#include "character.hpp"

Warrior::Warrior()
{
    this->loadImage(ImageState::Idle, CFG_WARRIOR_IMG_IDLE_PATH, CFG_WARRIOR_IMG_IDLE_FRAMES, CFG_WARRIOR_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Attack, CFG_WARRIOR_IMG_ATTACK_PATH, CFG_WARRIOR_IMG_ATTACK_FRAMES, CFG_WARRIOR_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Dead, CFG_WARRIOR_IMG_DEAD_PATH, CFG_WARRIOR_IMG_DEAD_FRAMES, CFG_WARRIOR_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Hit, CFG_WARRIOR_IMG_HIT_PATH, CFG_WARRIOR_IMG_HIT_FRAMES, CFG_WARRIOR_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Walk, CFG_WARRIOR_IMG_WALK_PATH, CFG_WARRIOR_IMG_WALK_FRAMES, CFG_WARRIOR_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Jump, CFG_WARRIOR_IMG_JUMP_PATH, CFG_WARRIOR_IMG_JUMP_FRAMES, CFG_WARRIOR_IMG_SWITCH_TIME * 3);
    this->attack = CFG_WARRIOR_STAT_ATTACK;
    this->defend = CFG_WARRIOR_STAT_DEFEND;
    this->health = CFG_WARRIOR_STAT_HEALTH;
    this->scale = CFG_WARRIOR_IMG_SCALE;
    this->setState(ImageState::Idle);
}
Warrior::~Warrior(){};
