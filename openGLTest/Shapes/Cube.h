#pragma once
#include "Shapes.h"
#include "../Shader.h"
#include <SOIL.h>

class Cube : public Shapes
{
public:
    Cube();
    virtual ~Cube();

    virtual void update() override;
    virtual void render(glm::vec3 position) override;

    virtual void setup();

    Shader *getShader();

protected:
    GLint uniColor;
    GLuint texture;
    GLuint texture2;
    Shader *shader;
};

