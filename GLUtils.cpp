#include "GLUtils.h"
#include "consts.h"
#include "callbacks.h"

string GLUtils::LoadShader(const char* filename)
{
    string shader;
    ifstream file(filename, ios::in);
    if (file.is_open())
    {
        std::stringstream sstr;
        sstr << file.rdbuf();
        shader = sstr.str();
        file.close();
    }
    return shader;
}

GLFWwindow* GLUtils::Init(int w, int h, bool Fullscreen, string title)
{
    //set global variables
    winWidth = w;
    winHeight = h;
    //create window pointer
    GLFWwindow* window = nullptr;
    //init GLFW
    if (!glfwInit())
    {
        cerr << "ERROR: could not start GLFW3\n";
        exit(-1);
    }

    if (Fullscreen)
    {
        GLFWmonitor* mon = glfwGetPrimaryMonitor();
        const GLFWvidmode* vmode = glfwGetVideoMode(mon);
        winWidth = vmode->width;
        winHeight = vmode->height;
        window = glfwCreateWindow(winWidth, winHeight, title.c_str(), mon, NULL);
    }
    else
    {
        window = glfwCreateWindow(winWidth, winHeight, title.c_str(), NULL, NULL);
    }
    
    glfwSetKeyCallback(window, keyCallback);
    glfwSetWindowSizeCallback(window, windowSizeCallback);
     // set context
     glfwMakeContextCurrent(window);
     // connect latest version OpenGL
     glewExperimental = GL_TRUE;

     // init GLEW
     if (glewInit() != GLEW_OK)
     {
         cerr << "ERROR: could not start GLEW\n";
         return nullptr;
     }
     
     return window;
}

void GLUtils::Clear()
{
    glfwTerminate();
}
