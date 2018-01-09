#pragma once
#include "Enemy.h"
#include "Smol.h"
#include "big.h"

enum class EnemyTypes { Smol, Big };

class EnemyFactory
{
public:
	static EnemyFactory* GetInstance();

	Enemy* createEnemy(EnemyTypes type);

private:
	EnemyFactory();
	static EnemyFactory* m_EnemyFactory;
};