#include "InputManager.h"


	InputManager::InputManager(GLFWwindow* window)
	{
		this->window = window;
	}

	bool InputManager::getKey(KeyCode key, Action keyAction)
	{
		if (window == nullptr)
		{
			return;
		}

		int state;

		switch (keyAction)
		{
		case InputManager::Pressed:
			state = glfwGetKey(window, key);
			return state == Action::Pressed;
			break;

		case InputManager::Reapeated:
			state = glfwGetKey(window, key);
			return state == Action::Reapeated;
			break;

		case InputManager::Released:
			state = glfwGetKey(window, key);
			return state == Action::Released;
			break;
		default:
			return false;
			break;
		}
		return false;
	}
