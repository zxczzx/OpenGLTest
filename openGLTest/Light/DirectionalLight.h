#pragma once
#include "Light.h"

class DirectionalLight : public Light
{
public:
    DirectionalLight();
    ~DirectionalLight();

    void update() override;
    void render() override;

    void processUniforms(Shader& shader, int counter) override;

    glm::vec3 direction;
};

