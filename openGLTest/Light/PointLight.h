#pragma once
#include "../Light/Light.h"
class PointLight : public Light
{
public:
    PointLight(glm::vec3 pos);
    ~PointLight();

    void update() override;
    void render() override;

    void processUniforms(Shader& shader, int counter) override;

    GLfloat getConstant();
    GLfloat getLinear();
    GLfloat getQuadratic();

    glm::vec3 position;

private:
    GLfloat constant;
    GLfloat linear;
    GLfloat quadratic;
};

