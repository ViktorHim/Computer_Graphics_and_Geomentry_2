#include "GLController.h"

void GLController::Start()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		Render();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

void GLController::ToScene(int scene)
{
	if (scene <= sceneCount)
	{
		currentScene = scene;
	}
	std::cout << currentScene << std::endl;
	ConfigureScene(currentScene);
}

void GLController::ToSubScene(SubScenes subScene)
{
	this->subScene = subScene;
	ConfigureScene(currentScene);
}

void GLController::NextScene()
{
	if (currentScene < sceneCount - 1)
	{
		currentScene++;
	}
	else
	{
		currentScene = 0;
	}
	std::cout << currentScene << std::endl;

	ConfigureScene(currentScene);
}

void GLController::PrevScene()
{
	if (currentScene == 0)
	{
		currentScene = sceneCount - 1;
	}
	else
	{
		currentScene--;
	}
	std::cout << currentScene << std::endl;

	ConfigureScene(currentScene);
}

void GLController::Render()
{
	glViewport(0, 0, winWidth, winHeight);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(auto& model : models)
	{
		model.render(mode);
	}
}

void GLController::Init(GLFWwindow* _window)
{
	window = _window;
	currentScene = 0;
	isInit = true;
}
