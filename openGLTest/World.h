#pragma once
#include "Shader.h"
#include "Game.h"
#include "Camera.h"
#include <chrono>
#include <vector>
#include "Cube.h"

class World 
{
public:
	World();
	~World();

	void handleInput();
	void update();
	void render();

private:
	Shader *shader;
	std::vector<glm::vec3> cubePositions;
	std::chrono::time_point<std::chrono::steady_clock> t_start;

	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	Camera camera;
	Cube cube;

	GLfloat yaw;
	GLfloat pitch;
	GLfloat lastX;
	GLfloat lastY;
	GLfloat fov;

	GLfloat deltaTime;
	GLfloat lastFrame;

	bool firstMouse;
};

