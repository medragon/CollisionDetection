#pragma once

#include <string>
#include <vector>
#include "../libraries/GLM/glm.hpp"

class ObjLoader
{
	private:
		ObjLoader(){};
	public:
		static bool load(const std::string fileName, std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);
};

