#include "Triangle.h"
#include <iostream>
#include <SOIL.h>


Triangle::Triangle() :
	uniColor(0),
	t_start(std::chrono::high_resolution_clock::now())
{

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // Top Left 
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	// Load and create a texture 
	// Texture 1
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load image, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("screenshot000.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

	// Texture 2
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	image = SOIL_load_image("3qtr_render.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
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

	// Activate container
	shader->Use();

	// Bind Textures using texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(shader->program, "ourTexture"), 0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(shader->program, "ourTexture2"), 1);

	// Draw the container
	glUniform1f(glGetUniformLocation(shader->program, "offset"), 0.0f);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	//glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	//shader->Use();
	//glUniform1f(glGetUniformLocation(shader->program, "offset"), -0.5f);
	//glBindVertexArray(vao);
	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
}
