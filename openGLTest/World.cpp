#include "World.h"
#include <SOIL.h>
#include <map>
#include "Shapes/CubeLight.h"
#include "Shapes/CubePlain.h"
#include "Shapes/CubeTextured.h"


World::World() :
    t_start(std::chrono::high_resolution_clock::now())
{
    cubePositions = 
    {
        glm::vec3(1.2f, 1.0f, 2.0f),
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    lightPos = glm::vec3(1.2f, 1.0f, 2.0f);

    cube.push_back(new CubeLight());
    for (int i = 1; i < cubePositions.size(); ++i)
    {
        cube.push_back(new CubeTextured());
    }

    for (int i = 0; i < cubePositions.size(); ++i)
    {
        cube[i]->setup();
    }

    deltaTime = 0.0f;	// Time between current frame and last frame
    lastFrame = 0.0f;  	// Time of last frame

    firstMouse = true;

    camera = Camera(glm::vec3(0.0f, 1.5f, 3.0f));
}

World::~World()
{
}

void World::handleInput()
{
    auto t_now = std::chrono::high_resolution_clock::now();
    float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();

    deltaTime = time - lastFrame;
    lastFrame = time;

    GLfloat cameraSpeed = 5.0f * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
    {
        camera.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
    {
        camera.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        camera.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        camera.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        camera.ProcessKeyboard(Camera_Movement::UP, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        camera.ProcessKeyboard(Camera_Movement::DOWN, deltaTime);
    }
    
    if (firstMouse)
    {
        lastX = sf::Mouse::getPosition().x;
        lastY = sf::Mouse::getPosition().y;
        firstMouse = false;
    }

    GLfloat xoffset = sf::Mouse::getPosition().x - lastX;
    GLfloat yoffset = lastY - sf::Mouse::getPosition().y; // Reversed since y-coordinates go from bottom to left
    lastX = sf::Mouse::getPosition().x;
    lastY = sf::Mouse::getPosition().y;

    camera.ProcessMouseMovement(xoffset, yoffset);
    //camera.ProcessMouseScroll(yoffset);
}

void World::update()
{
}

void World::render(sf::Vector2u windowSize)
{
    // Clear the colorbuffer
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Create transformations
    glm::mat4 view;
    glm::mat4 projection;

    view = camera.GetViewMatrix();

    // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    projection = glm::perspective(camera.Zoom, static_cast<float>(windowSize.x / windowSize.y), 0.1f, 100.0f);
    
    //WARNING: TOO MUCH SHADER SWITCHING
    for (int i = 0; i < cubePositions.size(); ++i)
    {
        if (dynamic_cast<CubeTextured*>(cube[i]))
        {
            dynamic_cast<CubeTextured*>(cube[i])->number = i-1;
        }
        cube[i]->getShader()->Use();
        // Get their uniform location
        GLint viewLoc = glGetUniformLocation(cube[i]->getShader()->program, "view");
        GLint projLoc = glGetUniformLocation(cube[i]->getShader()->program, "projection");
        GLint viewPosLoc = glGetUniformLocation(cube[i]->getShader()->program, "viewPos");
        GLint lightDirPos = glGetUniformLocation(cube[i]->getShader()->program, "light.position");
        glUniform3f(lightDirPos, -0.2f, -1.0f, -0.3f);
        glUniform3f(viewPosLoc, camera.Position.x, camera.Position.y, camera.Position.z);
        //glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);

        // Pass them to the shaders
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        cube[i]->render(cubePositions[i]);
    }
}
