#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Sphere.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glimac/Image.hpp>
#include <random>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glimac/Model.hpp>

using namespace glimac;

void Model::draw() const{
    for(unsigned int i = 0;i < _meshes.size();i++)
    {
        _meshes[i].draw();
    }
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type)
{
    std::vector<Texture> textures;
    for(unsigned int i = 0;i < mat->GetTextureCount(type);i++)
    {
        aiString str; 
        mat->GetTexture(type, i, &str);
        Texture tex(_path + "/" + str.C_Str(), type);
        textures.push_back(tex);
    }
    return textures;
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    std::vector<Texture> textures;

    for(unsigned int i = 0;i < mesh->mNumVertices;i++)
    {
        Vertex vert;
        vert.position = glm::vec3(mesh->mVertices[i].x,mesh->mVertices[i].y,mesh->mVertices[i].z);
        vert.normal = glm::vec3(mesh->mNormals[i].x,mesh->mNormals[i].y,mesh->mNormals[i].z);

        if(mesh->mTextureCoords[0])
            vert.texCoords = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
        else
            vert.texCoords = glm::vec2(0.0f,0.0f);
        vertices.push_back(vert);
    }

    for(unsigned int i = 0;i < mesh->mNumFaces;i++)
    {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0;j < face.mNumIndices;j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    if(mesh->mMaterialIndex >= 0)
    {
        aiMaterial *mat = scene->mMaterials[mesh->mMaterialIndex];
        std::vector<Texture> diffuseMaps = loadMaterialTextures(mat, aiTextureType_DIFFUSE);
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        std::vector<Texture> specularMaps = loadMaterialTextures(mat, aiTextureType_SPECULAR);
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

    }

    return Mesh(vertices, indices, textures);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    for(unsigned int i = 0;i < node->mNumMeshes;i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        _meshes.push_back(processMesh(mesh, scene));
    }

    for(unsigned int i = 0;i < node->mNumChildren;i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

void Model::loadModel(std::string path){
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path,aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP::"<< import.GetErrorString()<<std::endl;
        return;
    }
    _path = FilePath(path.c_str());

    processNode(scene->mRootNode, scene);
}