#pragma once
#include "GLController.h"

class GLSecondLab :
    public GLController
{
private:
    GLSecondLab() {};
    ~GLSecondLab() {};

    void FirstTask();
    void SecondTask();
    void ThirdTask();
    void FourTask();
    void FiveTask();
    void SixTask();
    void SevenTask();
    void EightTask();

    void ConfigureScene(int scene) override;

public:
    void Init(GLFWwindow* window) override;
    static GLSecondLab& GetInstance()
    {
        static GLSecondLab instance;
        return instance;
    }
};