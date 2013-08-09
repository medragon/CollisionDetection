#pragma once

#include <string>
#include "../libraries/GLM/glm.hpp"
#include "../libraries/GLM/gtc/quaternion.hpp"

class Object
{
		private:
		std::string _name;
		int _id;

		glm::vec3 _position;
		glm::quat _direction;

	public:
		Object();
		~Object();

		void translate(glm::vec3 position);
};

