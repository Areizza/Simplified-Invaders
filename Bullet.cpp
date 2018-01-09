#include "gotoXY.h"
#include "Bullet.h"

bool Bullet::boundaryHit() //check if bullet has reached the top of the screen (y value = 0)
{
	if (m_Y == 0)
	{
		return true;
	}
	return false;
}

void Bullet:: drawBullet() //draw the bullet
{
	gotoXY(m_X, m_Y);
	cout << (char)248;
}

void Bullet::erasePrev() //"erase" the previously drawn bullet
{
	gotoXY(m_X, m_Y);
	cout << ' ';
}