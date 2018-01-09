#include "InputManager.h" 

InputManager::InputManager()
{

}

bool InputManager::Attach(int input)
{

	for (unsigned int i = 0; i < m_RegisterInput.size(); i++)
	{
		if (input == m_RegisterInput[i])
		{
			return false;
		}

	}

	m_RegisterInput.push_back(input);

}
void InputManager::Detach(int input)
{
	for (unsigned int i = 0; i < m_RegisterInput.size(); i++)
	{
		if (input == m_RegisterInput[i])
		{
			m_RegisterInput.erase(m_RegisterInput.begin() + i);
		}
	}

}
void InputManager::Notify(int input)
{
	for (unsigned int i = 0; i < m_RegisterInput.size(); i++)
	{
		if (input == m_RegisterInput[i])
		{
			for (int i = 0; i < m_Listeners.size(); i++)
			{
				m_Listeners[i]->keyDownEvent(input);
			}
			break;
		}
	}
}
void InputManager::SetListeners(InputListener* listener)
{
	m_Listeners.push_back(listener);
}