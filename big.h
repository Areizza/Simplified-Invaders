#pragma once
#include "Enemy.h"

class Big : public Enemy
{
private:
	//randomly generated locations
	int m_X = rand() % 50 + 4;
	int m_Y = rand() % 10 + 4; //spawn higher up than the small ones
	int m_char = 178;

public:
	Big()
	{
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		//draws enemy
		SetConsoleTextAttribute(hstdout, 3);
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
