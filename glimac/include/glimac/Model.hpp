#ifndef _LIB_IMPORT_MODEL_IMAC_LSM
#define _LIB_IMPORT_MODEL_IMAC_LSM
#pragma once

#include <glimac/SDLWindowManager.hpp>
#include <iostream>
#include <glimac/glm.hpp>
#include <random>
#include <algorithm>
#include <queue>
#include <glimac/common.hpp>
#include <glimac/Mesh.hpp>
#include <glimac/Texture.hpp>


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace glimac {

    class Model : public Asset {
        private:
            std::vector<Mesh> _meshes;

            void loadModel(std::string path);
            void processNode(aiNode *node, const aiScene *scene);
            Mesh processMesh(aiMesh *mesh, const aiScene *scene);
            std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type);
        public:

            void draw() const;
            inline void displayInfos() const {
                std::cout << "meshes : " << _meshes.size() << std::endl;
                for(int i = 0; i < _meshes.size(); ++i) {
                    _meshes[i].displayInfos();
                }
            }

            Model(std::string path)
            : Asset(), _meshes()
            {
                loadModel(path);
            }
            Model(Mesh mesh)
            : Asset(), _meshes()
            {
                _meshes.push_back(mesh);
            }
            Model(std::vector<Mesh> meshes)
            : Asset(), _meshes(meshes)
            {

            }
    };

}

#endif