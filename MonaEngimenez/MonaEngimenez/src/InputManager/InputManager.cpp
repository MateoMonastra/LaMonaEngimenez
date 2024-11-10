#include "InputManager.h"


	InputManager::InputManager(GLFWwindow* window)
	{
		this->window = window;
	}

	bool InputManager::GetKey(KeyCode key, Action keyAction)
	{
		if (window == nullptr)
		{
			throw std::runtime_error("Window is nullptr");
			return false;
		}

		int state;

		switch (keyAction)
		{
			case Pressed:
			{
				state = glfwGetKey(window, key);
				return state == Action::Pressed;
				break;
			}
			case Reapeated:
			{
				state = glfwGetKey(window, key);
				return state == Action::Reapeated;
				break;
			}
			case Released:
			{
				state = glfwGetKey(window, key);
				return state == Action::Released;
				break;
			}	
			default:
			{
				return false;
				break;
			}
		}
	}
