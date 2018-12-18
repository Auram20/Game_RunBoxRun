#pragma once

#include <GL/glew.h>
#include <glimac/glm.hpp>

namespace glimac {

struct ShapeVertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

}
