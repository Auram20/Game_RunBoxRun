#include <glimac/Model.hpp>

using namespace glimac;

void Model::draw() const{


    for(unsigned int i = 0;i < _meshes.size();i++)
    {
        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;


        const Material &mat = _materials[_meshes[i].materialID()];

        if(mat.textureNb() > 0) {
            uint i = 0;
            for(std::map<aiTextureType, Texture>::const_iterator it = mat.textureBegin(); it != mat.textureEnd();it++){
                glActiveTexture(GL_TEXTURE0+i);

                std::string number;
                std::string name = Material::getTypeName(it->first);

                if(name == "texture_diffuse")
                    number = std::to_string(diffuseNr++);
                else if(name == "texture_specular")
                    number = std::to_string(specularNr++);

                glBindTexture(GL_TEXTURE_2D, (it->second).id());
                ++i;
            }
            glActiveTexture(GL_TEXTURE0);

            Render *render = Render::getInstance();
            render->sendDatasTex(mat.textureBegin(), mat.textureEnd());

        }


        _meshes[i].draw();

    }
}

/*std::vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type)
{
    std::vector<Texture> textures;
    for(unsigned int i = 0;i < mat->GetTextureCount(type);i++)
    {
        aiString str; 
        mat->GetTexture(type, i, &str);
        Texture tex(_path.dirPath() +  str.C_Str(), type);
        textures.push_back(tex);
    }
    return textures;
}*/

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    std::vector<Texture> textures;
    uint materialID = 0;

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
        materialID = _materials.size();
        Material newMaterial;
        aiMaterial *mat = scene->mMaterials[mesh->mMaterialIndex];

        aiString str; 
        mat->GetTexture(aiTextureType_DIFFUSE, 0, &str);
        std::cout << _path.dirPath() + str.C_Str() << std::endl;
        newMaterial.addTexture(aiTextureType_DIFFUSE, _path.dirPath() + str.C_Str());

        mat->GetTexture(aiTextureType_SPECULAR, 0, &str);
        newMaterial.addTexture(aiTextureType_SPECULAR, _path.dirPath() + str.C_Str());

        _materials.push_back(newMaterial);

    }

    return Mesh(vertices, indices, materialID);
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

bool Model::load(){
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(_path,aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP::"<< import.GetErrorString()<<std::endl;
        return false;
    }

    processNode(scene->mRootNode, scene);

    return true;
}