#pragma once
#include "Cube.h"
#include <chrono>

class CubePlain : public Cube
{
public:
    CubePlain();
    ~CubePlain();

    void render(glm::vec3 position) override;
    virtual void setup() override;

private:
    glm::vec3 lightPos; //temporary value till light class
    std::chrono::time_point<std::chrono::steady_clock> t_start;
};

