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
{}

Mesh::Mesh(GLuint VertexCount): _VertexList(), _VertexCount(VertexCount), _vao(0), _vbo(0), _ibo(0), _nTriangles(0)
{

}/*!< object's constructor with arguments*/

Mesh::~Mesh() {
	 glDeleteBuffers(1,&_vbo);
    glDeleteVertexArrays(1,&_vao);
}

void Mesh::displayInfos()
{

	std::cout << "--------------------  INFOS MESH -------------------- " << std::endl;
	for (size_t i=0;i<_VertexCount;i++)
	{
		std::cout << _VertexList[i].position << std :: endl;

		std::cout << _VertexList[i].normal << std :: endl;

		std::cout << _VertexList[i].texCoords << std :: endl;
	}


}

void Mesh::initVAO()
{ 
     const GLuint VERTEX_ATTR_POSITION = 0;
     const GLuint VERTEX_ATTR_NORMAL = 1;
     const GLuint VERTEX_ATTR_TEXCOORDS = 2 ;
	if(_vbo == 0)
		return; 

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	if(_ibo != 0) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	}

	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
	glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

	//Bind mesh VBO
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	//Specify vertice properties positions
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid *)(offsetof(ShapeVertex, position)));
	glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid *)(offsetof(ShapeVertex, normal)));
	glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid *)(offsetof(ShapeVertex, texCoords)));

	//Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}



void Mesh::initVBO()
{


	//Generate & bind VBO
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	//Fill VBO with data
	glBufferData(
				 GL_ARRAY_BUFFER,
				 getVertexCount()*sizeof(ShapeVertex),
				 _VertexList.data(),
				 GL_STATIC_DRAW
				 );

	//Unbind VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}




void Mesh::render() const
{
	glBindVertexArray(_vao);
	if(_ibo != 0) {
		glDrawElements(GL_TRIANGLES, _nTriangles * 3, GL_UNSIGNED_INT, 0);
	} else {
		glDrawArrays(GL_TRIANGLES, 0, getVertexCount());
	}
	glBindVertexArray(0);
}