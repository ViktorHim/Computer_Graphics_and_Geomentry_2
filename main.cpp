#include "GLUtils.h"
#include "GLModel.h"
#include "GLSecondLab.h"

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

	GLSecondLab::GetInstance().Init(window, functions);
	GLSecondLab::GetInstance().Start();
	
	GLUtils::Clear();
	return 0;
}