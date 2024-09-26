#include "GLSecondLab.h"
#define SCENE_COUNT 8
#define N 7

void GLSecondLab::ConfigureScene(int scene)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	models.clear();

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
	this->mode = GL_TRIANGLES;
	this->scale = 400;
	FirstTask();
}

void GLSecondLab::FirstTask()
{
	GLModel model = GLModel(window);
	vector<glm::vec3> points;

	double offsetAngle = (360 / (float)N) / 180 * PI;

	for (int i = 0; i < N; i++)
	{
		float x = scale * cos(offsetAngle * i) / winWidth;
		float y = scale * sin(offsetAngle * i) / winHeight;
		points.push_back({ x, y, 0.0f });
	}

	model.loadCoords(points.data(), points.size());
	model.loadShaders("mono_vs.glsl", "mono_fs.glsl");

	glPointSize(15);
	glEnable(GL_POINT_SMOOTH);

	mode = GL_POINTS;
	models.push_back(model);
}

void GLSecondLab::SecondTask()
{
	GLModel model = GLModel(window);
	vector<glm::vec3> points;

	float offsetAngle = (360 / (float)N) / 180 * PI;

	for (int i = 0; i < N; i++)
	{
		float x = scale * cos(offsetAngle * i) / winWidth;
		float y = scale * sin(offsetAngle * i) / winHeight;
		points.push_back({x, y, 0.0f});
		std::cout << x << " " << y << std::endl;
	}

	model.loadCoords(points.data(), points.size());
	model.loadShaders("mono_vs.glsl", "mono_fs.glsl");

	glLineWidth(5);
	glEnable(GL_LINE_SMOOTH);

	mode = GL_LINE_LOOP;
	models.push_back(model);
}

void GLSecondLab::ThirdTask()
{
	GLModel model = GLModel(window);

	vector<glm::vec3> points = {
		{-0.6f, 0.6f, 0.0f},
		{-0.5f, -0.6f, 0.0f},   
		{-0.3f, 0.0f, 0.0f},   
		{0.3f, 0.0f, 0.0f}, 
		{0.2f, 0.7f, 0.0f},
		{0.7f, 0.7f, 0.0f},
		{0.25f, -0.7f, 0.0f},
	};

	model.loadCoords(points.data(), points.size());
	model.loadShaders("mono_vs.glsl", "mono_fs.glsl");

	glLineWidth(5);
	glEnable(GL_LINE_SMOOTH);

	mode = GL_LINE_STRIP;
	models.push_back(model);
}

void GLSecondLab::FourTask()
{
	GLModel model = GLModel(window);

	vector<glm::vec3> points = {
		{0.8f, -0.8f, 0.0f},
		{0.8f, -0.4f, 0.0f},
		{0.2f, -0.4f, 0.0f},
		{0.2f, 0.4f, 0.0f},
		{0.9f, 0.8f, 0.0f},
		{-0.9f, 0.8f, 0.0f},
		{-0.1f, 0.0f, 0.0f},
		{-0.4f, -0.8f, 0.0f},
	};

	model.loadCoords(points.data(), points.size());
	model.loadShaders("mono_vs.glsl", "mono_fs.glsl");

	glLineWidth(5);
	glEnable(GL_LINE_SMOOTH);

	mode = GL_LINE_LOOP;
	models.push_back(model);
}

