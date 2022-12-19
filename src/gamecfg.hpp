#ifndef _GAMECFG_HPP_
#define _GAMECFG_HPP_

// Gravity falling speed
#define CFG_GRAVITATION_ACCELERATION 981.0f

// Common character config
#define CFG_CHARACTER_HEALTH 100
#define CFG_CHARACTER_WIDTH 120.0f
#define CFG_CHARACTER_HEIGHT 160.0f
#define CFG_CHARACTER_ACCELERATION 1000.0f
#define CFG_CHARACTER_SPEED (10000.0f)
#define CFG_CHARACTER_JUMP_HEIGHT (1.0f * CFG_CHARACTER_HEIGHT)

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
#define CFG_WARRIOR_IMG_SWITCH_TIME 0.08f
#define CFG_WARRIOR_IMG_ATTACK_PATH "assets/char/warrior/image/warrior_idle.png"
#define CFG_WARRIOR_IMG_ATTACK_FRAMES
#define CFG_WARRIOR_IMG_DEAD_PATH "assets/char/warrior/image/warrior_dead.png"
#define CFG_WARRIOR_IMG_DEAD_FRAMES
#define CFG_WARRIOR_IMG_HIT_PATH "assets/char/warrior/image/warrior_hit.png"
#define CFG_WARRIOR_IMG_HIT_FRAMES
#define CFG_WARRIOR_IMG_IDLE_PATH "assets/char/warrior/image/warrior_idle.png"
#define CFG_WARRIOR_IMG_IDLE_FRAMES
#define CFG_WARRIOR_IMG_WALK_PATH "assets/char/warrior/image/warrior_walk.png"
#define CFG_WARRIOR_IMG_WALK_FRAMES
#define CFG_WARRIOR_STAT_ATTACK 10
#define CFG_WARRIOR_STAT_DEFEND 5
#define CFG_WARRIOR_STAT_HEALTH CFG_CHARACTER_HEALTH

#endif // _GAMECFG_HPP_
