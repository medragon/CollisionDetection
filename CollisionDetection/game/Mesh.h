#pragma once

#include <vector>
#include <string>

#include "..\resourcemanagement\Resource.h"
#include "..\libraries\GLEW\include\GL\glew.h"
#include "..\libraries\GLM\glm.hpp"

class Mesh : public Resource
{
	private:
		GLuint indicesBuffer;
		GLuint verticesBuffer;
		GLuint normalsBuffer;
		GLuint uvsBuffer;
		std::vector<unsigned int> indices;
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;

	public:
		Mesh(const int handle, const std::string& name, const std::string& path);
		~Mesh(void);
};

