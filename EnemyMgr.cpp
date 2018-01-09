#include "EnemyMgr.h"

EnemyFactory* EnemyFactory::m_EnemyFactory = 0;

EnemyFactory* EnemyFactory::GetInstance()
{
	if (m_EnemyFactory == 0)
		m_EnemyFactory = new EnemyFactory();
	return m_EnemyFactory;
}

EnemyFactory::EnemyFactory() {}

Enemy* EnemyFactory::createEnemy(EnemyTypes type)
{
	switch (type)
	{
	case EnemyTypes::Smol:
		return new Smol();
		break;
	case EnemyTypes::Big:
		return new Big();
		break;
	default:
		break;
	}
}