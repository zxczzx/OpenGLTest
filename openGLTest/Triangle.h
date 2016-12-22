#pragma once
#include "Shapes.h"
#include "Shader.h"
#include "Game.h"
#include "Camera.h"
#include <chrono>
#include <vector>

class Triangle : public Shapes
{
public:
	Triangle(Game *game, Shader *sh);
	~Triangle() override;

	void handleInput() override;
	void update() override;
	void render() override;

private:
	GLint uniColor;
	GLuint texture;
	GLuint texture2;
	Game *_game;
	Shader *shader;
	std::vector<glm::vec3> cubePositions;
	std::chrono::time_point<std::chrono::steady_clock> t_start;

	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	Camera camera;

	GLfloat yaw;
	GLfloat pitch;
	GLfloat lastX;
	GLfloat lastY;
	GLfloat fov;

	GLfloat deltaTime;
	GLfloat lastFrame;

	bool firstMouse;
};

