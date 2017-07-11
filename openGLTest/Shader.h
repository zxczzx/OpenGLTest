#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader
{
public:
    // Constructor reads and builds the shader
    Shader();
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    ~Shader();

    // Use the program
    void Use();

    // The program ID
    GLuint program;
};

#endif