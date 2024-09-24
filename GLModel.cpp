#include "GLModel.h"

void GLModel::render(GLuint mode)
{
	//�������� ��������� ���������
	glUseProgram(shaderProgramID);
	//���������� ������ ������
	glBindVertexArray(vaoID);
	//���� ������� ���� - ������ �� ���
	if (indexCount > 0)
		glDrawElements(mode, indexCount, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(mode, 0, vertexCount);
}

void GLModel::loadCoords(glm::vec3* verteces, size_t count)
{
	//���������� ������� �������
	vertexCount = count;
	//�������� VBO
	GLuint coords_vbo = 0;
	glGenBuffers(1, &coords_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, coords_vbo);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(glm::vec3),verteces, GL_STATIC_DRAW);
	
	//��� ��� VAO ��� ������, �� ����� ����� ������� � ���
	glBindVertexArray(vaoID);
	//���������� �����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	//����������� ��������
	glEnableVertexAttribArray(0);
}

void GLModel::loadColors(glm::vec3* colors, size_t count)
{
	//������ ��������� �� ��������� � ����� ������ ����� ������
	GLuint colors_vbo = 0;
	glGenBuffers(1, &colors_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(glm::vec3), colors,
		GL_STATIC_DRAW);
	glBindVertexArray(vaoID);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);

}

void GLModel::loadIndexes(GLuint* indices, size_t count)
{
	indexCount = count;
	glBindVertexArray(vaoID);
	GLuint elementbuffer;
	glGenBuffers(1, &elementbuffer); // ��������� ������ ������� ������ ������
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer); //�������� ����������� ������
	//�������� �������� � ������������ ���������� �����
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof
	(GLuint), indices, GL_STATIC_DRAW);
}

void GLModel::loadShaders(const char* vect, const char* frag)
{
	// ���������� ��� ��������� ���������� ���������
	GLint result = GL_FALSE;
	int infoLogLength;
	//�������� ��������� ���������
	shaderProgramID = glCreateProgram();
	//�������� ������� �������� �� ������
	string vstext = GLUtils::LoadShader(vect);
	const char* vertex_shader = vstext.c_str();
	string fstext = GLUtils::LoadShader(frag);
	const char* fragment_shader = fstext.c_str();

	//�������� ���������� �������
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	//�������� ���������� ����������
	glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &infoLogLength);
	//����� ��������� �� ������ ���� ���-�� ����� �� ���
	if (infoLogLength > 0)
	{
		char* errorMessage = new char[infoLogLength + 1];
		glGetShaderInfoLog(vs, infoLogLength, NULL, errorMessage);
		std::cout << errorMessage;
		delete errorMessage;
	}

	//���������� � ����������� ��������
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0)
	{
		char* errorMessage = new char[infoLogLength + 1];
		glGetShaderInfoLog(fs, infoLogLength, NULL, errorMessage);
		std::cout << errorMessage;
		delete errorMessage;
	}

	//������ ���������
	glAttachShader(shaderProgramID, vs);
	glAttachShader(shaderProgramID, fs);

	//������ ������ � ��� ����� ����������� �������� ������� ���������� � �������� �� ���������� ������� ������
	//��� ����� ������� � ��������� ������� ��� ������� ���������������.
	//������ ��� ��� ��� ������, �� ��������� ���
	glBindAttribLocation(shaderProgramID, 0, "vertex_position");
	glBindAttribLocation(shaderProgramID, 1, "vertex_color");

	//���������� ��������� ���������
	glLinkProgram(shaderProgramID);
}


