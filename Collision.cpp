#include "Collision.h"

bool collision(Bullet &bullet, Enemy &Enemies) //when bullet collides with enemy, enemy loses health and/or get deleted
{
	if (bullet.getX() == Enemies.getX() && bullet.getY() == Enemies.getY())
	{
		//bullet.~Bullet();
		return true;
	}
	return false;
}