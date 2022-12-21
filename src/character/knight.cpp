#include "character.hpp"

Knight::Knight()
{
    this->loadImage(State::Idle, CFG_KNIGHT_IMG_IDLE_PATH, CFG_KNIGHT_IMG_IDLE_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(State::Attack, CFG_KNIGHT_IMG_ATTACK_PATH, CFG_KNIGHT_IMG_ATTACK_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(State::Dead, CFG_KNIGHT_IMG_DEAD_PATH, CFG_KNIGHT_IMG_DEAD_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(State::Hit, CFG_KNIGHT_IMG_HIT_PATH, CFG_KNIGHT_IMG_HIT_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(State::Walk, CFG_KNIGHT_IMG_WALK_PATH, CFG_KNIGHT_IMG_WALK_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(State::Jump, CFG_KNIGHT_IMG_JUMP_PATH, CFG_KNIGHT_IMG_JUMP_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME * 3);
    this->attack = CFG_KNIGHT_STAT_ATTACK;
    this->defend = CFG_KNIGHT_STAT_DEFEND;
    this->health = CFG_KNIGHT_STAT_HEALTH;
    this->scale = CFG_KNIGHT_IMG_SCALE;
    this->setState(State::Idle);
}
Knight::~Knight(){};
