// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MESH.CPP ___________ 
//================================



#include <glimac/Mesh.hpp>
#include <iostream>

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
