#ifndef _LIB_IMPORT_MODEL_IMAC_LSM
#define _LIB_IMPORT_MODEL_IMAC_LSM
#pragma once

#include <glimac/SDLWindowManager.hpp>
#include <iostream>
#include <GL/glew.h>
#include <random>
#include <algorithm>
#include <queue>
#include <glimac/common.hpp>
#include <glimac/Mesh.hpp>
#include <glimac/Texture.hpp>
#include <utils/FilePath.hpp>
#include <utils/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glimac/Image.hpp>
#include <glimac/Material.hpp>

namespace glimac {

    class Model : public Asset {
        private:
            std::vector<Mesh> _meshes;
            std::vector<Material> _materials;
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

            bool load() override;

            Model() = default;

            Model(std::string path)
            : Asset(path, AssetType::MODEL), _meshes()
            {
                load();
            }

            Model(const glimac::FilePath &path)
            : Asset(path, AssetType::MODEL), _meshes()
            {
                load();
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