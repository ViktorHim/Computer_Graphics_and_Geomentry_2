#include "GLUtils.h"
#include "GLModel.h"
#include "GLSecondLab.h"

// GL_POINTS - точки
// GL_LINES - одиночные линии
// GL_LINE_STRIP - ломанна€ лини€
// GL_LINE_LOOP - замкнута€ ломанна€
// GL_TRIANGLES - одиночные треугольники
// GL_TRIANGLE_STRIP - лента треугольников
// GL_TRIANGLE_FAN - веер треугольников

//GL_FILL Ц вывод граней с заливкой
//GL_LINE Ц каркасный вывод (только контуры)
//GL_POINT Ц вывод€тс€ только вершины

//ѕервый параметр определ€ет дл€ каких граней установлен режим :
//GL_FRONT Ц лицевые;
//GL_BACK Ц обратные;
//GL_FRONT_AND_BACK Ц лицевые и обратные.
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