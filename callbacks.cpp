#include "callbacks.h"

void windowSizeCallback(GLFWwindow* window, int width, int height)
{
	winWidth = width;
	winHeight = height;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{	
	if (action == GLFW_PRESS)
	{
		if (key >= GLFW_KEY_1 && key <= GLFW_KEY_8)
		{
			GLSecondLab::GetInstance().ToScene(key - GLFW_KEY_1);
		}

		if (key >= GLFW_KEY_A && key <= GLFW_KEY_D)
		{
			GLSecondLab::GetInstance().ToSubScene((GLSecondLab::SubScenes)(key - GLFW_KEY_A));
		}

		switch (key)
		{
			case GLFW_KEY_ESCAPE:
			{
				glfwSetWindowShouldClose(window, 1);
			}
			break;
			case GLFW_KEY_LEFT:
			{
				GLSecondLab::GetInstance().PrevScene();
			}
			break;
			case GLFW_KEY_RIGHT:
			{
				GLSecondLab::GetInstance().NextScene();
			}
			break;
		default:
			break;
		}
	}
}
