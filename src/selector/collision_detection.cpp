#include "collision_detection.hpp"

bool pointInRect(float px, float py, float l, float t, float w, float h)
{
	if (px < l || px > l + w)
	{
		return false;
	}
	if (py < t || py > t + h)
	{
		return false;
	}
	return true;
}

bool rectVsRect(float l, float t, float w, float h, float l2, float t2, float w2, float h2)
{
	if (l > l2 + w2 || l2 > l + w)
	{
		return false;
	}
	if (t > t2 + h2 || t2 > t + h)
	{
		return false;
	}
	return true;
}