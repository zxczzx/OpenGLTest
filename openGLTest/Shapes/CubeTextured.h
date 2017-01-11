#pragma once
#include "Cube.h"
#include <chrono>
#include <vector>

class CubeTextured : public Cube
{
public:
    CubeTextured();
    ~CubeTextured();

    void update() override;
    void render(glm::vec3 position) override;
    void setup() override;

    int number;

private:
    GLuint texture;
    GLuint specularMap;
    std::vector<glm::vec3> pointLightPositions;
};

