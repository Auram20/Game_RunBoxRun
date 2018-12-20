#pragma once

#include <GL/glew.h>
#include <glimac/glm.hpp>

namespace glimac {

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
    glm::vec2 texCoords;
};

}