void GLSecondLab::FiveTask()
{
	GLModel model = GLModel(window);
	vector<glm::vec3> colors;
	//glm::vec3 points[] = {
	//	{0.8f, -0.8f, 0.0f},
	//	{0.8f, -0.4f, 0.0f},
	//	{0.2f, -0.4f, 0.0f},
	//	{0.2f, 0.4f, 0.0f},
	//	{0.9f, 0.8f, 0.0f},
	//	{-0.9f, 0.8f, 0.0f},
	//	{-0.1f, 0.0f, 0.0f},
	//	{-0.4f, -0.8f, 0.0f},
	//};
	vector<glm::vec3> pointsA =
	{
		{0.8f, -0.8f, 0.0f},
		{0.8f, -0.4f, 0.0f},
		{0.2f, -0.4f, 0.0f},

		{0.8f, -0.8f, 0.0f},
		{0.2f, -0.4f, 0.0f},
		{-0.4f, -0.8f, 0.0f},

		{0.2f, -0.4f, 0.0f},
		{-0.1f, 0.0f, 0.0f},
		{-0.4f, -0.8f, 0.0f},

		{0.2f, -0.4f, 0.0f},
		{0.2f, 0.4f, 0.0f},
		{-0.1f, 0.0f, 0.0f},

		{0.2f, 0.4f, 0.0f},
		{-0.1f, 0.0f, 0.0f},
		{-0.9f, 0.8f, 0.0f},

		{0.2f, 0.4f, 0.0f},
		{0.9f, 0.8f, 0.0f},
		{-0.9f, 0.8f, 0.0f},
	};

	vector<glm::vec3> pointsB =
	{
		{0.9f, 0.8f, 0.0f}, // 5
		{-0.9f, 0.8f, 0.0f}, // 6
		{0.2f, 0.4f, 0.0f}, // 4
		{-0.1f, 0.0f, 0.0f}, //7
		{0.2f, -0.4f, 0.0f}, // 3
		{-0.4f, -0.8f, 0.0f}, // 8
		{0.8f, -0.4f, 0.0f}, // 2
		{0.8f, -0.8f, 0.0f},
	};

	vector<glm::vec3> pointsC_1 =
	{
		{-0.4f, -0.8f, 0.0f},
		{0.8f, -0.8f, 0.0f},
		{0.8f, -0.4f, 0.0f},
		{0.2f, -0.4f, 0.0f},
		{0.2f, 0.4f, 0.0f},
		{-0.1f, 0.0f, 0.0f},
	};

	vector<glm::vec3> pointsC_2 =
	{
		{-0.9f, 0.8f, 0.0f},
		{0.9f, 0.8f, 0.0f},
		{0.2f, 0.4f, 0.0f},
		{-0.1f, 0.0f, 0.0f},
	};

	for (int i = 0; i < 6; i++)
	{
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
	}

	switch (subScene)
	{
	case GLController::SubScenes::A: 
	{
		model.loadCoords(pointsA.data(), pointsA.size());
		model.loadColors(colors.data(), colors.size());
		mode = GL_TRIANGLES;
	}
		break;
	case GLController::SubScenes::B:
	{
		model.loadCoords(pointsB.data(), pointsB.size());
		model.loadColors(colors.data(), colors.size());
		mode = GL_TRIANGLE_STRIP;
	}
		break;
	case GLController::SubScenes::C:
	{
		GLModel model2 = GLModel(window);

		model.loadCoords(pointsC_1.data(), pointsC_1.size());
		model.loadColors(colors.data(), colors.size());

		model2.loadCoords(pointsC_2.data(), pointsC_2.size());
		model2.loadColors(colors.data(), colors.size());
		model2.loadShaders("mono_vs.glsl", "mono_fs.glsl");
		models.push_back(model2);
		mode = GL_TRIANGLE_FAN;
	}
		break;
	default:
	{
		model.loadCoords(pointsA.data(), pointsA.size());
		model.loadColors(colors.data(), colors.size());
		mode = GL_TRIANGLES;
	}
		break;
	}

	model.loadShaders("mono_vs.glsl", "mono_fs.glsl");
	models.push_back(model);
}

void GLSecondLab::SixTask()
{
	GLModel model = GLModel(window);
	vector<glm::vec3> points;
	vector<glm::vec3> colors;

	float offsetAngle = (360 / (float)N) / 180 * PI;

	for (int i = 0; i < N; i++)
	{
		float x = scale * cos(offsetAngle * i) / winWidth;
		float y = scale * sin(offsetAngle * i) / winHeight;
		points.push_back({ x, y, 0.0f });
		std::cout << x << " " << y << std::endl;
	}

	for (int i = 0; i < 6; i++)
	{
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
	}

	model.loadColors(colors.data(), colors.size());
	model.loadCoords(points.data(), points.size());
	model.loadShaders("mono_vs.glsl", "mono_fs.glsl");

	glLineWidth(5);
	glEnable(GL_LINE_SMOOTH);

	mode = GL_TRIANGLE_FAN;
	models.push_back(model);
}

