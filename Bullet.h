#pragma once
#include "gotoXY.h"

//Bullets
class Bullet {

	int m_X;
	int m_Y;

public:
	Bullet() {}
	Bullet(int x) { m_X = x; m_Y = 24; } //sets starting values for bullet (based on position of player)

	//getters
	int getX() { return m_X; } 
	int getY() { return m_Y; }

	//methods
	void moveBullet() { m_Y--; } //bullet moves in one direction (upwards)
	bool boundaryHit();
	void drawBullet();
	void erasePrev();

};