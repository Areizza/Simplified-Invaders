#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <vector>
#include "InputListener.h"
#include "InputManager.h"
#include "Bullet.h"

using namespace std;

//Player ship (OBSERVER)
class Ship : public InputListener
{
public:
	int m_X = 30; //only X, because Y stays the same
	int m_PrevX = 0;
	Ship() {};
	Ship(int x) : m_X(x) {};
	vector<Bullet*> Bullets;
	InputManager* inputMgr;

	//methods
	void drawShip();
	void clearShip();
	void keyDownEvent(int input);

	Ship(InputManager* inputMgr) : inputMgr(inputMgr) {}
};
