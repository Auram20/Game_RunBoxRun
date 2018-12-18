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

Mesh::Mesh(GLuint VertexCount): _VertexCount(VertexCount)
{}/*!< object's constructor with arguments*/



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

	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
	glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

	//Bind mesh VBO
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	//Specify vertice properties positions
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), 0);
	glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid *)offsetof(ShapeVertex, normal));
	glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid *)offsetof(ShapeVertex, texCoords));

	//Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}



void Mesh::initVBO()
{
	//Get Manager for VBO
	
	//Generate & bind VBO
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	

	GLsizeiptr size = _VertexList.size() * sizeof(ShapeVertex);

	//Fill VBO with data
	glBufferData(
				 GL_ARRAY_BUFFER,
				 size,
				 _VertexList.data(),
				 GL_STATIC_DRAW
				 );

	//Unbind VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
