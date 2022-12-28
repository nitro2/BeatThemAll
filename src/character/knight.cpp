#include "character.hpp"

Knight::Knight()
{
    this->loadImage(ImageState::Idle, CFG_KNIGHT_IMG_IDLE_PATH, CFG_KNIGHT_IMG_IDLE_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Attack, CFG_KNIGHT_IMG_ATTACK_PATH, CFG_KNIGHT_IMG_ATTACK_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Dead, CFG_KNIGHT_IMG_DEAD_PATH, CFG_KNIGHT_IMG_DEAD_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Hit, CFG_KNIGHT_IMG_HIT_PATH, CFG_KNIGHT_IMG_HIT_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Walk, CFG_KNIGHT_IMG_WALK_PATH, CFG_KNIGHT_IMG_WALK_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME);
    this->loadImage(ImageState::Jump, CFG_KNIGHT_IMG_JUMP_PATH, CFG_KNIGHT_IMG_JUMP_FRAMES, CFG_KNIGHT_IMG_SWITCH_TIME * 3);
    this->attack = CFG_KNIGHT_STAT_ATTACK;
    this->defend = CFG_KNIGHT_STAT_DEFEND;
    this->health = CFG_KNIGHT_STAT_HEALTH;
    this->scale = CFG_KNIGHT_IMG_SCALE;
    this->setState(ImageState::Idle);
}
Knight::~Knight(){};
