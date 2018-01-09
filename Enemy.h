#pragma once
#include "gotoXY.h"

class Enemy
{
private:
	int m_X;
	int m_Y;
	int m_char;

public:
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getChar() = 0;
};
