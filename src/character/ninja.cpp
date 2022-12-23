#include "character.hpp"

Ninja::Ninja()
{
    this->loadImage(State::Idle, CFG_NINJA_IMG_IDLE_PATH, CFG_NINJA_IMG_IDLE_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(State::Attack, CFG_NINJA_IMG_ATTACK_PATH, CFG_NINJA_IMG_ATTACK_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(State::Dead, CFG_NINJA_IMG_DEAD_PATH, CFG_NINJA_IMG_DEAD_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(State::Hit, CFG_NINJA_IMG_HIT_PATH, CFG_NINJA_IMG_HIT_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(State::Walk, CFG_NINJA_IMG_WALK_PATH, CFG_NINJA_IMG_WALK_FRAMES, CFG_NINJA_IMG_SWITCH_TIME);
    this->loadImage(State::Jump, CFG_NINJA_IMG_JUMP_PATH, CFG_NINJA_IMG_JUMP_FRAMES, CFG_NINJA_IMG_SWITCH_TIME * 3);
    this->attack = CFG_NINJA_STAT_ATTACK;
    this->defend = CFG_NINJA_STAT_DEFEND;
    this->health = CFG_NINJA_STAT_HEALTH;
    this->scale = CFG_NINJA_IMG_SCALE;
    this->setState(State::Idle);
}
Ninja::~Ninja(){};
