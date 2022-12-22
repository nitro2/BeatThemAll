#!/bin/bash
# Require install Image magick tool
mogrify -crop 918x700+500+0 *.png
mogrify -resize x350 *.png
convert +append *ATTACK* attack.png
convert +append *DIE* dead.png
convert +append *HURT* hit.png
convert +append *IDLE* idle.png
convert +append *JUMP* jump.png
convert +append *WALK* walk.png
convert +append *RUN* run.png