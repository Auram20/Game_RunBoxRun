// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MESH.CPP ___________ 
//================================



#include <glimac/Mesh.hpp>
#include <iostream>
#include <GL/glew.h>

using namespace glimac; 

Mesh::Mesh(GLuint VertexCount): _VertexList(), _index(), _textures(), _vao(0), _vbo(0), _ebo(0)
{

}/*!< object's constructor with arguments*/


Mesh::Mesh(std::vector<Vertex> vert, std::vector<unsigned int> ind, std::vector<Texture> tex) /*!< object's constructor with arguments*/
    : _VertexList(vert), _index(ind), _textures(tex)
{
    setupMesh();
};

Mesh::~Mesh() {
	glDeleteBuffers(1,&_vbo);
	glDeleteBuffers(1, &_ebo);
    glDeleteVertexArrays(1,&_vao);
}

void Mesh::displayInfos()
{

	std::cout << "--------------------  INFOS MESH -------------------- " << std::endl;
	for (unsigned int i=0;i<getVertexCount();i++)
	{
		std::cout << _VertexList[i].position << std :: endl;

		std::cout << _VertexList[i].normal << std :: endl;

		std::cout << _VertexList[i].texCoords << std :: endl;
	}


}

void Mesh::setupMesh() {
	initVBO();
	if(_index.size() != 0) {
		initEBO();
	}
	initVAO();
}

void Mesh::initVAO()
{ 
	if(_vbo == 0)
		return; 

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	if(_ebo != 0) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	}

	glEnableVertexAttribArray(Mesh::VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(Mesh::VERTEX_ATTR_NORMAL);
	glEnableVertexAttribArray(Mesh::VERTEX_ATTR_TEXCOORDS);
	glEnableVertexAttribArray(Mesh::VERTEX_ATTR_COLOR);

	//Bind mesh VBO
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	//Specify vertice properties positions
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(offsetof(Vertex, position)));
	glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(offsetof(Vertex, texCoords)));
	glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(offsetof(Vertex, color)));

	//Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::initEBO() {
    //Création du IBO
    glGenBuffers(1, &_ebo);

    //Bin sur GL_ELEMENT_ARRAY_BUFFER, cible réservée pour les IBOs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);

    //On remplit l'IBO avec les indices
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        _index.size()*sizeof(uint32_t),
        &_index[0],
        GL_STATIC_DRAW
    );

    //Debin de l'IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Mesh::initVBO()
{


	//Generate & bind VBO
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	//Fill VBO with data
	glBufferData(
				 GL_ARRAY_BUFFER,
				 getVertexCount()*sizeof(Vertex),
				 _VertexList.data(),
				 GL_STATIC_DRAW
				 );

	//Unbind VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}




void Mesh::draw() const
{

	unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;

	if(_textures.size() > 0) {

		for(unsigned int i = 0;i < _textures.size();i++){
			glActiveTexture(GL_TEXTURE0+i);

			std::string number;
			std::string name = _textures[i].getTypeName();

			if(name == "texture_diffuse")
				number = std::to_string(diffuseNr++);
			else if(name == "texture_specular")
				number = std::to_string(specularNr++);

			glBindTexture(GL_TEXTURE_2D, _textures[i].id());
		}
		glActiveTexture(GL_TEXTURE0);

	}

	glBindVertexArray(_vao);
	if(_ebo != 0) {
		glDrawElements(GL_TRIANGLES, _index.size(), GL_UNSIGNED_INT, 0);
	} else {
		glDrawArrays(GL_TRIANGLES, 0, getVertexCount());
	}
	glBindVertexArray(0);
}