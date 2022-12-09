#ifndef _GAME_OBJECT_HPP_
#define _GAME_OBJECT_HPP_

class GameObject
{
public:
    GameObject(){};
    ~GameObject(){};

    // Movement
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

private:
    float width;
    float height;
    float x;
    float y;
};

#endif // _GAME_OBJECT_HPP_
