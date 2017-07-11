#include "PointLight.h"
#include <string>


PointLight::PointLight(glm::vec3 pos)
{
    position = pos;

    ambient = glm::vec3(0.05f, 0.05f, 0.05f);
    diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
    specular = glm::vec3(1.0f, 1.0f, 1.0f);

    constant = 1.0f;
    linear = 0.09f;
    quadratic = 0.032f;
}

PointLight::~PointLight()
{
}

void PointLight::update()
{
}

void PointLight::render()
{
}

void PointLight::processUniforms(Shader& shader, int counter)
{
    std::string structName = "pointLights[" + std::to_string(counter )+ "].";
    glUniform3f(glGetUniformLocation(shader.program, (structName+"position").c_str()), position.x, position.y, position.z);
    glUniform3f(glGetUniformLocation(shader.program, (structName+"ambient").c_str()), 0.05f, 0.05f, 0.05f);
    glUniform3f(glGetUniformLocation(shader.program, (structName+"diffuse").c_str()), 0.8f, 0.8f, 0.8f);
    glUniform3f(glGetUniformLocation(shader.program, (structName+"specular").c_str()), 1.0f, 1.0f, 1.0f);
    glUniform1f(glGetUniformLocation(shader.program, (structName+"constant").c_str()), 1.0f);
    glUniform1f(glGetUniformLocation(shader.program, (structName+"linear").c_str()), 0.09);
    glUniform1f(glGetUniformLocation(shader.program, (structName+"quadratic").c_str()), 0.032);
}

GLfloat PointLight::getConstant()
{
    return constant;
}

GLfloat PointLight::getLinear()
{
    return linear;
}

GLfloat PointLight::getQuadratic()
{
    return quadratic;
}
