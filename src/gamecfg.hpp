#ifndef _GAMECFG_HPP_
#define _GAMECFG_HPP_

#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)
#include "ResourcePath.hpp"

// Gravity falling speed
#define CFG_GRAVITATION_ACCELERATION 981.0f
#define CFG_GRAVITY_MAX_FALLING 1000.0f

#define CFG_HIT_POWER 4.5f // Move back pixels if being hit

// Common character config
#define CFG_CHARACTER_HEALTH 100
#define CFG_CHARACTER_WIDTH 80.0f
#define CFG_CHARACTER_HEIGHT 112.0f
#define CFG_CHARACTER_ACCELERATION 300.0f
#define CFG_CHARACTER_SPEED (300.0f)
#define CFG_CHARACTER_JUMP_HEIGHT (1.5f * CFG_CHARACTER_HEIGHT)

// Knight
#define CFG_KNIGHT_IMG_SCALE roundf((CFG_CHARACTER_HEIGHT / (350.0f)) * 10) / 10 // Round to 2 decimal point
#define CFG_KNIGHT_IMG_SWITCH_TIME 0.5f
#define CFG_KNIGHT_IMG_ATTACK_PATH "assets/char/knight/image/attack.png"
#define CFG_KNIGHT_IMG_ATTACK_FRAMES 10
#define CFG_KNIGHT_IMG_DEAD_PATH "assets/char/knight/image/dead.png"
#define CFG_KNIGHT_IMG_DEAD_FRAMES 10
#define CFG_KNIGHT_IMG_HIT_PATH "assets/char/knight/image/hit.png"
#define CFG_KNIGHT_IMG_HIT_FRAMES 10
#define CFG_KNIGHT_IMG_IDLE_PATH "assets/char/knight/image/idle.png"
#define CFG_KNIGHT_IMG_IDLE_FRAMES 10
#define CFG_KNIGHT_IMG_WALK_PATH "assets/char/knight/image/walk.png"
#define CFG_KNIGHT_IMG_WALK_FRAMES 10
#define CFG_KNIGHT_IMG_JUMP_PATH "assets/char/knight/image/jump.png"
#define CFG_KNIGHT_IMG_JUMP_FRAMES 10
#define CFG_KNIGHT_STAT_ATTACK 8
#define CFG_KNIGHT_STAT_DEFEND 7
#define CFG_KNIGHT_STAT_HEALTH CFG_CHARACTER_HEALTH

// Ninja
#define CFG_NINJA_IMG_SCALE (CFG_CHARACTER_HEIGHT / (495.0f))
#define CFG_NINJA_IMG_SWITCH_TIME 0.5f
#define CFG_NINJA_IMG_ATTACK_PATH "assets/char/ninja/image/attack.png"
#define CFG_NINJA_IMG_ATTACK_FRAMES 10
#define CFG_NINJA_IMG_DEAD_PATH "assets/char/ninja/image/dead.png"
#define CFG_NINJA_IMG_DEAD_FRAMES 10
#define CFG_NINJA_IMG_HIT_PATH "assets/char/ninja/image/hit.png"
#define CFG_NINJA_IMG_HIT_FRAMES 10
#define CFG_NINJA_IMG_IDLE_PATH "assets/char/ninja/image/idle.png"
#define CFG_NINJA_IMG_IDLE_FRAMES 10
#define CFG_NINJA_IMG_WALK_PATH "assets/char/ninja/image/walk.png"
#define CFG_NINJA_IMG_WALK_FRAMES 10
#define CFG_NINJA_IMG_JUMP_PATH "assets/char/ninja/image/jump.png"
#define CFG_NINJA_IMG_JUMP_FRAMES 10
#define CFG_NINJA_STAT_ATTACK 11
#define CFG_NINJA_STAT_DEFEND 4
#define CFG_NINJA_STAT_HEALTH CFG_CHARACTER_HEALTH

// Skeleton
#define CFG_SKELETON_IMG_SCALE (CFG_CHARACTER_HEIGHT / (32.0f))
#define CFG_SKELETON_IMG_SWITCH_TIME 0.5f
#define CFG_SKELETON_IMG_ATTACK_PATH "assets/char/skeleton/image/attack.png"
#define CFG_SKELETON_IMG_ATTACK_FRAMES 18
#define CFG_SKELETON_IMG_DEAD_PATH "assets/char/skeleton/image/dead.png"
#define CFG_SKELETON_IMG_DEAD_FRAMES 15
#define CFG_SKELETON_IMG_HIT_PATH "assets/char/skeleton/image/hit.png"
#define CFG_SKELETON_IMG_HIT_FRAMES 8
#define CFG_SKELETON_IMG_IDLE_PATH "assets/char/skeleton/image/idle.png"
#define CFG_SKELETON_IMG_IDLE_FRAMES 11
#define CFG_SKELETON_IMG_WALK_PATH "assets/char/skeleton/image/walk.png"
#define CFG_SKELETON_IMG_WALK_FRAMES 13
#define CFG_SKELETON_IMG_JUMP_PATH "assets/char/skeleton/image/jump.png"
#define CFG_SKELETON_IMG_JUMP_FRAMES 13
#define CFG_SKELETON_STAT_ATTACK 10
#define CFG_SKELETON_STAT_DEFEND 5
#define CFG_SKELETON_STAT_HEALTH CFG_CHARACTER_HEALTH

// Warrior
#define CFG_WARRIOR_IMG_SCALE (CFG_CHARACTER_HEIGHT / (350.0f))
#define CFG_WARRIOR_IMG_SWITCH_TIME 0.8f
#define CFG_WARRIOR_IMG_ATTACK_PATH "assets/char/warrior/image/attack.png"
#define CFG_WARRIOR_IMG_ATTACK_FRAMES 10
#define CFG_WARRIOR_IMG_DEAD_PATH "assets/char/warrior/image/dead.png"
#define CFG_WARRIOR_IMG_DEAD_FRAMES 10
#define CFG_WARRIOR_IMG_HIT_PATH "assets/char/warrior/image/hit.png"
#define CFG_WARRIOR_IMG_HIT_FRAMES 10
#define CFG_WARRIOR_IMG_IDLE_PATH "assets/char/warrior/image/idle.png"
#define CFG_WARRIOR_IMG_IDLE_FRAMES 10
#define CFG_WARRIOR_IMG_WALK_PATH "assets/char/warrior/image/walk.png"
#define CFG_WARRIOR_IMG_WALK_FRAMES 10
#define CFG_WARRIOR_IMG_JUMP_PATH "assets/char/warrior/image/jump.png"
#define CFG_WARRIOR_IMG_JUMP_FRAMES 10
#define CFG_WARRIOR_STAT_ATTACK 10
#define CFG_WARRIOR_STAT_DEFEND 5
#define CFG_WARRIOR_STAT_HEALTH CFG_CHARACTER_HEALTH

#endif // _GAMECFG_HPP_
