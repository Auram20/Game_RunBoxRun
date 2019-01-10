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


    /*!< classe "Model",elle concerne les modèle obj présents dans le jeu*/

    class Model : public Asset {
        private:
            std::vector<Mesh> _meshes;
            std::vector<Material> _materials;
            void loadModel(std::string path);
            void processNode(aiNode *node, const aiScene *scene);
            Mesh processMesh(aiMesh *mesh, const aiScene *scene);
            std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type);
            
        public:

            /*!< activate, bind texture and send data to the render */
            void draw() const;

            /*!< display info of all meshes */
            inline void displayInfos() const {
                std::cout << "meshes : " << _meshes.size() << std::endl;
                for(unsigned int i = 0; i < _meshes.size(); ++i) {
                    _meshes[i].displayInfos();
                }
            }

            /*!< load with assimp */
            bool load() override;

            /*!< default constructor */
            Model()
            : Asset(), _meshes(), _materials({Material()})
            {} 

            /*!< constructor width string */
            Model(std::string path)
            : Asset(path, AssetType::MODEL), _meshes(), _materials({Material()})
            {
                load();
            }

            /*!< constructor from a filePath*/
            Model(const glimac::FilePath &path)
            : Asset(path, AssetType::MODEL), _meshes(), _materials({Material()})
            {
                load();
            }

            /*!< constructor with mesh in argument */
            Model(Mesh mesh)
            : Asset(), _meshes(), _materials({Material()})
            {
                _meshes.push_back(mesh);
            }

            /*!< constructor with vector of meshes */
            Model(std::vector<Mesh> meshes)
            : Asset(), _meshes(meshes), _materials({Material()})
            {

            }
    };

}

#endif