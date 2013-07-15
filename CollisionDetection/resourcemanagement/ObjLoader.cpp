#include "ObjLoader.h"
#include <stdio.h>


bool ObjLoader::load(const std::string fileName, std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals)
{
	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;

	FILE * f = fopen((char*)fileName.c_str(), "r");
	if ( f == NULL) {
		printf("File cannot be loaded!");
		return false;
	}

	while (1) {
		char lineHeader[128];
		int res = fscanf(f, "%s", lineHeader);
		if (res == EOF)
			break;

		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(f, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		} else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf(f, "%f%f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		} else if (strcmp(lineHeader, "vn") == 0 ) {
			glm::vec3 normal;
			fscanf(f, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		} else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(f, "%d/%d/%d %d/%d/%d %d/%d/%d\n", 
				&vertexIndex[0], &uvIndex[0], &normalIndex[0],
				&vertexIndex[1], &uvIndex[1], &normalIndex[1],
				&vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				printf("File can't be read by parser~");
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		} else {
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, f);
		}
	}

	for (unsigned int i=0; i < vertexIndices.size(); i++) {
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = normalIndices[i];
		unsigned int normalIndex = normalIndices[i];

		glm::vec3 vertex = temp_vertices[vertexIndex-1];
		glm::vec2 uv = temp_uvs[uvIndex-1];
		glm::vec3 normal = temp_normals[normalIndex-1];

		vertices.push_back(vertex);
		uvs.push_back(uv);
		normals.push_back(normal);
	}

	return true;


}
