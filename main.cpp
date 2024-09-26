#include "GLUtils.h"
#include "GLModel.h"
#include "GLSecondLab.h"

// GL_POINTS - �����
// GL_LINES - ��������� �����
// GL_LINE_STRIP - �������� �����
// GL_LINE_LOOP - ��������� ��������
// GL_TRIANGLES - ��������� ������������
// GL_TRIANGLE_STRIP - ����� �������������
// GL_TRIANGLE_FAN - ���� �������������

//GL_FILL � ����� ������ � ��������
//GL_LINE � ��������� ����� (������ �������)
//GL_POINT � ��������� ������ �������

//������ �������� ���������� ��� ����� ������ ���������� ����� :
//GL_FRONT � �������;
//GL_BACK � ��������;
//GL_FRONT_AND_BACK � ������� � ��������.
//glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

int winWidth;
int winHeight;

int main() 
{
	GLFWwindow* window = GLUtils::Init(1024, 768, false, "sample");
	if (window == nullptr)
	{
		GLUtils::Clear();
		return -1;
	}

	GLSecondLab::GetInstance().Init(window);
	GLSecondLab::GetInstance().Start();
	
	GLUtils::Clear();
	return 0;
}