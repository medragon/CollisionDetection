#include "Mesh.h"

#include "../resourcemanagement/ObjLoader.h"
#include "../application/vboindexer.hpp"


Mesh::Mesh(const int handle, const std::string& fileName) : Resource(handle, fileName)
{
	ObjLoader::load(getFileName(),vertices, uvs, normals);
	
}


Mesh::~Mesh(void)
{
}