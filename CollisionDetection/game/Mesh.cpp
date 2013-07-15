#include "Mesh.h"

#include "../resourcemanagement/ObjLoader.h"
#include "../application/vboindexer.hpp"


Mesh::Mesh(const int handle, const std::string& name, const std::string& path) : Resource(handle, name, path)
{
	ObjLoader::load(getFileName(),vertices, uvs, normals);
	
}


Mesh::~Mesh(void)
{
}