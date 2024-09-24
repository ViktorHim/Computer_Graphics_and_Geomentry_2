#include "GLSecondLab.h"
#define SCENE_COUNT 8

void GLSecondLab::ConfigureScene(int scene)
{
	switch (scene)
	{
		case 0:
		{
			FirstTask();
		}
		break;
		case 1:
		{
			SecondTask();
		}
		break;
		case 2:
		{
			ThirdTask();
		}
		break;
		case 3:
		{
			FourTask();
		}
		break;
		case 4:
		{
			FiveTask();
		}
		break;
		case 5:
		{
			SixTask();
		}
		break;
		case 6:
		{
			SevenTask();
		}
		break;
		case 7:
		{
			EightTask();
		}
		break;
	default:
		break;
	}
}

void GLSecondLab::Init(GLFWwindow* window)
{
	GLController::Init(window);
	this->sceneCount = SCENE_COUNT;	
	FirstTask();
}

void GLSecondLab::FirstTask()
{
	delete currentModel;
	currentModel = new GLModel(window);

	glm::vec3 points[] = {
		{0.0f, 0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f},
		{-0.5f, -0.5f, 0.0f}
	};
	glm::vec3 colors[] = {
		{1.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};

	GLuint indices[] = { 0, 1, 2 };

	currentModel->loadCoords(points, 3);
	currentModel->loadColors(colors, 3);
	currentModel->loadIndexes(indices, 3);

	currentModel->loadShaders("vs.glsl", "fs.glsl");
}

void GLSecondLab::SecondTask()
{
	delete currentModel;
	currentModel = new GLModel(window);

	glm::vec3 points[] = {
	{0.0f, 0.7f, 0.0f},
	{0.6f, -0.4f, 0.0f},
	{-0.9f, -0.2f, 0.0f}
	};
	glm::vec3 colors[] = {
		{1.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};

	GLuint indices[] = { 0, 1, 2 };

	currentModel->loadCoords(points, 3);
	currentModel->loadColors(colors, 3);
	currentModel->loadIndexes(indices, 3);
	currentModel->loadShaders("vs.glsl", "fs.glsl");
}

void GLSecondLab::ThirdTask()
{
}

void GLSecondLab::FourTask()
{
}

void GLSecondLab::FiveTask()
{
}

void GLSecondLab::SixTask()
{
}

void GLSecondLab::SevenTask()
{
}

void GLSecondLab::EightTask()
{
}
