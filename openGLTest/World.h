#pragma once
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
    void render(sf::Vector2u windowSize);

private:
    std::vector<glm::vec3> cubePositions;
    std::chrono::time_point<std::chrono::steady_clock> t_start;

    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;


    glm::vec3 lightPos; //temporary value till light class

    Camera camera;
    std::vector<Cube*> cube;

    GLfloat yaw;
    GLfloat pitch;
    GLfloat lastX;
    GLfloat lastY;
    GLfloat fov;

    GLfloat deltaTime;
    GLfloat lastFrame;

    bool firstMouse;
};

