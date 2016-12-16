#include "Triangle.h"
#include <iostream>
#include <SOIL.h>


Triangle::Triangle() :
	uniColor(0),
	t_start(std::chrono::high_resolution_clock::now())
{

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions         // Colors
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Top 
	};

	// Build and compile our shader program
	shader = new Shader("VertexSource.glsl", "FragmentSource.glsl");

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO
}


Triangle::~Triangle()
{
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void Triangle::handleInput()
{
}

void Triangle::update()
{
}

void Triangle::render()
{
	// Render
	// Clear the colorbuffer
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the triangle
	shader->Use();
	glUniform1f(glGetUniformLocation(shader->program, "offset"), 0.0f);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//shader->Use();
	//glUniform1f(glGetUniformLocation(shader->program, "offset"), -0.5f);
	//glBindVertexArray(vao);
	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
}