void GLSecondLab::SevenTask()
{
	GLModel model = GLModel(window);
	vector<glm::vec3> colors;
	vector<glm::vec3> points = {

			{0.2f, -0.2f, 0.0f},
			{-0.3f, -0.1f, 0.0f},
			{0.0f, -0.5f, 0.0f},
		
			{0.0f, -0.5f, 0.0f},
			{-0.3f, -0.1f, 0.0f},
			{-0.6f, 0.0f, 0.0f},

			{-0.3f, -0.1f, 0.0f},
			{-0.6f, 0.0f, 0.0f},
			{-0.1f, 0.8f, 0.0f},

			{-0.3f, -0.1f, 0.0f},
			{-0.1f, 0.8f, 0.0f},
			{0.1f, 0.4f, 0.0f},

			{0.1f, 0.4f, 0.0f},
			{0.1f, 0.4f, 0.0f},
			{0.7f, 0.7f, 0.0f},

			{0.7f, 0.7f, 0.0f},
			{-0.1f, 0.8f, 0.0f},
			{0.1f, 0.4f, 0.0f},

			{0.8f, 0.0f, 0.0f},
			{0.7f, 0.7f, 0.0f},
			{0.1f, 0.4f, 0.0f},

			{0.1f, 0.4f, 0.0f},
			{0.3f, -0.4f, 0.0f},
			{0.8f, 0.0f, 0.0f},
	};

	for (int i = 0; i < 8; i++)
	{
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
	}

	model.loadCoords(points.data(), points.size());
	model.loadColors(colors.data(), colors.size());

	switch (subScene)
	{
	case GLController::SubScenes::A: 
	{
		model.loadShaders("mono_vs.glsl", "mono_fs.glsl");
	}
		break;
	case GLController::SubScenes::B:
	{
		model.loadShaders("grad_vs.glsl", "grad_fs.glsl");
	}
		break;
	default:
	{
		model.loadShaders("mono_vs.glsl", "mono_fs.glsl");
	}
		break;
	}

	mode = GL_TRIANGLES;
	models.push_back(model);
}

void GLSecondLab::EightTask()
{
	GLModel model = GLModel(window);
	vector<glm::vec3> colors;
	vector<glm::vec3> points = {

			{0.2f, -0.2f, 0.0f},
			{-0.3f, -0.1f, 0.0f},
			{0.0f, -0.5f, 0.0f},

			{0.0f, -0.5f, 0.0f},
			{-0.3f, -0.1f, 0.0f},
			{-0.6f, 0.0f, 0.0f},

			{-0.3f, -0.1f, 0.0f},
			{-0.6f, 0.0f, 0.0f},
			{-0.1f, 0.8f, 0.0f},

			{-0.3f, -0.1f, 0.0f},
			{-0.1f, 0.8f, 0.0f},
			{0.1f, 0.4f, 0.0f},

			{0.1f, 0.4f, 0.0f},
			{0.1f, 0.4f, 0.0f},
			{0.7f, 0.7f, 0.0f},

			{0.7f, 0.7f, 0.0f},
			{-0.1f, 0.8f, 0.0f},
			{0.1f, 0.4f, 0.0f},

			{0.8f, 0.0f, 0.0f},
			{0.7f, 0.7f, 0.0f},
			{0.1f, 0.4f, 0.0f},

			{0.1f, 0.4f, 0.0f},
			{0.3f, -0.4f, 0.0f},
			{0.8f, 0.0f, 0.0f},
	};

	for (int i = 0; i < 8; i++)
	{
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
		colors.push_back({ (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX });
	}

	model.loadCoords(points.data(), points.size());
	model.loadColors(colors.data(), colors.size());

	switch (subScene)
	{
	case GLController::SubScenes::A:
	{
		model.loadShaders("mono_vs.glsl", "mono_fs.glsl");
		glPolygonMode (GL_FRONT, GL_POINT);
	}
	break;
	case GLController::SubScenes::B:
	{
		model.loadShaders("grad_vs.glsl", "grad_fs.glsl");
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_LINE);

	}
	break;
	case GLController::SubScenes::C:
	{
		model.loadShaders("grad_vs.glsl", "grad_fs.glsl");
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	}
	break;
	default:
	{
		model.loadShaders("mono_vs.glsl", "mono_fs.glsl");
		glPolygonMode(GL_FRONT, GL_POINT);
	}
	break;
	}
	mode = GL_TRIANGLES;
	models.push_back(model);
}