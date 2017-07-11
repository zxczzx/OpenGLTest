#include "Light.h"



Light::Light()
{
}


Light::~Light()
{
}

void Light::update()
{
}

void Light::render()
{
}

void Light::processUniforms(Shader& shader, int counter)
{
}

glm::vec3 Light::getAmbient()
{
    return ambient;
}

glm::vec3 Light::getDiffuse()
{
    return diffuse;
}

glm::vec3 Light::getSpecular()
{
    return specular;
}
