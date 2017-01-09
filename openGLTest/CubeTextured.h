#pragma once
#include "Cube.h"
#include <chrono>

class CubeTextured : public Cube
{
public:
    CubeTextured();
    ~CubeTextured();

    void render(glm::vec3 position) override;
    void setup() override;

    int number;

private:
    GLuint texture;
    GLuint specularMap;
};

