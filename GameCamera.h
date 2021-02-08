#ifndef GameCamera_hpp
#define GameCamera_hpp
#include "Entity.h"

class GameCamera
{
private:
	float xOffset, yOffset;
	float width, height;
	
public:
	GameCamera(float xOffset, float yOffset);
	void Init(float width, float height);
	void CheckBlankSpace();
	void CenterOnEntity(Entity E);
	void Move(float x, float y);
	float getxOffset();
	float getyOffset();
	void setxOffset(float x);
	void setyOffset(float y);
};

#endif