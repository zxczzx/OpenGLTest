#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "../Light/Light.h"


class Shapes
{
public:
    Shapes();
    virtual ~Shapes();

    virtual void update();
    virtual void render(glm::vec3 position);

protected:
    std::vector<Light*> lights;
    GLuint vao;
    GLuint vbo;
};

