#pragma once
#include <vector>
#include "InputListener.h"

using std::vector;

class InputManager
{
public:

	bool Attach(int input);
	void Detach(int input);
	void Notify(int input);

	void SetListeners(InputListener* listener);

	InputManager();

private:


	vector<InputListener*> m_Listeners;
	vector<int> m_RegisterInput;


};