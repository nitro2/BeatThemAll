# BeatThemAll
2D fighting game using SFML.

# Compile
```
mkdir build
cd build
cmake ../
cmake --build .
```


# Class
## GameObject
GameObject is drawable object in game. 

GameObject
   ^
   |
   |--- Character
   |        ^
   |        |----- Skeleton
   |        |----- Warrior
   |
   |--- Bullet
   |
   |--- TileMap


## Player
Player is logic object, presents for each player.