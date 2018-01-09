#pragma once
#include "gotoXY.h"
#include "Collision.h"
#include "Player.h"
#include "EnemyMgr.h"

//Player ship
void Ship::drawShip()
	{
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		if (m_X > 3 && m_X < 57) //make sure ship only stays in range
		{
			SetConsoleTextAttribute(hstdout, 23);
			gotoXY(m_X, 25);
			cout << (char)179 << endl;
			gotoXY(m_X - 1, 26);
			cout << "/ \\" << endl;
			gotoXY(m_X - 2, 27);
			cout << "/___\\" << endl;
			gotoXY(m_X - 2, 28);
			cout << (char)179 << "   " << (char)179 << endl;
			gotoXY(m_X - 2, 29);
			cout << (char)179 << "   " << (char)179 << endl;
			gotoXY(m_X - 3, 30);
			cout << "/" << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << "\\" << endl;
			SetConsoleTextAttribute(hstdout, 15);
		}
		else
		{
			m_X = m_PrevX;
		}
	}

void Ship::clearShip()
	{
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hstdout, 15);
		gotoXY(m_PrevX, 25);
		cout << "   " << endl;
		gotoXY(m_PrevX - 1, 26);
		cout << "      " << endl;
		gotoXY(m_PrevX - 2, 27);
		cout << "        " << endl;
		gotoXY(m_PrevX - 2, 28);
		cout << "       " << endl;
		gotoXY(m_PrevX - 2, 29);
		cout << "        " << endl;
		gotoXY(m_PrevX - 3, 30);
		cout << "         ";
		SetConsoleTextAttribute(hstdout, 15);
	}


void Ship::keyDownEvent(int input)
	{
		switch (input)
		{
		case 75://Left
		{
			m_PrevX = m_X;
			m_X--;
			break;
		}
		case 77://Right
		{
			m_PrevX = m_X;
			m_X++;
			break;
		}
		case 72://Up to shoot
		{
			Bullets.push_back(new Bullet(m_X)); //bullets put into a vector
			break;
		}
		case 27:
		{
			exit(0);
			break;
		}
		}

		//deleting/drawing things
		if (m_X > 3 && m_X < 57)
		{
			clearShip();
		}

		drawShip();

	}