#pragma once

#include <GL/glew.h>
#include <utils/glm.hpp>

namespace glimac {

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

}
