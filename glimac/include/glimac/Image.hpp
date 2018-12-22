// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ IMAGE.HPP ___________ 
//================================

#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include <utils/glm.hpp>
#include <utils/FilePath.hpp>

namespace glimac {

    /// \class Image
    /// \brief virtual class for Image.
class Image {
private:
    unsigned int m_nWidth = 0u;
    unsigned int m_nHeight = 0u;
    std::unique_ptr<glm::vec4[]> m_Pixels;
public:

        // CONSTRUCTORS & DESTRUCTOR
    Image(unsigned int width, unsigned int height):
        m_nWidth(width), m_nHeight(height), m_Pixels(new glm::vec4[width * height]) {
    }/*!< init constructor*/

    unsigned int getWidth() const {
        return m_nWidth;
    }/*!< get width*/

    unsigned int getHeight() const {
        return m_nHeight;
    }/*!< get height*/

    const glm::vec4* getPixels() const {
        return m_Pixels.get();
    }/*!< getpixels*/

    glm::vec4* getPixels() {
        return m_Pixels.get();
    }
};

std::unique_ptr<Image> loadImage(const FilePath& filepath);

class ImageManager {
private:
    static std::unordered_map<FilePath, std::unique_ptr<Image>> m_ImageMap;
public:
    static const Image* loadImage(const FilePath& filepath);
};

}
