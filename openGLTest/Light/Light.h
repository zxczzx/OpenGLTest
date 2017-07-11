#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Shader.h"

class Light
{
public:
    Light();
    ~Light();

    virtual void update();
    virtual void render();

    virtual void processUniforms(Shader& shader, int counter);

    glm::vec3 getAmbient();
    glm::vec3 getDiffuse();
    glm::vec3 getSpecular();

protected:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};

