#pragma once
#include "Enemy.h"

class Smol : public Enemy
{
private:
	//randomly generated location
	int m_X = rand() % 50 + 4;
	int m_Y = rand() % 20 + 4; //spawn lower than the big ones
	int m_char = 232;

public:
	Smol()
	{
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		//draws enemy
		SetConsoleTextAttribute(hstdout, 60);
		gotoXY(m_X, m_Y);
		cout << (char)getChar();
		SetConsoleTextAttribute(hstdout, 15);
	}
	int getX()
	{
		return m_X;
	}

	int getY()
	{
		return m_Y;
	}

	int getChar()
	{
		return m_char;
	}

};