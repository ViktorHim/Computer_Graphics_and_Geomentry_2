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
#include <algorithm>

using namespace std;

class GLUtils
{
public:
	/// <summary>
	/// Loading a shader from a file
	/// </summary>
	/// <param name="filename">Path to file.</param>
	/// <returns>String with shader code.</returns>
	static string LoadShader(const char* filename);
	/// <summary>
	/// ������� ������������� ����� � �������� ����.
	/// </summary>
	/// <param name="w">������ ����.</param>
	/// <param name="h">������ ����.</param>
	/// <param name="Fullscreen">����� ������� ������. </param>
	/// <param name="title">Window title</param>
	/// <returns>��������� �� ��������� ����.</returns>
	static GLFWwindow* Init(int w = 640, int h = 480, bool Fullscreen = false, string title = "test");
	/// <summary>
	/// Function for correct program termination.
	/// </summary>
	static void Clear();
};

