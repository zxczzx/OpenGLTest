#include "DirectionalLight.h"



DirectionalLight::DirectionalLight()
{
    direction = glm::vec3(-0.2f, -1.0f, -0.3f);

    ambient = glm::vec3(0.05f, 0.05f, 0.05f);
    diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    specular = glm::vec3(0.5f, 0.5f, 0.5f);
}


DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::update()
{
}

void DirectionalLight::render()
{
}

void DirectionalLight::processUniforms(Shader& shader, int counter)
{
    std::string structName = "dirLight.";
    glUniform3f(glGetUniformLocation(shader.program, (structName + "direction").c_str()), -0.2f, -1.0f, -0.3f);
    glUniform3f(glGetUniformLocation(shader.program, (structName + "ambient").c_str()), 0.05f, 0.05f, 0.05f);
    glUniform3f(glGetUniformLocation(shader.program, (structName + "diffuse").c_str()), 0.4f, 0.4f, 0.4f);
    glUniform3f(glGetUniformLocation(shader.program, (structName + "specular").c_str()), 0.5f, 0.5f, 0.5f);
}
