#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shapes
{
public:
    Shapes();
    virtual ~Shapes();

    virtual void render(glm::vec3 position);

//protected:
    GLuint vao;
    GLuint vbo;
};

