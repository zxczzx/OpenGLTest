#pragma once
#include "Cube.h"

class CubeLight : public Cube
{
public:
    CubeLight();
    ~CubeLight();

    void render(glm::vec3 position) override;
    void setup() override;
};

