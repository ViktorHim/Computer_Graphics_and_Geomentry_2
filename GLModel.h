#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "GLUtils.h"
using namespace std;

class GLModel
{	
private:
	/// <summary>
	/// Vertex array object ID
	/// </summary>
	GLuint vaoID = -1;
	size_t vertexCount = 0;
	size_t indexCount = 0;
	/// <summary>
	/// Shader program ID
	/// </summary>
	GLuint shaderProgramID = -1;
	/// <summary>
	/// Window pointer
	/// </summary>
	GLFWwindow* window;
public:
	/// <summary>
	/// Простой конструктор - создаёт массив вершин, пока пустой. И
	/// подключает окно.
	/// </summary>
	/// <param name="w"></param>
	GLModel(GLFWwindow* w) {
		glGenVertexArrays(1, &vaoID);
		window = w;
	};
	~GLModel() {};
	void render(GLuint mode = GL_TRIANGLES);
	void loadCoords(glm::vec3* verteces, size_t count);
	void loadColors(glm::vec3* colors, size_t count);
	void loadIndexes(GLuint * indices, size_t count);
	void loadShaders(const char* vect, const char* frag);
};

