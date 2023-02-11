#pragma once
#ifndef COLLISION_DETECTION_HPP
#define COLLISION_DETECTION_HPP

bool pointInRect(float px, float py, float l, float t, float w, float h);
bool rectVsRect(float l, float t, float w, float h, float l2, float t2, float w2, float h2);

#endif // !COLLISION_DETECTION_HPP
