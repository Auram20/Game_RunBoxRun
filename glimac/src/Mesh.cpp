// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MESH.CPP ___________ 
//================================



#include <glimac/Mesh.hpp>
#include <iostream>
#include <GL/glew.h>

using namespace glimac; 

Mesh::Mesh()
: _VertexList(),
_index(),
_materialID(0),
_vao(nullptr, Mesh::deleteVertexArrays),
_vbo(nullptr, Mesh::deleteBuffers),
_ebo(nullptr, Mesh::deleteBuffers)
{

}

Mesh::Mesh(const std::vector<Vertex> &vert, const std::vector<uint32_t> &ind, const uint &mat)
: _VertexList(vert),
	_index(ind),
	_materialID(mat),
	_vao(new GLuint(0), Mesh::deleteVertexArrays),
	_vbo(new GLuint(0), Mesh::deleteBuffers),
	_ebo(new GLuint(0), Mesh::deleteBuffers)
{
    setupMesh();
}

Mesh::Mesh(const Mesh &mesh)
: _VertexList(mesh._VertexList), _index(mesh._index), _materialID(mesh._materialID), _vao(mesh._vao), _vbo(mesh._vbo), _ebo(mesh._ebo)
{
	setupMesh();
}


void Mesh::displayInfos() const
{

	std::cout << "--------------------  INFOS MESH -------------------- " << std::endl;
	/*for (unsigned int i=0;i<getVertexCount();i++)
	{
		std::cout << _VertexList[i].position << std :: endl;

		std::cout << _VertexList[i].normal << std :: endl;

		std::cout << _VertexList[i].texCoords << std :: endl;
	}*/

	std::cout << "vbo : " << *_vbo << std::endl;
	std::cout << "vao : " << *_vao << std::endl;
	std::cout << "ebo : " << *_ebo << std::endl;
	std::cout << "index : " << _index.size() << std::endl;
	std::cout << "textures : " << _materialID << std::endl;
	std::cout << "vertex : " << _VertexList.size() << std::endl;
}

void Mesh::setupMesh() {
	initVBO();
	if(_index.size() > 0) {
		initEBO();
	}
	initVAO();
}

void Mesh::initVAO()
{ 
	if(_vbo == nullptr)
		return; 

	_vao = std::make_shared<GLuint>(0);


	glGenVertexArrays(1, _vao.get());
	glBindVertexArray(*_vao);

	if(_ebo != nullptr) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *_ebo);
	}

	glEnableVertexAttribArray(Mesh::VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(Mesh::VERTEX_ATTR_NORMAL);
	glEnableVertexAttribArray(Mesh::VERTEX_ATTR_TEXCOORDS);

	//Bind mesh VBO
	glBindBuffer(GL_ARRAY_BUFFER, *_vbo);

	//Specify vertice properties positions
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(offsetof(Vertex, position)));
	glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(offsetof(Vertex, texCoords)));

	//Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Mesh::initEBO() {

	_ebo = std::make_shared<GLuint>(0);

    //Création du IBO
    glGenBuffers(1, _ebo.get());

    //Bin sur GL_ELEMENT_ARRAY_BUFFER, cible réservée pour les IBOs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *_ebo);

    //On remplit l'IBO avec les indices
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        _index.size()*sizeof(uint32_t),
        _index.data(),
        GL_STATIC_DRAW
    );

    //Debind de l'IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Mesh::initVBO()
{

	_vbo = std::make_shared<GLuint>(0);

	//Generate & bind VBO
	glGenBuffers(1, _vbo.get());
	glBindBuffer(GL_ARRAY_BUFFER, *_vbo);

	//Fill VBO with data
	glBufferData(
				 GL_ARRAY_BUFFER,
				 getVertexCount()*sizeof(Vertex),
				 getDataPointer(),
				 GL_STATIC_DRAW
	);

	//Unbind VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}




void Mesh::draw() const
{
	//std::map Model ? Material


	glBindVertexArray(*_vao);
	if(_index.size() > 0 && _ebo != nullptr) {
		glDrawElements(GL_TRIANGLES, _index.size(), GL_UNSIGNED_INT, 0);
	} else {
		glDrawArrays(GL_TRIANGLES, 0, getVertexCount());
	}
	glBindVertexArray(0);
}